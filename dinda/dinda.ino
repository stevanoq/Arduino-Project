#include <virtuabotixRTC.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

//Inisialisasi pin (CLK, DAT, RST)
virtuabotixRTC myRTC(6, 7, 8);
Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define irIn 4
#define irOut 3

int jam,menit;
int setJam = 22;
int setMenit = 59;

int jumlah_orang = 0;

void setup(){
  Serial.begin(9600);
  servo.attach(9);
  servo.write(90);
  delay(500);
  servo.write(0);

  pinMode(irIn, INPUT);
  pinMode(irOut, INPUT);
  
  lcd.begin();
  lcd.backlight();
  //seconds, minutes, hours, day of the week, day of the month, month, year
  myRTC.setDS1302Time(55,58,22,6,21,9,2022);
}

void loop(){
  rtc();
  orang();
  monitoring();
  
  if(jam == setJam && menit == setMenit){
    for(int i = 0; i!=1; i++){
      semprot();
    }

    if(jumlah_orang <= 15){
      setMenit = setMenit + 20;
    }
    else if(jumlah_orang > 15){
      setMenit = setMenit + 25;
    }
  }
  

  if(setMenit >60){
    setMenit = setMenit - 60;
    setJam += 1;
   
  }
  
  delay(1000);
}

void monitoring(){
  if(menit == 0){
    lcd.clear();
  }
  lcd.setCursor(0,1);
  lcd.print("Jumlah Orang: ");
  lcd.setCursor(13,1);
  lcd.print(jumlah_orang);
  lcd.setCursor(3,0);
  lcd.print(myRTC.hours);
  lcd.setCursor(5,0);
  lcd.print(":");
  lcd.setCursor(6,0);
  lcd.print(myRTC.minutes);
  lcd.setCursor(8,0);
  lcd.print(":");
  lcd.setCursor(9,0);
  lcd.print(myRTC.seconds);
}

void semprot(){
  servo.write(90);
  delay(1000);
  servo.write(0);
  setMenit = setMenit + 25;
}

void orang(){
  int masuk, keluar;
  masuk = digitalRead(irIn);
  keluar = digitalRead(irOut);

  if(masuk == HIGH && keluar == LOW){
    jumlah_orang += 1;
    delay(500);
  }
  else if(keluar == HIGH && masuk == LOW){
    jumlah_orang -= 1;
    delay(500);
  }
  else if(keluar == HIGH && masuk == HIGH){
    jumlah_orang = jumlah_orang;
    delay(500);
  }
  else{
    jumlah_orang = jumlah_orang;
  }
  if(jumlah_orang == 9){
    for(int i = 0; i != 0; i++){
      lcd.clear();
    }
  }
  Serial.print("jumlah orang:");
  Serial.println(jumlah_orang);
}

void rtc(){
  myRTC.updateTime();
  jam = myRTC.hours;
  menit = myRTC.minutes;
  Serial.print("Current Date / Time: ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("  ");
  Serial.print(myRTC.hours);
  Serial.print(":");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  Serial.println(myRTC.seconds);
}
