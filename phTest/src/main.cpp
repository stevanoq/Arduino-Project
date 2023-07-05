<<<<<<< HEAD
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

=======
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

>>>>>>> 9f4c145668b6fb6c7976d9e7904c2a03d2dd6554
}