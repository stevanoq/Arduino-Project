#include <Arduino.h>
const int pin = 12;
void setup() {
  Serial.begin(115200);
  pinMode(pin,OUTPUT);

}

void loop() {
  digitalWrite(pin,HIGH);
  delay(1000);
  digitalWrite(pin,LOW);

}