<<<<<<< HEAD
#include <Arduino.h>
#include <Stepper.h>

#define STEPS 32

#define p1 A0
#define p2 A1
#define p3 A2
#define p4 A3
#define p5 A4

int stateP1, stateP2, stateP3, stateP4, stateP5;
int val, currentVal = 0;

Stepper stepper(STEPS, 2, 4, 3, 5);

void steps(int angle);

void setup() {
  Serial.begin(9600);
    pinMode(p1, INPUT_PULLUP);
    pinMode(p2, INPUT_PULLUP);
    pinMode(p3, INPUT_PULLUP);
    pinMode(p4, INPUT_PULLUP);
    pinMode(p5, INPUT_PULLUP);
    stepper.setSpeed(200);
    steps(0);
}

void loop() {
  stateP1 = digitalRead(p1);
  stateP2 = digitalRead(p2);
  stateP3 = digitalRead(p3);
  stateP4 = digitalRead(p4);
  stateP5 = digitalRead(p5);

  if (stateP1 == LOW)
  {
    steps(30);
  }

  if (stateP2 == LOW)
  {
    steps(90);
  }
  
  if (stateP4 == LOW)
  {
    steps(-90);
  }
  
  if (stateP5 == LOW)
  {
    steps(-30);
  }

  if (stateP1 == HIGH && stateP2 == HIGH && stateP3 == HIGH && stateP4 == HIGH && stateP5 == HIGH)
  {
    steps(0);
  }
}

void steps(int angle)
{
  val = map(angle, 0, 360, 0, 500);
  
  if (angle > currentVal)
  {
    currentVal += 5;
    stepper.step(5);
  }

  if (angle < currentVal)
  {
    currentVal -= 5;
    stepper.step(-5);
    
  }  
  
  if (angle == currentVal)
  {
    currentVal = angle;
  }

  Serial.println(currentVal);
  
=======
#include <Arduino.h>
#include <Stepper.h>

#define STEPS 32

#define p1 A0
#define p2 A1
#define p3 A2
#define p4 A3
#define p5 A4

int stateP1, stateP2, stateP3, stateP4, stateP5;
int val, currentVal = 0;

Stepper stepper(STEPS, 2, 4, 3, 5);

void steps(int angle);

void setup() {
  Serial.begin(9600);
    pinMode(p1, INPUT_PULLUP);
    pinMode(p2, INPUT_PULLUP);
    pinMode(p3, INPUT_PULLUP);
    pinMode(p4, INPUT_PULLUP);
    pinMode(p5, INPUT_PULLUP);
    stepper.setSpeed(200);
    steps(0);
}

void loop() {
  stateP1 = digitalRead(p1);
  stateP2 = digitalRead(p2);
  stateP3 = digitalRead(p3);
  stateP4 = digitalRead(p4);
  stateP5 = digitalRead(p5);

  if (stateP1 == LOW)
  {
    steps(30);
  }

  if (stateP2 == LOW)
  {
    steps(90);
  }
  
  if (stateP4 == LOW)
  {
    steps(-90);
  }
  
  if (stateP5 == LOW)
  {
    steps(-30);
  }

  if (stateP1 == HIGH && stateP2 == HIGH && stateP3 == HIGH && stateP4 == HIGH && stateP5 == HIGH)
  {
    steps(0);
  }
}

void steps(int angle)
{
  val = map(angle, 0, 360, 0, 500);
  
  if (angle > currentVal)
  {
    currentVal += 5;
    stepper.step(5);
  }

  if (angle < currentVal)
  {
    currentVal -= 5;
    stepper.step(-5);
    
  }  
  
  if (angle == currentVal)
  {
    currentVal = angle;
  }

  Serial.println(currentVal);
  
>>>>>>> 9f4c145668b6fb6c7976d9e7904c2a03d2dd6554
}