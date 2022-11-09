#include<Servo.h>
Servo servo;
void setup() {
  // put your setup code here, to run once:
servo.attach(A0);
}

void loop() {
  servo.write(0);
  delay(1000);
  servo.write(90);
  delay(1000);
  servo.write(180);
  delay(1000);
}
