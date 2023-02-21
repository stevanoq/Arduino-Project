#include <Arduino.h>
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

#include <NTPClient.h>
#include <WiFiUdp.h>

#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>

#include <OneWire.h>
#include <DallasTemperature.h>
#include <EEPROM.h>
#include "GravityTDS.h"
//#define ssid "BAGABAGA"
//#define pass "123456789"
#define ssid "Cinta Biak"
#define pass "Utha23042211"
// #define ssid "WCP"
// #define pass "Digital1502*"
// #define ssid "KOST BAROKAH BAWAH"
// #define pass "maret2022"

#define API_KEY "AIzaSyDM-sjh1SlESa2I9dABb0jYUadcplUhyrk"
#define FIREBASE_PROJECT_ID "aquarium-a26c9"
#define USER_EMAIL "Balvinimmanuel26@gmail.com"
#define USER_PASS "09092022"

#define DATABASE_URL "https://aquarium-a26c9-default-rtdb.firebaseio.com/"
#define EEPROM_SIZE 512
//pin define
#define servoPin 13
#define tdsPin 35
#define led 5

FirebaseData db;
FirebaseAuth auth;
FirebaseConfig config;
FirebaseJson json;

String UID, path, tdsPath, tempPath;
String hour[5], minute[5], status[5];

int count,j;
int currentHour, currentMinute, currentDay[3], currentSecond;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "asia.pool.ntp.org", 25200);

Servo myServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int tempPin = 15;
int stateMinute;
float averageVoltage = 0;
float temp = 0, tdsValue, temperature = 0;

OneWire oneWire(tempPin);
DallasTemperature sensors(&oneWire);
GravityTDS tds;

byte smile[8] = 
              {
                0b00000,
                0b00000,
                0b01010,
                0b00000,
                0b10001,
                0b01110,
                0b00000,
                0b00000
              };

void initWiFi(){
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to WiFi");
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Connecting");
  lcd.setCursor(4,1);
  lcd.print("To WiFi");
  while(WiFi.status() != WL_CONNECTED){
    digitalWrite(led,HIGH);
    delay(500);
    Serial.print('.');
    digitalWrite(led, LOW);
    delay(500);
  }

  Serial.println("Connected to" + (String)WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Smart Aquarium");
  lcd.setCursor(1,1);
  lcd.print("Balvin Imanuel");
  delay(2000);

  initWiFi();
  
  config.api_key = API_KEY;

  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASS;

  config.database_url = DATABASE_URL;

  Firebase.reconnectWiFi(true);
  db.setResponseSize(4096);

  config.token_status_callback = tokenStatusCallback;
  config.max_token_generation_retry = 5;

  Firebase.begin(&config, &auth);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Connecting");
  lcd.setCursor(2,1);
  lcd.print("To Firebase");

  Serial.println("Getting UID");
  while((auth.token.uid) == ""){    
    Serial.print('.');
    delay(1000);
  }

  UID = auth.token.uid.c_str();
  Serial.print("User UID : ");
  Serial.println(UID);

  timeClient.begin();
  delay(1000);
  timeClient.update();
  currentDay[0] = timeClient.getDay();
  currentDay[1] = timeClient.getDay();
  currentMinute = timeClient.getMinutes();
  stateMinute = currentMinute;

  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("Device");
  lcd.setCursor(3,1);
  lcd.print("is Conected");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Recieving Data");
  lcd.setCursor(0,1);
  lcd.print("From Firebase");

  pinMode(tdsPin, INPUT);
  sensors.begin();
  EEPROM.begin(EEPROM_SIZE);

  tds.setPin(tdsPin);
  tds.setAref(3.3);
  tds.setAdcRange(4096);
  tds.begin();

  myServo.attach(servoPin);
  myServo.write(0);
  getSchedule(1);
  getSchedule(2);
  getSchedule(3);
  getSchedule(4);
  lcd.clear();
  
  lcd.setCursor(5,0);
  lcd.print("System");
  lcd.setCursor(4,1);
  lcd.print("Is Ready");
  delay(1000);
  lcd.clear();
}

void loop() {
  getTime();
  readSensor();
  monitoring();
  if(currentMinute == 0){
    stateMinute = currentMinute;
  }
  if(currentMinute == stateMinute+5){
    getSchedule(1);
    getSchedule(2);
    getSchedule(3);
    getSchedule(4);
    stateMinute = currentMinute;
    Serial.println("get Data from Firebase");
  }
  verifyTime(1);
  verifyTime(2);
  verifyTime(3);
  verifyTime(4);
  setValue();
  reconnect();
  digitalWrite(led, LOW);
}

void setValue(){
  int tds ;
  float iTemp;
  tds = tdsValue,0;
  iTemp = temp,1;
  path = UID + "/value";
  tdsPath = path + "/tds";
  tempPath = path + "/temp";
  Serial.println("Setting value for Firebase " + path);

  if (Firebase.RTDB.setInt(&db,tdsPath, tds)){
    Serial.println("PASSED");
  }
  else{
    Serial.println("Filed " + db.errorReason());
  }

  if (Firebase.RTDB.setFloat(&db,tempPath, iTemp)){
    Serial.println("PASSED");
  }
  else{
    Serial.println("Filed " + db.errorReason());
  }
}

void getSchedule(int i){
  digitalWrite(led, HIGH);
  int event = 0;
  count = 0;
  String childPath, hourPath, minutePath, statusPath;

  path = UID + "/schedule";
  childPath = path + "/" + (String)i;
  hourPath = childPath + "/hour";
  minutePath = childPath + "/minute";
  statusPath = childPath + "/status";

  while (Firebase.RTDB.pathExisted(&db,path) && count == 0){
  
    if(Firebase.RTDB.pathExisted(&db, childPath)){
        // Serial.println( String(i) + "is exsist");
        for(event = 0; event < 3; event++){
          if(Firebase.RTDB.getInt(&db, hourPath) && event == 0){
            if(db.dataType() == "int"){
              hour[i] = String(db.intData());
            }
          }

          else if(Firebase.RTDB.getInt(&db, minutePath) && event == 1){
            if(db.dataType() == "int"){
              minute[i] = String(db.intData());
            }
          }

          else if(Firebase.RTDB.getString(&db, statusPath) && event == 2){
            if(db.dataType() == "string"){
              status[i] = db.stringData();
              count =1;
            }
          }
        } 
      }

    else{
      hour[i] = "";
      minute[i] = "";
      status[i] = "";
      break;
    }

    if(count != 0){
      break;
    }
  }
  while (!Firebase.RTDB.pathExisted(&db,path)){
    hour[i] = "";
    minute[i] = "";
    status[i] = "";
    break;
  }

  Serial.println("Data jam ke " + String(i) + " = " + hour[i]);
  Serial.println("Data menit ke " + String(i) + " = " + minute[i]);
  Serial.println("Data status ke " + String(i) + " = " + status[i]);
}

void getTime(){
  timeClient.update();
  currentDay[0] = timeClient.getDay();
  currentHour = timeClient.getHours();
  currentMinute = timeClient.getMinutes();
  currentSecond = timeClient.getSeconds();
  Serial.println(String(currentDay[0]) + "\t" + String(currentHour) + " : " + String(currentMinute));
}

void verifyTime(int i){
  String childPath, statusPath;

  path = UID + "/schedule";
  childPath = path + "/" + (String)i;
  statusPath = childPath + "/status";

  while(hour[i] != ""){
    if(hour[i].toInt() == currentHour && minute[i].toInt() == currentMinute && status[i] == "Belum"){
        Serial.println("feeding");
        feeding(15);
        if(Firebase.RTDB.setString(&db, statusPath, "Sudah")){
          status[i] = "Sudah";
//          break;
          lcd.clear();
        }
    }
    else{
      break;
    }
  }

  while(currentDay[0] != currentDay[1]){
    if(Firebase.RTDB.setString(&db, statusPath, "Belum") && j < 3){
          Serial.println("Day changed");
          j += 1;
          break;
    }
    
    if(j >= 3){
      Serial.println("status changed");
      currentDay[1] = currentDay[0];
      j = 0;
    }
  }    
}

void feeding(int iteration){
  lcd.clear();
  lcd.createChar(1, smile);
  lcd.setCursor(1,0);
  lcd.write(1);
  lcd.print("Happy Feeding");
  lcd.write(1);
  for (int i = 0; i < iteration; i++){
    myServo.write(120);
    delay(500);
    myServo.write(0);
    delay(500);
  }
  
}

void monitoring(){
  //for clock
  lcd.setCursor(4, 0);
  if(currentHour < 10)
  lcd.print("0");
  lcd.print(currentHour);
  lcd.print(":");
  if(currentMinute < 10)
  lcd.print("0");
  lcd.print(currentMinute);
  lcd.print(":");
  if(currentSecond < 10)
  lcd.print("0");
  lcd.print(currentSecond);

  lcd.setCursor(0,1);
  lcd.print("TDS:");
  lcd.print(tdsValue,0);
  lcd.print(" T:");
  lcd.print(temp,1);
  lcd.print("C");
}

void readSensor()
{
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);
  tds.setTemperature(temperature);
  tds.update();
  tdsValue = tds.getTdsValue();
}

void reconnect(){
  
  while(WiFi.status() != WL_CONNECTED){
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Reconnecting");
    ESP.restart();
  }
}
