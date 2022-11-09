#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>

LiquidCrystal_I2C lcd(0x27, 16,2);  

#define loker_1 14
#define loker_2 27
#define loker_3 26
#define loker_4 26

#define FIREBASE_HOST "qr-loc-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "kY32xGDjFvZOBr3BKWr8jlJagZWSAbhPv9dvA6nC"

#define WIFI_SSID "PerAiran"
#define WIFI_PASSWORD "12345678"

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {17, 5, 18, 19};
byte colPins[COLS] = {2, 0, 4, 16}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

int password;
int i = 0;
int j = 0;
int k = 0;
int PASSWORD = 0;

String input_password, noLoker,loker_mode;
String NoLoker ="";
String LokerMode = "";
String input_type = "";

int a = 0;
int b = 0;

void setup() {
  Serial.begin(115200);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  
  lcd.setCursor(2,0);
  lcd.print("Connecting");
  Serial.print("Connecting to wifi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  while(WiFi.status() != WL_CONNECTED);
  {
    delay(300);
    Serial.print(".");
    
  }
  Serial.println("Connected to wifi");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  lcd.setCursor(1,0);
  lcd.print("Setup  Success");
  delay(1000);
  lcd.clear();
  
  pinMode(loker_1, OUTPUT);
  pinMode(loker_2, OUTPUT);
  pinMode(loker_3, OUTPUT);
  pinMode(loker_4, OUTPUT);

  digitalWrite(loker_1, HIGH);
  digitalWrite(loker_2, HIGH);
  digitalWrite(loker_3, HIGH);
  digitalWrite(loker_4, HIGH);
}

void loop() {
  if(LokerMode == "ambil" && a == 0){
    ambil();
  }
  if(input_type == "key" && b == 1){
    Serial.println("keypass");
    keypass();
  }
  if(a == 0 && b == 0){
    lcd_Standby();  
  }
}

void ambil(){
  Serial.println("ambil");
  char customKey = customKeypad.getKey();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pilih Tipe Input");
  lcd.setCursor(0,1);
  lcd.print("C.QR Code D.Code");
  Serial.println(customKey);
  if(customKey){
    if(customKey == 'C'){
      Firebase.setString("esp32cam/status", "ON");
      Firebase.setString("loker_mode", "");
      loker_mode = Firebase.getString("loker_mode");
      LokerMode = loker_mode;  
      a = 0; b = 0;
    }
    else if(customKey == 'D'){
      Firebase.setString("esp32cam/status", "OFF");
      Firebase.setString("loker_mode", "");
      loker_mode = Firebase.getString("loker_mode");
      LokerMode = loker_mode;  
      a = 0; b = 1;
      input_type = "key";
    }
  }
  delay(100);
}

void keypass(){
  char customKey = customKeypad.getKey();
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Masukan Code");
  lcd.setCursor(0,1);
  lcd.print(input_password);
  
  if(k=0){
    Serial.println("get Data");
    password = Firebase.getInt(noLoker + "/qrcode");
    noLoker = Firebase.getString("noLoker");
    PASSWORD = password;  
    NoLoker = noLoker; 
    k+=1;
  }
  
  if(customKey){
    Serial.print(customKey);
    if(customKey == '*'){
      lcd.clear();
      input_password = "";
    }
    else if(customKey == '#'){
        if(input_password.toInt() == PASSWORD){
          Firebase.setString(NoLoker +"/status", "buka");
          Firebase.setInt(NoLoker + "/qrcode", 0);
          Firebase.setString("input_type", "null");
          Serial.println("firebase ok");
          input_type = "";
          LokerMode = "";
          k=0;
          i = 0;
          j = 0;
          b = 0;
          a = 0;
          lcd_benar();   
        }
        else{
          lcd_salah();
        }
        input_password = "";
    }
    else{
      input_password += customKey;
    }
  }
  delay(100);
}

void lcd_Standby(){
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Pilih Menu");
  lcd.setCursor(0,1);
  lcd.print("A.Ambil  B.Titip");
  char customKey = customKeypad.getKey();
  
  if(customKey){
    Serial.println(customKey);
    if(customKey == 'A'){
      
      Firebase.setString("loker_mode", "ambil");
      loker_mode = Firebase.getString("loker_mode");
    LokerMode = loker_mode;  
      a=0; b=1; 
    }
    else if(customKey == 'C'){
    
      Firebase.setString("loker_mode", "titip");
        loker_mode = Firebase.getString("loker_mode");
    LokerMode = loker_mode;  
      a=0; b=1; 
    }
    else{}
  }
  delay(500);
}

void lcd_benar(){
   lcd.clear();
   lcd.setCursor(1,0);
   lcd.print("Password Benar");
   delay(1000);
   lcd.clear();
}

void lcd_salah(){
   lcd.clear();
   lcd.setCursor(1,0);
   lcd.print("Password Salah");
   delay(1000);
   lcd.clear();
}


void titip(){
  
}
