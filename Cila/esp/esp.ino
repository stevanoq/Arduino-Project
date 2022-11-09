#include<SoftwareSerial.h>
#include <Blynk.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#include <TimeLib.h>

#define BLYNK_PRINT Serial

SoftwareSerial nodeMCU(3,1);
BlynkTimer timer;

char auth[] = "uiBWTY0m15C-4sxN_ISbNKTF-dPyfW9e";
char ssid[] = "PerAiran";
char pass[] = "1234567890";

char c;
String dataIn;
int8_t indexOfA,indexOfB,indexOfC;
String temp, ph, turbidity;

float dataSuhu, dataPh, dataTurbi;

void setup() {
  Serial.begin(115200);
  Serial.print("KOntol");
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);
  nodeMCU.begin(9600);
  setSyncInterval(10 * 60);
  timer.setInterval(500L, blynkData);
  Serial.print("KOntol");
}

void loop() {
    while(nodeMCU.available()>0){
      c = nodeMCU.read();
      Serial.println("DATA IN");
      Serial.println("PH = " + ph);
      Serial.println("Turbidity = " + turbidity);
      Serial.println("temp = " + temp);
      if(c=='\n'){
        break;
      }
      else {
        dataIn+=c;
      }
    }

    Serial.println("NO DATA");
    delay(500);
    if(c=='\n'){
      ParseTheData();
      c=0;
      dataIn="";
    }
    Blynk.run();
    timer.run();
}

void blynkData(){
  ParseTheData();
  dataSuhu = temp.toFloat();
  dataPh = ph.toFloat();
  dataaTurbi = turbidity.toFloat();
  Blynk.virtualWrite(V0, dataPh);
  Blynk.virtualWrite(V1, dataTurbi);
  Blynk.virtualWrite(V2, dataSuhu);
}

void ParseTheData(){
  indexOfA = dataIn.indexOf('A');
  indexOfB = dataIn.indexOf('B');
  indexOfC = dataIn.indexOf('C');

  ph = dataIn.substring(0,indexOfA);
  turbidity = dataIn.substring(indexOfA+1, indexOfB);
  temp = dataIn.substring(indexOfB+1, indexOfC);
}
