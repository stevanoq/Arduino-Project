#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <TimeLib.h>

BlynkTimer timer;

char auth[] = "mM5JRyNU3YkLJPJj-mq7BvA3CrviEv0r";
char ssid[] = "PerAiran";
char pass[] = "1234567890";
float data;
float suhu;
float turbidity;
float ph;
String Status;

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  setSyncInterval(10*60); 
  timer.setInterval(1000L, blynkData);
}

void loop() {
  Blynk.run();
  timer.run();
  
  if(Serial.available()>0){
    data = Serial.parseFloat();
    if(Serial.read() == '\n'){
      if(data >= 1000 && data <=1500){
        suhu = data - 1000.0;
      }

      if(data >= 2000 && data <= 5000){
        turbidity = data - 2000.0;
      }

      if(data >= 5500 && data<=5600){
        ph = data - 5500.0;
      }

      if(data == 1){
        Status = "CLEANING";
      }
      if(data == 2){
        Status = "CLEAN";
      }
    }
  }
  //Serial.println(data);
  delay(500);
}

void blynkData(){
  Blynk.virtualWrite(V0, suhu);  
  Blynk.virtualWrite(V1, turbidity);
  Blynk.virtualWrite(V2, ph);
  Blynk.virtualWrite(V3, Status);
  
}
