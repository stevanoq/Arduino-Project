#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2); 

int relay = 4;
int sensor = 5;
int tombol = 6;
int led = 7;
int jumlah = 0;
int waktu = 0;
int menit = 0;

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(sensor, INPUT);
  pinMode(tombol, INPUT_PULLUP);
  pinMode(relay, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  digitalWrite(relay, LOW);
}


void loop()
{
  if(digitalRead(sensor) == 1 || digitalRead(sensor) == 0 && digitalRead(relay) == LOW)
  {
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("System Ready");
    lcd.setCursor(0,1);
    lcd.print("Jumlah:");
    lcd.setCursor(7,1);
    lcd.print(jumlah);
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
  }
  
  
  if(digitalRead(tombol) == 0 && digitalRead(sensor) == 0)
  {
    digitalWrite(relay, HIGH);
    Serial.println("START");
    waktu = 0;
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("START");
    lcd.setCursor(0,1);
    lcd.print("Time ");
    digitalWrite(led, HIGH);  
    delay(1000);
  }
    if(digitalRead(relay) == HIGH)
    {
    waktu = waktu + 1;
    lcd.setCursor(7,1);
    if(waktu == 60)
    {
      waktu = 0;
      menit = menit + 1;
      lcd.clear();
    }
    Serial.println(waktu);
    lcd.setCursor(5,0);
    lcd.print("START");
    lcd.setCursor(0,1);
    lcd.print("Time ");
    lcd.setCursor(6,1);
    lcd.print(menit);
    lcd.setCursor(7,1);
    lcd.print(":");
    lcd.setCursor(8,1);
    lcd.print(waktu);
    delay(1000);
    }

  
  if(digitalRead(tombol) == 0 && digitalRead(sensor) == 1 && digitalRead(relay) == LOW)
  {
    Serial.println("belum ada Kertas");
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("NO PAPER");
    lcd.setCursor(2,1);
    lcd.print("Insert Paper");
    
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(1000);
  }
  
  if(digitalRead(sensor) == 1 && digitalRead(relay) == HIGH)
  {
    digitalWrite(relay, LOW);
    jumlah = jumlah +1;
    Serial.println(jumlah);
    Serial.println("FINISH");
    digitalWrite(led, LOW);
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("FINISH");
    lcd.setCursor(6,1);
    lcd.print(menit);
    lcd.setCursor(7,1);
    lcd.print(":");
    lcd.setCursor(8,1);
    lcd.print(waktu);
    delay(3000);
    waktu = 0;
    menit = 0;
  }
}
