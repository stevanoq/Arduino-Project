<<<<<<< HEAD
#include <Arduino.h>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
byte BTData;
#define lamp 32

void setup() {
  Serial.begin(115200);
  SerialBT.begin("MyRoom");
  Serial.println("Bluetooth Started! Ready to pair...");
  pinMode(lamp, OUTPUT);
  digitalWrite(lamp, HIGH);
}

void loop() {
  if(SerialBT.available())
  {
    BTData = SerialBT.read();
    Serial.write(BTData);
  }

  
  if(BTData == 'F')
  {
    digitalWrite(lamp, HIGH);
    Serial.print("Off");
  }
  
  if(BTData == 'O')
  {
    digitalWrite(lamp, LOW);
    Serial.print("On");
  }
}
=======
#include <Arduino.h>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
byte BTData;
#define lamp 32

void setup() {
  Serial.begin(115200);
  SerialBT.begin("MyRoom");
  Serial.println("Bluetooth Started! Ready to pair...");
  pinMode(lamp, OUTPUT);
  digitalWrite(lamp, HIGH);
}

void loop() {
  if(SerialBT.available())
  {
    BTData = SerialBT.read();
    Serial.write(BTData);
  }

  
  if(BTData == 'F')
  {
    digitalWrite(lamp, HIGH);
    Serial.print("Off");
  }
  
  if(BTData == 'O')
  {
    digitalWrite(lamp, LOW);
    Serial.print("On");
  }
}
>>>>>>> 9f4c145668b6fb6c7976d9e7904c2a03d2dd6554
