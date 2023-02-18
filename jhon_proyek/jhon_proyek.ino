#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(3, DHT11);
SoftwareSerial arduino(4,5);

#define flame 2
#define buzzer 13
#define mq2 A0

float temp, humi;
int flame_val, gasAnalog, gas, status;


void setup() {
  Serial.begin(9600);
  arduino.begin(115200);
  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Jhon Cenna");
  lcd.setCursor(1,1);
  lcd.print("Loading");
  
  for(int i = 8; i < 15; i++){
    lcd.setCursor(i,1);
    lcd.print(".");
    delay(500);
  }
  lcd.setBacklight(0x01);
  pinMode(flame, INPUT);
  pinMode(mq2, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

}

void loop() {
  flame_val = digitalRead(flame);
  gasAnalog = analogRead(mq2);
  gas = map(gasAnalog, 0, 1023, 0, 100);

  if(flame_val == 0){
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Api Terdeteksi");
    digitalWrite(buzzer, HIGH);
    status = 1;
    sendData();
  }

  else if(gas >= 30){
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Gas Terdeteksi");
    status = 2;
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    sendData();
  }

  else{
    monitoring();
    status = 0;
    digitalWrite(buzzer, LOW);
    sendData();
  }
  

  delay(1000);

}

void monitoring(){
  temp = dht.readTemperature();
  humi = dht.readHumidity();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.setCursor(2, 0);
  lcd.print(temp);
  lcd.setCursor(7, 0);
  lcd.print("C");

  lcd.setCursor(9, 0);
  lcd.print("G:");
  lcd.setCursor(11, 0);
  lcd.print(gas);
  lcd.setCursor(14, 0);
  lcd.print("%");

  lcd.setCursor(3,1);
  lcd.print("Kel:");
  lcd.setCursor(7, 1);
  lcd.print(humi);
  lcd.setCursor(12, 1);
  lcd.print("%");

  
}

void sendData(){
  arduino.print((String)temp + 'A' + (String)humi + 'B' + (String)status + 'Q' + (String)gas + 'D' + '\n');
  // arduino.print(temp);
  // arduino.print('A');
  // arduino.print(humi);
  // arduino.print('B');
  // arduino.print(status);
  // arduino.print('Q');
  // arduino.print(gas);
  // arduino.print('D');
  // arduino.print('\n');
}
