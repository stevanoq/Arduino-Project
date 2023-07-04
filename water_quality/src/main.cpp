#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <ota.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <WiFi.h>

#define BLYNK_TEMPLATE_ID "TMPL6_A3LwU6G"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "Tm9TGXEdeCyvwNN8LFlzliSZsRPXpYtV"
#define BLYNK_PRINT Serial
#define ONE_WIRE_BUS 5
#define buzzer_pin 23

OneWire oneWire(ONE_WIRE_BUS);	
DallasTemperature sensors(&oneWire);
ota myota;
DHT dht(13,DHT11);
LiquidCrystal_I2C lcd(0x27, 20, 4);
BlynkTimer timer;

int R1= 1000;
int Ra=25; 
int ECPin= 35;
int ECPower = 12;

const unsigned long eventInterval = 5000;
unsigned long previousTime = 0;

float ppmConversion = 0.5;
float temp_coef = 0.0019;
float k = 0.42;
float constanta;

float temp;
float Temperature = 27;
float ec=0;
float ec25 = 0;

float ppm;
float ppt;
float voltage = 0;
float vref = 3.3;
float vdrop = 0;
float rc = 0;

float airTemp;

//ph variable
#define ph_pin 34
unsigned long int avgval;
int buffer_arr[10];
int phVal;

float ph_act;
float kalibrasi = 21.27;
float nilaiPh,phSenVal;
float temp_ph;
int phVal_fix=0;

const char* ssid = "AlvinPuang";
const char* password = "test1234";

const long onDuration = 10000;
const long offDuration = 500;
long remeberTime = 0;
long buzzerState = LOW;

void readSensor();
void printSerial();
void getPH();
void monitorLCD();
void buzzer();
void reconnect();
void calibration();

void myTimerEvent(){
  Blynk.virtualWrite(V0, phVal_fix);
  Blynk.virtualWrite(V1, temp);
  Blynk.virtualWrite(V2, airTemp);
  Blynk.virtualWrite(V3, ppt);
}

void setup(void)
{
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1,1);
  lcd.print("CONNECTING TO WIFI");

  Serial.begin(115200);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(ph_pin, INPUT);
  pinMode(ECPower, OUTPUT);
  digitalWrite(ECPower, HIGH);
  digitalWrite(buzzer_pin, LOW);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  timer.setInterval(1000L, myTimerEvent);
  
  delay(500);
  lcd.clear();
  lcd.setCursor(2,1);
  lcd.print("SYSTEM CONNECTED");
  
  sensors.begin();
  myota.task();
  dht.begin();

  pinMode(ECPin, INPUT);
  pinMode(ECPower, OUTPUT);
  pinMode(ph_pin, INPUT);

  R1 = (R1+Ra);
  delay(500);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("VERTIKAL CRAB HOUSE");
  lcd.setCursor(0,2);
  lcd.print(" MONITORING SYSTEM");
  delay(2000);
  lcd.clear();

}

void loop(void)
{ 
  Blynk.run();
  timer.run();
  getPH();
  readSensor();
  printSerial();
  monitorLCD();
  buzzer();
  // reconnect();
  // calibration();
  delay(1000);
}

void monitorLCD(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("pH Air     : ");
  lcd.print(phVal);
  
  lcd.setCursor(0,1);
  lcd.print("Suhu Air   : ");
  lcd.print(temp);
  lcd.print(char(223));
  lcd.print("C");

  lcd.setCursor(0,2);
  lcd.print("Suhu Ruang : ");
  lcd.print(airTemp);
  lcd.print(char(223));
  lcd.print("C");

  lcd.setCursor(0,3);
  lcd.print("Salinitas  : ");
  lcd.print(ppt,0);
  lcd.print("PPT");
}

void printSerial(){
    Serial.print("WaterTemp: ");
    Serial.print(temp);
    Serial.print((char)176);
    Serial.print("C  |  Salinitas : ");
    Serial.print(ppt, 0);
    Serial.print(" PPT  |  airTemp : ");
    Serial.print(airTemp);
    Serial.print(" C | pH: ");
    Serial.println(phVal_fix);
}

void readSensor(){
  airTemp = dht.readTemperature();
  unsigned long curentTime = millis();
  
  if (curentTime - previousTime >= eventInterval)
  {
    sensors.requestTemperatures(); 
    temp = sensors.getTempCByIndex(0);

    digitalWrite(ECPower, HIGH);
    voltage = analogRead(ECPin);
    voltage = analogRead(ECPin);
    digitalWrite(ECPower, LOW);

    vdrop = (vref*voltage)/4095;
    rc = (vdrop*R1)/(vref-vdrop);
    rc = rc - Ra;
    ec = (1/(rc*k))*1000;
    ec25 = ec/(1+temp_coef*(temp - 25.0));
    ppm = (ec25)*(ppmConversion*1000);
    ppt = pow((ec), 1.09) * 0.47;
  }
}

void getPH(){
 phSenVal = analogRead(ph_pin);
//  float voltage_ph = phSenVal * (3.3 / 4095.0);
//  delay(1000);
//  Serial.println(voltage);
 for(int i=0;i<10;i++){
    buffer_arr[i]=phSenVal;
    //delay(30);
  }
  for(int i=0;i<9;i++)
  {
    for(int j=i+1;j<10;j++){
      if(buffer_arr[i]>buffer_arr[j]){
        temp_ph = buffer_arr[i];
        buffer_arr[i] = buffer_arr[j];
        buffer_arr[j] = temp_ph;  
      }
    }
  }

  avgval = 0;
  for(int i=0;i<10;i++)
  avgval += buffer_arr[i];
  float voltage_ph = (float)avgval*3.3/4096/10;
  float realVolt = voltage_ph + 0.14;
  phVal = (-5.70)*realVolt + kalibrasi;
  // int phVal = int((realVolt - 2)/0.0714285714);
  int phVal_map = map(phVal, 0, 14, 14, 0);
  phVal_fix = phVal_map - 1;
  // lcd.setCursor(0,0);   
  // lcd.print("real     : ");
  // lcd.print(realVolt);
  // lcd.setCursor(0,1);
  // lcd.print("volt     : ");
  // lcd.print(voltage_ph);
  
  // Serial.print("real = ");
  // Serial.print(realVolt);
  // Serial.print(" | Voltage = ");
  // Serial.print(voltage_ph);
  // // Serial.print(phSenVal);
  // Serial.print(" | pH = ");
  // Serial.print(phVal,0);
  // Serial.print(" | pH_map = ");
  // Serial.println(phVal_fix);
}

void calibration()
{
//   phSenVal = analogRead(ph_pin);
// //  float voltage_ph = phSenVal * (3.3 / 4095.0);
// //  delay(1000);
// //  Serial.println(voltage);
//  for(int i=0;i<10;i++){
//     buffer_arr[i]=phSenVal;
//     //delay(30);
//   }
//   for(int i=0;i<9;i++)
//   {
//     for(int j=i+1;j<10;j++){
//       if(buffer_arr[i]>buffer_arr[j]){
//         temp_ph = buffer_arr[i];
//         buffer_arr[i] = buffer_arr[j];
//         buffer_arr[j] = temp_ph;  
//       }
//     }
//   }

//   avgval = 0;
//   for(int i=0;i<10;i++)
//   avgval += buffer_arr[i];
//   float voltage_ph = (float)avgval*3.3/4096/10;
//   float realVolt = voltage_ph + 0.14;
//   int phVal = (-5.70)*realVolt + kalibrasi;
//   // int phVal = int((realVolt - 2)/0.0714285714);
//   int phVal_map = map(phVal, 0, 14, 14, 0);
//   phVal_fix = phVal_map - 1;
  // lcd.setCursor(0,0);   
  // lcd.print("real     : ");
  // lcd.print(realVolt);
  // lcd.setCursor(0,1);
  // lcd.print("phMap     : ");
  // lcd.print(phVal_map);
  // lcd.setCursor(0,2);
  // lcd.print("pH     : ");
  // lcd.print(phVal);
  // lcd.setCursor(0,3);
  // lcd.print("pH_fix     : ");
  // lcd.print(phVal_fix); 
  int ppt_fix = 0;
  unsigned long curentTime = millis();
  if (curentTime - previousTime >= eventInterval)
  {
    sensors.requestTemperatures(); 
    temp = 25;

    digitalWrite(ECPower, HIGH);
    voltage = analogRead(ECPin);
    voltage = analogRead(ECPin);
    digitalWrite(ECPower, LOW);

    vdrop = (vref*voltage)/4095;
    
    rc = (vdrop*R1)/(vref-vdrop);
    rc = rc - Ra;
    ec = (1/(rc*k))*1000;
    ec25 = ec/(1+temp_coef*(temp - 25.0));
    ppm = (ec25)*(ppmConversion*1000);
    ppt = pow((ec), 1.09) * 0.47;
  }
  // lcd.clear();
  // lcd.setCursor(0,0);
  // lcd.print("EC ");
  // lcd.print(ec25);
  // lcd.setCursor(0,1);
  // lcd.print("ppt ");
  // lcd.print(ppt);
  //  float voltage_ph = analogRead(ECPin) * (3.3 / 4095.0);
 
  Serial.print("ec ");
  Serial.print(ec);
  Serial.print(" |ppt ");
  Serial.print(ppt,0);
  Serial.print(" |ppm ");
  Serial.println(ppm);
}

void buzzer()
{
  if (ppt < 13 || ppt >25 || phVal < 6 || phVal > 8 || temp < 27.00 || temp > 33.00)
  {
    if (buzzerState == LOW)
    {
      if ((millis() - remeberTime) >= onDuration)
      {
        buzzerState = HIGH;
      }
    }

    else
    {
      if ((millis() - remeberTime) >= offDuration)
      {
        buzzerState = LOW;
      }
    }
    digitalWrite(buzzer_pin, buzzerState);
  }
  
  else
  {
    digitalWrite(buzzer_pin, LOW);
  }
}

void reconnect()
{
  while (!WiFi.isConnected())
  {
    ESP.restart();
  }
}