#include<Servo.h>

#define out1 6
#define out2 7
#define out3 8
#define out4 9

Servo myServo;
char data;
int pos = 0;
 
void setup() {
  Serial.begin(9600);
  
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);

  myServo.attach(3);
  myServo.write(pos);
}

void loop() {

 while(Serial.available()>0){
  data = Serial.read();
  Serial.println(data);

  if(data == 'S'){
    digitalWrite(out1, LOW);
    digitalWrite(out2, LOW);
    digitalWrite(out3, LOW);
    digitalWrite(out4, LOW);
  }

  else if(data == 'F'){
    digitalWrite(out1, HIGH);
    digitalWrite(out2, LOW);
    digitalWrite(out3, LOW);
    digitalWrite(out4, HIGH);
  }

  else if(data == 'R'){
    digitalWrite(out1, HIGH);
    digitalWrite(out2, LOW);
    digitalWrite(out3, HIGH);
    digitalWrite(out4, LOW);
  }

  else if(data == 'G'){
    digitalWrite(out1, LOW);
    digitalWrite(out2, HIGH);
    digitalWrite(out3, HIGH);
    digitalWrite(out4, LOW);
  }

  else if(data == 'L'){
    digitalWrite(out1, LOW);
    digitalWrite(out2, HIGH);
    digitalWrite(out3, LOW);
    digitalWrite(out4, HIGH);
  }

  else if(data == 'X'){
    for (pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);              
    delay(15);                       
  }
  }

  else if(data == 'Y'){
    for (pos = 180; pos >= 0; pos -= 1) { 
    myServo.write(pos);              
    delay(15);                       
  }
  }
 }
}
