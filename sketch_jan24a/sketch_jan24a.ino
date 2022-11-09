#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2); 

int relay = 4;
int sensor = 5;
int tombol = 6;
int jumlah = -1;


void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(sensor, INPUT);
  pinMode(tombol, INPUT_PULLUP);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
 
  
  
}

void loop()
{
  if(digitalRead(sensor) == 0 || digitalRead(sensor) == 1 && digitalRead(relay) == HIGH && digitalRead(tombol) == 0)
  {
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("System Ready");
  }
  
  if(digitalRead(tombol) == 0 && digitalRead(sensor) == 0)
  {
    digitalWrite(relay, LOW);
    Serial.println("START");
    
    lcd.clear();
    lcd.setCursor(0,5);
    lcd.print("START");
    
  }
  
  if(digitalRead(tombol) == 0 && digitalRead(sensor) == 1 && digitalRead(relay) == HIGH)
  {
    Serial.println("belum ada Kertas");
    lcd.clear();
    lcd.setCursor(0,4);
    lcd.print("NO PAPER");
  }
  
  if(digitalRead(sensor) == 1 && digitalRead(relay) == LOW)
  {
    digitalWrite(relay, HIGH);
    jumlah = jumlah +1;
    Serial.println(jumlah);
    Serial.println("FINISH");
    
    lcd.clear();
    lcd.setCursor(0,5);
    lcd.print("FINISH");
  }
  
    lcd.setCursor(1,0);
    lcd.print("JUMLAH:");
    lcd.setCursor(1,6);
    lcd.print(jumlah);
}
