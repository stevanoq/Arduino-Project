#include <Adafruit_Fingerprint.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
SoftwareSerial mySerial(2, 3);
#else
#define mySerial Serial1
#endif
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

LiquidCrystal_I2C lcd(0x27, 16, 2);
int relay = 4;

const int ROW_NUM    = 4;
const int COLUMN_NUM = 4;
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte pin_rows[ROW_NUM] = {25,33,32,35};
byte pin_column[COLUMN_NUM] = {12,14,27,26}; 

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

const String password_1 = "612018016"; // change your password here
String input_password;

void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.setCursor (5, 0);
  lcd.print(F("Adityo"));
  lcd.setCursor (3, 1);
  lcd.print(F("Loading"));
  for (int i = 0; i < 3; i++) {
    lcd.print(".");
    delay(500);
  }
  lcd.clear();
 
  input_password.reserve(32); // maximum input characters is 33, change if needed
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  Serial.begin(9600);
  while (!Serial);
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");
  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Sensor Not");
    lcd.setCursor(4,1);
    lcd.print("Detected");
    while (1) { delay(1); }
  }

  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);

  finger.getTemplateCount();

  if (finger.templateCount == 0) {
    Serial.print("Sensor doesn't contain any fingerprint data. Please run the 'enroll' example.");
  }
  else {
    Serial.println("Waiting for valid finger...");
      Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  }

 
}

void loop()                 
{
    lcd.setCursor(0,0);
    lcd.print("Code / Biometric");
    lcd.setCursor(0,1);
    lcd.print(input_password);
    pass(); 
    getFingerprintID();  
    delay(50);
}

void pass()
{
  char key = keypad.getKey();

  if (key){
    Serial.println(key);

    if(key == '*') {
      lcd.clear();
      input_password = ""; // reset the input password
    } else if(key == '#') {
      if(input_password == password_1) {
        Serial.println("The password is correct, unlocking the door in 20 seconds");
        digitalWrite(relay, LOW);  // unlock the door for 20 seconds
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("Acces Done");
        delay(3000);
        lcd.clear();
        digitalWrite(relay, HIGH); // lock the door
      } else {
        Serial.println("The password is incorrect, try again");
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("Acces Denied");
        delay(1000);
        lcd.clear();
      }

      input_password = ""; // reset the input password
    } else {
      input_password += key; // append new character to input password string
    }
  }
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
    digitalWrite(relay, LOW);
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Acces Done");
    delay(3000);
    lcd.clear();
    digitalWrite(relay, HIGH);
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Com Error");
    delay(1000);
    lcd.clear();
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Acces Denied");
    delay(1000);
    lcd.clear();
    return p;
  } else {
    Serial.println("Unknown error");
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Unknown error");
    delay(1000);
    lcd.clear();
    return p;
  }
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);

  return finger.fingerID;
}

int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
}
