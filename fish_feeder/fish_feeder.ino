#include <Servo.h>

Servo myservo;


void setup() 
{
  pinMode(A0,OUTPUT);
  digitalWrite(A0,LOW);
  Serial.begin(9600);
  myservo.attach(A1);
  myservo.write(45);
}

void loop()
{
  
  myservo.write(0);
  delay(500);
  myservo.write(45);
  delay(28750000);
  
}
