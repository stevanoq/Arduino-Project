#include <Arduino.h>
#include <ota.h>
#include <myFirebase.h>

OTA myOTA;
FIREBASE myFire;

void setup() {
  Serial.begin(115200);
  mylcd.begin();
  myOTA.begin();
  myFire.begin();
}

void loop() {
  myOTA.task();
}