#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo servox;
Servo servoy;

#define ldr_kiri A0
#define ldr_atas A2
#define ldr_bawah A1
#define ldr_kanan A3

int kiri, kanan, atas, bawah, x, y;

const int pinADC = A6;
int sensitivitas = 185; //tegantung sensor arus yang digunakan, yang ini 5A
int nilaiadc= 00;
int teganganoffset = 2500;
double tegangan = 00;
double nilaiarus = 00;

void setup() {
  data_olah();
  Serial.begin(115600);
  
  pinMode(ldr_kiri, INPUT);
  pinMode(ldr_atas, INPUT);
  pinMode(ldr_bawah, INPUT);
  pinMode(ldr_kanan, INPUT);
  
  lcd.begin();
  lcd.backlight();
  
  servox.attach(9);
  servoy.attach(10);

  x = 90;
  y = 90;
  servox.write(x);
  servoy.write(y);
  
  lcd.setCursor (0, 0);
  lcd.print(F("Solar Tracker"));
  lcd.setCursor (3, 1);
  lcd.print(F("Loading"));
  for (int i = 0; i < 3; i++) {
    lcd.print(".");
    delay(500);
  }
  lcd.clear();
  
}

void loop(){
  kiri = analogRead(ldr_kiri);
  kanan = analogRead(ldr_kanan);
  atas = analogRead(ldr_atas);
  bawah = analogRead(ldr_bawah);

  if(kanan > kiri){
    x++;
    if(x >= 180){
      x = 180;
    }
  }

  else if(kiri > kanan){
    x--;
    if(x <= 0){
      x = 0;
    }
  }

  if(atas < bawah){
    y++;
    if(y >= 180){
      y = 180;
    }
  }

  else if(bawah < atas){
    y--;
    if(y <= 0){
      y = 0;
    }
  }
  lcd.setCursor(0,0);
  lcd.print("V = ");
  lcd.setCursor(4,0);
  lcd.print(tegangan,2);
  lcd.setCursor(9,0);
  lcd.print("V");
  
  lcd.setCursor(0,1);
  lcd.print("I = ");
  lcd.setCursor(4,1);
  lcd.print(nilaiarus,2);
  lcd.setCursor(10,1);
  lcd.print("mA");
  
  servox.write(x);
  servoy.write(y);
  delay(10);
}

void data_olah(){
  nilaiadc = analogRead(pinADC);
  tegangan = ((nilaiadc / 1024.0) * 5000)/1000;
  nilaiarus = (((teganganoffset - tegangan ) / sensitivitas));
}
