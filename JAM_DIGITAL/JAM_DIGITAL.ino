#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;
int a = 0;
int b = 0;
int buzzer = A0;
int digit1 = 10;
int digit2 = 11;
int digit3 = 12;
int digit4 = 13;

int segA = 8; //Display pin 8
int segB = 7; //Display pin 7
int segC = 6; //Display pin 6
int segD = 5; //Display pin 5
int segE = 4; //Display pin 4
int segF = 3; //Display pin 3
int segG = 2; //Display pin 2
int segDP = 9; // Display pin 9

byte SW0 = A1;

byte SW1 = A2;

byte SW2 = A3;


// use for hexa in zecimal conversion

int zh, uh, ore;

int zm, um, miniti;


void setup() {
 Serial.begin(9600);
 Wire.begin();
 RTC.begin();


Wire.beginTransmission(0x68);

Wire.write(0x07); // move pointer to SQW address

// Wire.write(0x00); // turns the SQW pin off

Wire.write(0x10); // sends 0x10 (hex) 00010000 (binary) to control register - turns on square wave at 1Hz

// Wire.write(0x13); // sends 0x13 (hex) 00010011 (binary) 32kHz


Wire.endTransmission();


 if (! RTC.isrunning()) {

  Serial.println("RTC is NOT running!");

  // following line sets the RTC to the date & time this sketch was compiled

  RTC.adjust(DateTime(__DATE__, __TIME__));

 }

// dht.begin();
  digitalWrite(buzzer, LOW);

 pinMode(segA, OUTPUT);

 pinMode(segB, OUTPUT);

 pinMode(segC, OUTPUT);

 pinMode(segD, OUTPUT);

 pinMode(segE, OUTPUT);

 pinMode(segF, OUTPUT);

 pinMode(segG, OUTPUT);

 pinMode(segDP, OUTPUT);


 pinMode(digit1, OUTPUT);

 pinMode(digit2, OUTPUT);

 pinMode(digit3, OUTPUT);

 pinMode(digit4, OUTPUT);

 pinMode(buzzer, OUTPUT);



// pinMode(13, OUTPUT);


Serial.begin(9600);

Serial.println("test for niq_ro");


pinMode(SW0, INPUT); // for this use a slide switch

 pinMode(SW1, INPUT); // N.O. push button switch

 pinMode(SW2, INPUT); // N.O. push button switch


 digitalWrite(SW0, HIGH); // pull-ups on

 digitalWrite(SW1, HIGH);

 digitalWrite(SW2, HIGH);




}


void loop() {
  Serial.print("SW1");
Serial.println(SW1);
digitalWrite(segDP, HIGH);

 DateTime now = RTC.now();

 int timp = now.hour()*100+now.minute();

// int timp = (now.minute(), DEC);

// displayNumber(12); // this is number to diplay

// int timp = 1234;

 Serial.print(now.hour(), DEC);

 Serial.print(":");

 Serial.print(now.minute(), DEC);

 Serial.print(" -> ");

 Serial.print(timp);

 Serial.println(" !");


// display parts 

 for(int i = 250 ; i >0 ; i--) {

  if (timp >= 1000) displayNumber01(timp);

  else displayNumber02(timp);

 }


 for(int i = 250 ; i >0 ; i--) {

  if (timp >= 1000) displayNumber03(timp);

  else displayNumber04(timp);

 }


 if (!(digitalRead(SW0))) set_time(); // hold the switch to set time

 if(now.hour() == 7 && now.minute() == 0)
 {
  alarm();
 }
 if(now.hour() == 8 && now.minute() == 0)
 {
  alarm();
 }
 if(now.hour() == 9 && now.minute() == 0)
 {
  alarm();
 }
 if(a==0 && now.minute() == 1)
 {
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  a = a+1;
 }
 if(now.minute() == 2)
 {
  a=0;
  b=0;
 }

}

void alarm()
{
  if(b == 0)
  {
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(500); 
  }
  while (!digitalRead(SW1))
  {
    b = b + 1; 
  }
  
}

void set_time() {

 byte minutes1 = 0;

 byte hours1 = 0;

 byte minutes = 0;

 byte hours = 0;


 while (!digitalRead(SW0)) // set time switch must be released to exit

 {

  minutes1=minutes;

  hours1=hours;

 

  

  while (!digitalRead(SW1)) // set minutes

  {

  minutes++;

 // converting hexa in zecimal:

  zh = hours / 16;

  uh = hours - 16 * zh ;

  ore = 10 * zh + uh;

  zm = minutes / 16;

  um = minutes - 16 * zm ;

  miniti = 10 * zm + um;

 

  for(int i = 20 ; i >0 ; i--) {

  displayNumber01(ore*100+miniti);

  }


  

   if ((minutes & 0x0f) > 9) minutes = minutes + 6;

   if (minutes > 0x59) minutes = 0;

   Serial.print("Minutes = ");

   if (minutes >= 9) Serial.print("0");

   Serial.println(minutes, HEX);

  delay(150); 

  }


  while (!digitalRead(SW2)) // set hours

  {

  hours++;    

  

 // converting hexa in zecimal:

  zh = hours / 16;

  uh = hours - 16 * zh ;

  ore = 10 * zh + uh;

  zm = minutes / 16;

  um = minutes - 16 * zm ;

  miniti = 10 * zm + um;

 

  for(int i = 20 ; i >0 ; i--) {

  displayNumber01(ore*100+miniti);

  }

 

  

   if ((hours & 0x0f) > 9) hours = hours + 6;

   if (hours > 0x23) hours = 0;

   Serial.print("Hours = ");

   if (hours <= 9) Serial.print("0");

   Serial.println(hours, HEX);

  delay(150);

  }


  Wire.beginTransmission(0x68); // activate DS1307

  Wire.write(0); // where to begin

  Wire.write(0x00);     //seconds

  Wire.write(minutes);     //minutes

  Wire.write(0x80 | hours);  //hours (24hr time)

  Wire.write(0x06); // Day 01-07

  Wire.write(0x01); // Date 0-31

  Wire.write(0x05); // month 0-12

  Wire.write(0x09); // Year 00-99

  Wire.write(0x10); // Control 0x10 produces a 1 HZ square wave on pin 7.

  Wire.endTransmission();



  // converting hexa in zecimal:

  zh = hours / 16;

  uh = hours - 16 * zh ;

  ore = 10 * zh + uh;

  zm = minutes / 16;

  um = minutes - 16 * zm ;

  miniti = 10 * zm + um;

 

  for(int i = 20 ; i >0 ; i--) {

  displayNumber01(ore*100+miniti);

  }

// delay(150);

 

 }



}




void displayNumber01(int toDisplay) {

#define DISPLAY_BRIGHTNESS 500


#define DIGIT_ON LOW

#define DIGIT_OFF HIGH


 for(int digit = 4 ; digit > 0 ; digit--) {


  //Turn on a digit for a short amount of time

  switch(digit) {

  case 1:

  digitalWrite(digit1, DIGIT_ON);

  digitalWrite(segDP, HIGH);

   break;

 case 2:

   digitalWrite(digit2, DIGIT_ON);

   digitalWrite(segDP, HIGH);

   break;

  case 3:

   digitalWrite(digit3, DIGIT_ON);

   digitalWrite(segDP, HIGH);

   break;

  case 4:

   digitalWrite(digit4, DIGIT_ON);

   digitalWrite(segDP, HIGH);

   break;

  }

  lightNumber(toDisplay % 10);

  toDisplay /= 10;

  delayMicroseconds(DISPLAY_BRIGHTNESS);


  //Turn off all segments

  lightNumber(10);


  //Turn off all digits

  digitalWrite(digit1, DIGIT_OFF);

  digitalWrite(digit2, DIGIT_OFF);

  digitalWrite(digit3, DIGIT_OFF);

  digitalWrite(digit4, DIGIT_OFF);

}

}


void displayNumber02(int toDisplay) {

#define DISPLAY_BRIGHTNESS 500


#define DIGIT_ON LOW

#define DIGIT_OFF HIGH


 for(int digit = 4 ; digit > 0 ; digit--) {


  //Turn on a digit for a short amount of time

  switch(digit) {

  case 1:

  lightNumber(10);

  digitalWrite(segDP, HIGH);

  break;

 case 2:

   digitalWrite(digit2, DIGIT_ON);

   digitalWrite(segDP, HIGH);

   break;

  case 3:

   digitalWrite(digit3, DIGIT_ON);

   digitalWrite(segDP, HIGH);

   break;

  case 4:

   digitalWrite(digit4, DIGIT_ON);

   digitalWrite(segDP, HIGH);

   break;

  }

  lightNumber(toDisplay % 10);

  toDisplay /= 10;

  delayMicroseconds(DISPLAY_BRIGHTNESS);


  //Turn off all segments

  lightNumber(10);


  //Turn off all digits

  digitalWrite(digit1, DIGIT_OFF);

  digitalWrite(digit2, DIGIT_OFF);

  digitalWrite(digit3, DIGIT_OFF);

  digitalWrite(digit4, DIGIT_OFF);

}

}


void displayNumber03(int toDisplay) {

#define DISPLAY_BRIGHTNESS 500


#define DIGIT_ON LOW

#define DIGIT_OFF HIGH


 for(int digit = 4 ; digit > 0 ; digit--) {


  //Turn on a digit for a short amount of time

  switch(digit) {

  case 1:

  digitalWrite(digit1, DIGIT_ON);

  digitalWrite(segDP, LOW);

   break;

 case 2:

   digitalWrite(digit2, DIGIT_ON);

   digitalWrite(segDP, LOW);

   break;

  case 3:

   digitalWrite(digit3, DIGIT_ON);

   digitalWrite(segDP, LOW);

   break;

  case 4:

   digitalWrite(digit4, DIGIT_ON);

   digitalWrite(segDP, LOW);

   break;

  }

  lightNumber(toDisplay % 10);

  toDisplay /= 10;

  delayMicroseconds(DISPLAY_BRIGHTNESS);


  //Turn off all segments

  lightNumber(10);


  //Turn off all digits

  digitalWrite(digit1, DIGIT_OFF);

  digitalWrite(digit2, DIGIT_OFF);

  digitalWrite(digit3, DIGIT_OFF);

  digitalWrite(digit4, DIGIT_OFF);

}

}


void displayNumber04(int toDisplay) {

#define DISPLAY_BRIGHTNESS 500


#define DIGIT_ON LOW

#define DIGIT_OFF HIGH


 for(int digit = 4 ; digit > 0 ; digit--) {


  //Turn on a digit for a short amount of time

  switch(digit) {

  case 1:

  lightNumber(10);

  digitalWrite(segDP, LOW);

  break;

 case 2:

   digitalWrite(digit2, DIGIT_ON);

   digitalWrite(segDP, LOW);

   break;

  case 3:

   digitalWrite(digit3, DIGIT_ON);

   digitalWrite(segDP, LOW);

   break;

  case 4:

   digitalWrite(digit4, DIGIT_ON);

   digitalWrite(segDP, LOW);

   break;

  }

  lightNumber(toDisplay % 10);

  toDisplay /= 10;

  delayMicroseconds(DISPLAY_BRIGHTNESS);


  //Turn off all segments

  lightNumber(10);


  //Turn off all digits

  digitalWrite(digit1, DIGIT_OFF);

  digitalWrite(digit2, DIGIT_OFF);

  digitalWrite(digit3, DIGIT_OFF);

  digitalWrite(digit4, DIGIT_OFF);

}

}


void lightNumber(int numberToDisplay) {


#define SEGMENT_ON HIGH

#define SEGMENT_OFF LOW


 switch (numberToDisplay){


 case 0:

  digitalWrite(segA, SEGMENT_ON);

  digitalWrite(segB, SEGMENT_ON);

  digitalWrite(segC, SEGMENT_ON);

  digitalWrite(segD, SEGMENT_ON);

  digitalWrite(segE, SEGMENT_ON);

  digitalWrite(segF, SEGMENT_ON);

  digitalWrite(segG, SEGMENT_OFF);

  break;


 case 1:

  digitalWrite(segA, SEGMENT_OFF);

  digitalWrite(segB, SEGMENT_ON);

  digitalWrite(segC, SEGMENT_ON);

  digitalWrite(segD, SEGMENT_OFF);

  digitalWrite(segE, SEGMENT_OFF);

  digitalWrite(segF, SEGMENT_OFF);

  digitalWrite(segG, SEGMENT_OFF);

  break;


 case 2:

  digitalWrite(segA, SEGMENT_ON);

  digitalWrite(segB, SEGMENT_ON);

  digitalWrite(segC, SEGMENT_OFF);

  digitalWrite(segD, SEGMENT_ON);

  digitalWrite(segE, SEGMENT_ON);

  digitalWrite(segF, SEGMENT_OFF);

  digitalWrite(segG, SEGMENT_ON);

  break;


 case 3:

  digitalWrite(segA, SEGMENT_ON);

  digitalWrite(segB, SEGMENT_ON);

  digitalWrite(segC, SEGMENT_ON);

  digitalWrite(segD, SEGMENT_ON);

  digitalWrite(segE, SEGMENT_OFF);

  digitalWrite(segF, SEGMENT_OFF);

  digitalWrite(segG, SEGMENT_ON);

  break;


 case 4:

  digitalWrite(segA, SEGMENT_OFF);

  digitalWrite(segB, SEGMENT_ON);

  digitalWrite(segC, SEGMENT_ON);

  digitalWrite(segD, SEGMENT_OFF);

  digitalWrite(segE, SEGMENT_OFF);

  digitalWrite(segF, SEGMENT_ON);

  digitalWrite(segG, SEGMENT_ON);

  break;


 case 5:

  digitalWrite(segA, SEGMENT_ON);

  digitalWrite(segB, SEGMENT_OFF);

  digitalWrite(segC, SEGMENT_ON);

  digitalWrite(segD, SEGMENT_ON);

  digitalWrite(segE, SEGMENT_OFF);

  digitalWrite(segF, SEGMENT_ON);

  digitalWrite(segG, SEGMENT_ON);

  break;


 case 6:

  digitalWrite(segA, SEGMENT_ON);

  digitalWrite(segB, SEGMENT_OFF);

  digitalWrite(segC, SEGMENT_ON);

  digitalWrite(segD, SEGMENT_ON);

  digitalWrite(segE, SEGMENT_ON);

  digitalWrite(segF, SEGMENT_ON);

  digitalWrite(segG, SEGMENT_ON);

  break;


 case 7:

  digitalWrite(segA, SEGMENT_ON);

  digitalWrite(segB, SEGMENT_ON);

  digitalWrite(segC, SEGMENT_ON);

  digitalWrite(segD, SEGMENT_OFF);

  digitalWrite(segE, SEGMENT_OFF);

  digitalWrite(segF, SEGMENT_OFF);

  digitalWrite(segG, SEGMENT_OFF);

  break;


 case 8:

  digitalWrite(segA, SEGMENT_ON);

  digitalWrite(segB, SEGMENT_ON);

  digitalWrite(segC, SEGMENT_ON);

  digitalWrite(segD, SEGMENT_ON);

  digitalWrite(segE, SEGMENT_ON);

  digitalWrite(segF, SEGMENT_ON);

  digitalWrite(segG, SEGMENT_ON);

  break;


 case 9:

  digitalWrite(segA, SEGMENT_ON);

  digitalWrite(segB, SEGMENT_ON);

  digitalWrite(segC, SEGMENT_ON);

  digitalWrite(segD, SEGMENT_ON);

  digitalWrite(segE, SEGMENT_OFF);

  digitalWrite(segF, SEGMENT_ON);

  digitalWrite(segG, SEGMENT_ON);

  break;


 // all segment are ON

 case 10:

  digitalWrite(segA, SEGMENT_OFF);

  digitalWrite(segB, SEGMENT_OFF);

  digitalWrite(segC, SEGMENT_OFF);

  digitalWrite(segD, SEGMENT_OFF);

  digitalWrite(segE, SEGMENT_OFF);

  digitalWrite(segF, SEGMENT_OFF);

  digitalWrite(segG, SEGMENT_OFF);

 break;



 }

}
