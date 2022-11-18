#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
const int TONE_OUTPUT_PIN = 13;
const int TONE_PWM_CHANNEL = 0; 

int i = 0;
int j = 0;
int x = 0;
char input;

#define in1 27
#define in2 26
#define in3 32
#define in4 25

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Russel"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  ledcAttachPin(TONE_OUTPUT_PIN, TONE_PWM_CHANNEL);
}

void loop() { 
  input = SerialBT.read();
  
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
      if(input == 'F'){
        maju();
      }
      
      else if(input == 'S'){
        berhenti();
      }

      else if(input == 'B'){
        mundur();
      }

      else if(input == 'R'){
        kanan();
      }

      else if(input == 'L'){
        kiri();
      }

      else if(input == 'X'){
        x = 1;
      }

      else if(input == 'Y'){
        i = 0;
        x = 0;
        j = 0;
        ledcWriteTone(TONE_PWM_CHANNEL, 0);

      }

    //Serial.write(input);
  }
  if(x == 1){
    sirene();
  }
  delay(25);
}

void sirene(){
  if(i >= 0 && i <= 3 && j == 0){
    i++;
    ledcWriteNote(TONE_PWM_CHANNEL, NOTE_A, 5);
    if(i == 3){
      j+=1;
      i=0;
    }
    //delay(1);
  }
  if(i >= 0 && i <= 4 && j == 1){
    i++;
    ledcWriteNote(TONE_PWM_CHANNEL, NOTE_C, 5);
    if(i == 4){
      j-=1;
      i=0;
    }
   // delay(1);
  }
}

void berhenti(){
  //Serial.println  ("Stop");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void maju(){
  //Serial.println("Maju");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void mundur(){
  //Serial.println("Mundur");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void kanan(){
  //Serial.println("Kanan");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void kiri(){
  //Serial.println("Kiri");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
