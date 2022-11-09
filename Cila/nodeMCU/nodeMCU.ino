#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <TimeLib.h>
#include<SoftwareSerial.h>

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

void setup()
{
  Serial.begin(115200);
  Serial.print("KOntol");
  Blynk.begin(auth, ssid, pass);
  nodeMCU.begin(9600);
  setSyncInterval(10 * 60);
  timer.setInterval(500L, blynkData);
}

void loop()
{
  Blynk.run();
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
}
void blynkData(){
  ParseTheData();
  dataSuhu = temp.toFloat();
  dataPh = ph.toFloat();
  dataTurbi = turbidity.toFloat();
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
