#include "ota.h"
#include "myFirebase.h"

OTA myota;
FIRE myFire;

void setup() {
  Serial.begin(115200);
  mylcd.begin();
  myota.begin();
  myFire.init();
}

void loop() {
  myota.task();
}
