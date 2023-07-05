<<<<<<< HEAD
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"

#define upDoorPin 2
#define downDoorPin 3
#define ledUpPin 4
#define ledDownPin 5
#define lpwm A0
#define rpwm A1
#define upSwitch 6
#define downSwitch 7
#define cameraPin A2

int downVal;
int upVal;
int oldVal = 0;
int count = 0;
int q = 0;
int t = 0;
String upString;
String downString;

SoftwareSerial myserial(11,10);//rx,tx
DFRobotDFPlayerMini player;

void(* resetFunc) (void) = 0;

void setup() {
  Serial.begin(115200);
  myserial.begin(9600);

  pinMode(upDoorPin, OUTPUT);
  pinMode(downDoorPin, OUTPUT);
  pinMode(ledUpPin, OUTPUT);
  pinMode(ledDownPin, OUTPUT);
  pinMode(lpwm, OUTPUT);
  pinMode(rpwm, OUTPUT);
  pinMode(upSwitch, INPUT_PULLUP);
  pinMode(downSwitch, INPUT_PULLUP);
  pinMode(cameraPin, OUTPUT);

  digitalWrite(upDoorPin, HIGH);
  digitalWrite(downDoorPin, HIGH);
  digitalWrite(ledUpPin, HIGH);
  digitalWrite(ledDownPin, HIGH);
  digitalWrite(cameraPin, HIGH);
  analogWrite(lpwm, 0);
  analogWrite(rpwm, 0);

  player.begin(myserial);
  player.EQ(DFPLAYER_EQ_NORMAL);
}

void loop()
{
  upVal = digitalRead(upSwitch);
  downVal = digitalRead(downSwitch);
      // analogWrite(lpwm, 0);
      // analogWrite(rpwm, 255);
  char data;
  if (Serial.available())
  {
    data = Serial.read();
    // Serial.print(data);

     if (data == 'U')
  {
    digitalWrite(upDoorPin, LOW);
  }

  else if (data == 'u')
  {
    digitalWrite(upDoorPin, HIGH);
  }
  
  else if (data == 'D')
  {
    digitalWrite(downDoorPin, LOW);
  }

  else if (data == 'd')
  {
    digitalWrite(downDoorPin, HIGH);
  }

  else if (data == 'L')
  {
    digitalWrite(ledDownPin, LOW);
  }

  else if (data == 'l')
  {
    digitalWrite(ledDownPin, HIGH);
  }
  
  else if (data == 'Q')
  {
    digitalWrite(ledUpPin, LOW);
  }
  
  else if (data == 'q')
  {
    digitalWrite(ledUpPin, HIGH);
  }

  else if (data == '@')
  {
    analogWrite(lpwm, 255);
    analogWrite(rpwm, 0);
  }

  else if (data == '^')
  {
    analogWrite(lpwm, 0);
    analogWrite(rpwm, 255);
  }

  else if (data == '*')
  {
    analogWrite(lpwm, 0);
    analogWrite(rpwm, 0);
  }

  else if (data == ']')
  {
    q = 1;
  }

  else if (data == '[')
  {
    q = 0;
  }

  else if (data == 'c')
  {
    digitalWrite(cameraPin, LOW);
  }

  else if (data == 'C')
  {
    digitalWrite(cameraPin, HIGH);
  }

  else if (data == 'Z')
  {
    //init
    player.playMp3Folder(1);
  }

  else if (data == 'z')
  {
    //success init
    player.playMp3Folder(2);
  }

  else if (data == 'F')
  {
    //open door up
    player.playMp3Folder(3);
  }

  else if (data == '`')
  {
    //open door down
    player.playMp3Folder(4);
  }
  
  else if (data == '}')
  {
    //ambil paket
    player.playMp3Folder(5);
  }

  else if (data == '{')
  {
    //taruh paket
    player.playMp3Folder(6);
  }
  
  else if (data == ',')
  {
    //terimakasih
    player.playMp3Folder(7);
  }
  
  else if (data == '.')
  {
    //empty
    player.playMp3Folder(8);
  }

  else if (data == 'R')
  {
    //arahkan kamera
    player.playMp3Folder(9);
  }
  
  else if (data == 'G')
  {
    //manual key
    player.playMp3Folder(10);
  }
  
  else if (data == '>')
  {
    //ambil paket
    player.playMp3Folder(11);
  }

  else if (data == 't')
  {
    player.playMp3Folder(12);
  }

  if (q == 1)
  {
    upVal = digitalRead(upSwitch);
    downVal = digitalRead(downSwitch);
    if (upVal == HIGH)
    {
      upString = ".";
    }

    else{
      upString = ",";
    }

    if (downVal == HIGH)
    {
      downString = "+";
    }
    
    else{
      downString = "=";
    }
    Serial.print(String(downString) + " " + String(upString) + " ");
    delay(500);
  }

  while (data == 'M'){
    upVal = digitalRead(upSwitch);
    downVal = digitalRead(downSwitch);
    if (downVal == 0 && upVal == 1 && count == 0)
    {
      analogWrite(lpwm, 0);
      analogWrite(rpwm, 255);
    }

    if (downVal == 1 && upVal == 1 && count == 0)
    {
      analogWrite(lpwm, 0);
      analogWrite(rpwm, 255);
    }
    
    if (downVal == 1 && upVal == 0 && count == 0)
    {
      if (t == 0)
      {
        analogWrite (lpwm, 0 );
        analogWrite (rpwm, 0);
        delay(2000);
        t = 1;
      }
      
      analogWrite(lpwm, 255);
      analogWrite(rpwm, 0);
      count = 1;
    }

    if (downVal == 1 && upVal == 1 && count == 1)
    {
      analogWrite(lpwm, 255);
      analogWrite(rpwm, 0);
    }

    if (downVal == 0 && upVal == 1 && count == 1)
    {
      analogWrite(lpwm, 0);
      analogWrite(rpwm, 0);

      t = 0;
      Serial.print('?');
      data = '-';
      count = 0;
      delay(1000);
      break;
    }
    
  }
  }

 
    
  data = '-';
=======
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"

#define upDoorPin 2
#define downDoorPin 3
#define ledUpPin 4
#define ledDownPin 5
#define lpwm A0
#define rpwm A1
#define upSwitch 6
#define downSwitch 7
#define cameraPin A2

int downVal;
int upVal;
int oldVal = 0;
int count = 0;
int q = 0;
int t = 0;
String upString;
String downString;

SoftwareSerial myserial(11,10);//rx,tx
DFRobotDFPlayerMini player;

void(* resetFunc) (void) = 0;

void setup() {
  Serial.begin(115200);
  myserial.begin(9600);

  pinMode(upDoorPin, OUTPUT);
  pinMode(downDoorPin, OUTPUT);
  pinMode(ledUpPin, OUTPUT);
  pinMode(ledDownPin, OUTPUT);
  pinMode(lpwm, OUTPUT);
  pinMode(rpwm, OUTPUT);
  pinMode(upSwitch, INPUT_PULLUP);
  pinMode(downSwitch, INPUT_PULLUP);
  pinMode(cameraPin, OUTPUT);

  digitalWrite(upDoorPin, HIGH);
  digitalWrite(downDoorPin, HIGH);
  digitalWrite(ledUpPin, HIGH);
  digitalWrite(ledDownPin, HIGH);
  digitalWrite(cameraPin, HIGH);
  analogWrite(lpwm, 0);
  analogWrite(rpwm, 0);

  player.begin(myserial);
  player.EQ(DFPLAYER_EQ_NORMAL);
}

void loop()
{
  upVal = digitalRead(upSwitch);
  downVal = digitalRead(downSwitch);
      // analogWrite(lpwm, 0);
      // analogWrite(rpwm, 255);
  char data;
  if (Serial.available())
  {
    data = Serial.read();
    // Serial.print(data);

     if (data == 'U')
  {
    digitalWrite(upDoorPin, LOW);
  }

  else if (data == 'u')
  {
    digitalWrite(upDoorPin, HIGH);
  }
  
  else if (data == 'D')
  {
    digitalWrite(downDoorPin, LOW);
  }

  else if (data == 'd')
  {
    digitalWrite(downDoorPin, HIGH);
  }

  else if (data == 'L')
  {
    digitalWrite(ledDownPin, LOW);
  }

  else if (data == 'l')
  {
    digitalWrite(ledDownPin, HIGH);
  }
  
  else if (data == 'Q')
  {
    digitalWrite(ledUpPin, LOW);
  }
  
  else if (data == 'q')
  {
    digitalWrite(ledUpPin, HIGH);
  }

  else if (data == '@')
  {
    analogWrite(lpwm, 255);
    analogWrite(rpwm, 0);
  }

  else if (data == '^')
  {
    analogWrite(lpwm, 0);
    analogWrite(rpwm, 255);
  }

  else if (data == '*')
  {
    analogWrite(lpwm, 0);
    analogWrite(rpwm, 0);
  }

  else if (data == ']')
  {
    q = 1;
  }

  else if (data == '[')
  {
    q = 0;
  }

  else if (data == 'c')
  {
    digitalWrite(cameraPin, LOW);
  }

  else if (data == 'C')
  {
    digitalWrite(cameraPin, HIGH);
  }

  else if (data == 'Z')
  {
    //init
    player.playMp3Folder(1);
  }

  else if (data == 'z')
  {
    //success init
    player.playMp3Folder(2);
  }

  else if (data == 'F')
  {
    //open door up
    player.playMp3Folder(3);
  }

  else if (data == '`')
  {
    //open door down
    player.playMp3Folder(4);
  }
  
  else if (data == '}')
  {
    //ambil paket
    player.playMp3Folder(5);
  }

  else if (data == '{')
  {
    //taruh paket
    player.playMp3Folder(6);
  }
  
  else if (data == ',')
  {
    //terimakasih
    player.playMp3Folder(7);
  }
  
  else if (data == '.')
  {
    //empty
    player.playMp3Folder(8);
  }

  else if (data == 'R')
  {
    //arahkan kamera
    player.playMp3Folder(9);
  }
  
  else if (data == 'G')
  {
    //manual key
    player.playMp3Folder(10);
  }
  
  else if (data == '>')
  {
    //ambil paket
    player.playMp3Folder(11);
  }

  else if (data == 't')
  {
    player.playMp3Folder(12);
  }

  if (q == 1)
  {
    upVal = digitalRead(upSwitch);
    downVal = digitalRead(downSwitch);
    if (upVal == HIGH)
    {
      upString = ".";
    }

    else{
      upString = ",";
    }

    if (downVal == HIGH)
    {
      downString = "+";
    }
    
    else{
      downString = "=";
    }
    Serial.print(String(downString) + " " + String(upString) + " ");
    delay(500);
  }

  while (data == 'M'){
    upVal = digitalRead(upSwitch);
    downVal = digitalRead(downSwitch);
    if (downVal == 0 && upVal == 1 && count == 0)
    {
      analogWrite(lpwm, 0);
      analogWrite(rpwm, 255);
    }

    if (downVal == 1 && upVal == 1 && count == 0)
    {
      analogWrite(lpwm, 0);
      analogWrite(rpwm, 255);
    }
    
    if (downVal == 1 && upVal == 0 && count == 0)
    {
      if (t == 0)
      {
        analogWrite (lpwm, 0 );
        analogWrite (rpwm, 0);
        delay(2000);
        t = 1;
      }
      
      analogWrite(lpwm, 255);
      analogWrite(rpwm, 0);
      count = 1;
    }

    if (downVal == 1 && upVal == 1 && count == 1)
    {
      analogWrite(lpwm, 255);
      analogWrite(rpwm, 0);
    }

    if (downVal == 0 && upVal == 1 && count == 1)
    {
      analogWrite(lpwm, 0);
      analogWrite(rpwm, 0);

      t = 0;
      Serial.print('?');
      data = '-';
      count = 0;
      delay(1000);
      break;
    }
    
  }
  }

 
    
  data = '-';
>>>>>>> 9f4c145668b6fb6c7976d9e7904c2a03d2dd6554
}