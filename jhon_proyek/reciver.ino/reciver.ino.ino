#include <ESPSoftwareSerial.h>
#include "CTBot.h"
#include <WiFi.h>

SoftwareSerial esp(18,19);
CTBot myBot;
TBMessage msg;

String SSID = "iPhoneJozzy";
String Password = "12345670";
String token = "6297690356:AAHkszYU0w2c0p0tv5Zrslg2Bwhn9jfD8PE";

const int id = 1604099726;

void connectWiFi();
void connectTelegram();

String reply = "";
String dataIn = "";
String realStatus = "";

char data;
float temp, humi;
int gas, status, indexOfA, indexOfB, indexOfC, indexOfD;

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);
  esp.begin(115200);

  connectWiFi();
  connectTelegram();
  myBot.sendMessage(msg.sender.id, (String)"Device is Active");
}

void loop() {
  while(Serial2.available() > 0){
    data = Serial2.read();

    if(data == '\n'){
      break;
    }

    else{
      dataIn += data;
      recieveData();
      Serial.print("Suhu = ");
      Serial.println(temp);
      Serial.print("Kelembaban = ");
      Serial.println(humi);
      Serial.print("Gas = ");
      Serial.println(gas);
      Serial.print("Status = ");
      Serial.println(status);
      Serial.println();
    }
  }
  sendTele();
  dataIn ="";

  
  // delay(1000);
}

void recieveData(){
  indexOfA = dataIn.indexOf('A');
  indexOfB = dataIn.indexOf('B');
  indexOfC = dataIn.indexOf('Q');
  indexOfD = dataIn.indexOf('D');

  temp = dataIn.substring(0, indexOfA).toFloat();
  humi = dataIn.substring(indexOfA+1, indexOfB).toFloat();
  status = dataIn.substring(indexOfB+1, indexOfC).toInt();
  gas = dataIn.substring(indexOfC+1, indexOfD).toInt();

  if(status == 0){
    realStatus = "AMAN";
  }

  else if(status == 1){
    realStatus = "API TERDETEKSI !!";
  }

  else if(status == 2){
    realStatus = "GAS TERDETEKSI !!\n Cek Kembali Tabung Gas Anda";
  }
}

void connectWiFi(){
  Serial.println("koneksi ke wifi");
  WiFi.begin(SSID.c_str(),Password.c_str());
  while(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("WiFi terkoneksi");
  // Serial.println(WiFi.SSID());
  // Serial.println(WiFi.RSSI());
  // Serial.println(WiFi.macAddress());
  // Serial.println(WiFi.localIP());
  // Serial.println(WiFi.gatewayIP);
  //Serial.println(WiFi.dnsP());
}

void connectTelegram(){
  Serial.println("login ke telegram");
  while(!myBot.testConnection()){
    myBot.setTelegramToken(token);
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Telegram OK");
}

void sendTele(){

  while(myBot.getNewMessage(msg)>0){
      if(msg.text.equalsIgnoreCase("Data")){
        reply = (String)"\tData Anda\n" + (String)"Gas =  " + gas + (String)"%\n" + (String)"Suhu = " + temp + (String)"°C\n" + (String)"Kelembaban = " + humi + (String)"%\n" + (String)"Status = " + realStatus + (String)"\n" ;
        myBot.sendMessage(msg.sender.id, reply);
        break;
      }

      else if(msg.text.equalsIgnoreCase("Suhu")){
        reply = (String)"Suhu = " + temp + (String)"°C";
        myBot.sendMessage(msg.sender.id, reply);
        break;
      }

      else if(msg.text.equalsIgnoreCase("Gas")){
        reply = (String)"Gas = " + gas + (String)"%";
        myBot.sendMessage(msg.sender.id, reply);
        break;
      }

      else if(msg.text.equalsIgnoreCase("Kelembaban")){
        reply = (String)"Kelembaban = " + humi + (String)"%";
        myBot.sendMessage(msg.sender.id, reply);
        break;
      }

      else if(msg.text.equalsIgnoreCase("Status")){
        reply = (String)"Status = " + realStatus;
        myBot.sendMessage(msg.sender.id, reply);
        break;
      }
  }    
  
    if(status != 0 && myBot.getNewMessage(msg)<=0){
      delay(1000);
      Serial.println("Send status");
      myBot.sendMessage(msg.sender.id, (String)realStatus);
    }

  
}