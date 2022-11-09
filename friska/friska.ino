#include <Blynk.h>
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN 2
#define csms 34
#define LDR 35
#define MAX_ADC_READING 1023
#define ADC_REF_VOLTAGE 5.0
#define REF_RESISTANCE 10000
#define LUX_CALC_SCALAR 125235178.3654270
#define LUX_CALC_EXPONENT -1.604568157

#define pompa 13
#define mist_maker 14
#define led 12

#define button_pompa 27
#define button_led 26
#define button_mm 25

const int tombol_otomatis = 33;
int a = 0;

int buttonStatePompa = HIGH;
int buttonStateLED = HIGH;
int buttonStateMM = HIGH; 

char auth[] = "LltUlbnvxBA5NSYddBXXasvaF5LG-MN2";
char ssid[] = "Cinta Biak";
char pass[] = "Djorkaef";

BlynkTimer timer;
WidgetRTC rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);
  dht.begin();
  pinMode(csms, INPUT);
  pinMode(pompa, OUTPUT);
  pinMode(mist_maker, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(button_pompa, INPUT);
  pinMode(button_led,INPUT);
  pinMode(button_mm, INPUT);
   pinMode(tombol_otomatis, INPUT);
  
  digitalWrite(pompa, HIGH);
  digitalWrite(mist_maker, HIGH);
  digitalWrite(led, HIGH);
  
  lcd.begin();
  lcd.backlight();
  lcd.clear();
    Blynk.begin(auth, ssid, pass);
    setSyncInterval(10 * 60);
    timer.setInterval(500L, Data);
  }

  void Data()
  {
    float t = dht.readTemperature();
    float h = dht.readHumidity();

    int tanah = analogRead(csms);
    int moisture = map(tanah, 0, 4095, 100, 0);
    
    int ldrRawData;
    float resistorVoltage, ldrVoltage;
    float ldrResistance;
    float ldrLux;

    ldrRawData = analogRead(LDR);   //Baca sensor

    //------------Konversi  dari data analog ke nilai lux------------//
    resistorVoltage = (float)ldrRawData / MAX_ADC_READING * ADC_REF_VOLTAGE;
    ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage;
    ldrResistance = ldrVoltage / resistorVoltage * REF_RESISTANCE;
    ldrLux = LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT);

    
    String currentTime = String(hour()) + ":" + minute() + ":" + second();
    Blynk.virtualWrite(V0, currentTime);
    Blynk.virtualWrite(V1, t);
    Blynk.virtualWrite(V2, h);
    Blynk.virtualWrite(V3, moisture);
    Blynk.virtualWrite(V4, ldrLux);
    Serial.print("Intensitas Cahaya : ");
    Serial.print(ldrLux);                     //Tampilkan intensitas cahaya
    Serial.println(" Lux");

  }

  BLYNK_CONNECTED()
  {
    rtc.begin();
  }

  void monitoring()
  {
    float t = dht.readTemperature();
    float h = dht.readHumidity();

    int ldrRawData;
    float resistorVoltage, ldrVoltage;
    float ldrResistance;
    float ldrLux;
    ldrRawData = analogRead(LDR);
    resistorVoltage = (float)ldrRawData / MAX_ADC_READING * ADC_REF_VOLTAGE;
    ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage;
    ldrResistance = ldrVoltage / resistorVoltage * REF_RESISTANCE;
    ldrLux = LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT);

    int tanah = analogRead(csms);
    int moisture = map(tanah, 0, 4095, 100, 0);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.setCursor(0, 1);
    lcd.print("H:");
    lcd.setCursor(2, 0);
    lcd.print(t);
    lcd.setCursor(2, 1);
    lcd.print(h);
    lcd.setCursor(10, 0);
    lcd.print("L:");
    lcd.setCursor(10, 1);
    lcd.print("M:");
    lcd.setCursor(12, 0);
    lcd.print(ldrLux);
    lcd.setCursor(12, 1);
    lcd.print(moisture);
}

void kontrol_otomatis()
{
    float t = dht.readTemperature();
    float h = dht.readHumidity();

    int tanah = analogRead(csms);
    int moisture = map(tanah, 0, 4095, 100, 0);
    
    int ldrRawData;
    float resistorVoltage, ldrVoltage;
    float ldrResistance;
    float ldrLux;

    ldrRawData = analogRead(LDR);   //Baca sensor

    //------------Konversi  dari data analog ke nilai lux------------//
    resistorVoltage = (float)ldrRawData / MAX_ADC_READING * ADC_REF_VOLTAGE;
    ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage;
    ldrResistance = ldrVoltage / resistorVoltage * REF_RESISTANCE;
    ldrLux = LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT);

    if(t >= 30)
    {
      digitalWrite(mist_maker, LOW);  
    }
    else if(t <= 25)
    {
      digitalWrite(mist_maker, HIGH);
    }

    if(moisture <= 70)
    {
      digitalWrite(pompa, LOW);
    }
    else if(moisture >= 90)
    {
      digitalWrite(pompa, HIGH);
    }

    if(hour() == 7 && minute() == 0 )
    {
      digitalWrite(led, LOW);
    }
    else if(hour() == 23 && minute() == 59 )
    {
      digitalWrite(led, HIGH);
    }
}

void kontrol_manual()
{
  if (buttonStatePompa == LOW) 
  {
    digitalWrite(pompa, LOW);
  } else { 
    digitalWrite(pompa, HIGH);
  }
  
  if (buttonStateLED == LOW) 
  {
    digitalWrite(led, LOW);
  } else { 
    digitalWrite(led, HIGH);
  }

  
  if (buttonStateMM == LOW) 
  {
    digitalWrite(mist_maker, LOW);
  } else { 
    digitalWrite(mist_maker, HIGH);
  }
}

  void loop()
  {
    Blynk.run();
    timer.run();
    monitoring();
    kontrol_otomatis();
   // kontrol_manual();
    delay(500);
  }
