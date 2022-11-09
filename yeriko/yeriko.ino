#include <LiquidCrystal.h> 
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 

#define in1 10
#define in2 11
#define LDR A0
          
int ldrData;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);   
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  ldrData = analogRead(LDR);
  int pwm = map(ldrData, 0, 1023, 255, 0);
  analogWrite(in1, pwm);
  analogWrite(in2, pwm);
  int presentase = map(pwm, 255,0,0,100);
  int nilai_pwm = map(pwm, 255,0,0,255);
  lcd.setCursor(0,0);
  lcd.print("LDR:");
  lcd.setCursor(4,0);
  lcd.print(ldrData);
  
  lcd.setCursor(8,0);
  lcd.print("PWM:");
  lcd.setCursor(12,0);
  lcd.print(nilai_pwm);

  lcd.setCursor(0,1);
  lcd.print("PRESENTASE:");
  lcd.setCursor(12,1);
  lcd.print(presentase);

  delay(500);
}
