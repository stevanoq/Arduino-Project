#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

char auth[] = "BcXhktuBgavzgkLfqiXvOzzSrdrqyorR";
char ssid[] = "napa ?";
char pass[] = "gatauahmales";

BlynkTimer timer;
WidgetRTC rtc;

LiquidCrystal_I2C lcd(0x27, 16,2);  

DHT dht(25,DHT11);

#define csms 34
#define pump 17
#define mistmaker 5
#define led 19
#define pump_pin  14
#define mistmaker_pin 12
#define led_pin 26

void Data()
{
  String currentTime = String(hour()) + ":" + minute() + ":" + second();
  Blynk.virtualWrite(V0, currentTime);
    
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);

  int tanah = analogRead(csms);
  int moisture = map(tanah, 430, 840, 100,0);
  Blynk.virtualWrite(V3, moisture);
}

BLYNK_CONNECTED() 
{
  rtc.begin();
}

void setup()
{
  Serial.begin(115200);
  pinMode(csms,INPUT);
  pinMode(pump_pin,INPUT_PULLUP);
  pinMode(mistmaker_pin,INPUT_PULLUP);
  pinMode(led_pin,INPUT_PULLUP);
  
  pinMode(mistmaker,OUTPUT);
  pinMode(pump,OUTPUT);
  pinMode(led,OUTPUT);

  digitalWrite(mistmaker,HIGH);
  digitalWrite(pump,HIGH);
  digitalWrite(led,HIGH);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  dht.begin();
  Blynk.begin(auth, ssid, pass);
  setSyncInterval(10*60); 
  timer.setInterval(1000L, Data);
}

void tampilan()
{
  String currentTime = String(hour()) + ":" + minute() + ":" + second();
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  int tanah = analogRead(csms);
  int moisture = map(tanah, 430, 840, 100,0);
  
  lcd.setCursor(0,0);
  lcd.print("T: ");
  lcd.setCursor(2,0);
  lcd.print(t);
  lcd.setCursor(0,1);
  lcd.print("H: ");
  lcd.setCursor(2,1);
  lcd.print(h);

  lcd.setCursor(8,1);
  lcd.print(currentTime);

  lcd.setCursor(8,0);
  lcd.print("SM: ");
  lcd.setCursor(11,0);
  lcd.print(moisture);
}

void kontrol_manual()
{
    if(digitalRead(pump_pin) ==  0)
    {
       digitalWrite(pump,HIGH);
    }
    else if (digitalRead(pump_pin) ==  1)
    {
      digitalWrite(pump,LOW);
    } 
    
    if(digitalRead(mistmaker_pin) ==  0)
    {
       digitalWrite(mistmaker,HIGH);
    }
    else if (digitalRead(pump_pin) ==  1)
    {
      digitalWrite(mistmaker,LOW);
    } 
    
    if(digitalRead(led_pin) ==  0)
    {
       digitalWrite(led,HIGH);
    }
    else if (digitalRead(pump_pin) ==  1)
    {
      digitalWrite(led,LOW);
    } 
}

void kontrol_otomatis()
{
  String currentTime = String(hour()) + ":" + minute() + ":" + second();
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  int tanah = analogRead(csms);
  int moisture = map(tanah, 430, 840, 100,0);
  
  if(t >= 28)
  {
    digitalWrite(mistmaker, LOW);
  }
  else if(t <= 26 )
  {
    digitalWrite(mistmaker, HIGH);
  }

  if(moisture >= 100)
  {
    digitalWrite(pump, HIGH);
  }

  else if(moisture <=80 )
  {
    digitalWrite(pump, LOW);
  }

  if(hour() == 5 && minute() == 00)
  {
    digitalWrite(led, LOW);
  }

  else if(hour() == 22 && minute() == 00);
  {
    digitalWrite(led, HIGH);
  }
}

void loop()
{
  Blynk.run();
  timer.run();
  tampilan();
  kontrol_manual();
  kontrol_otomatis();
}
