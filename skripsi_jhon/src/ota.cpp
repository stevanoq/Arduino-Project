#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
#include <lcd.h>
#include "ota.h"

// const char* ssid = "SALSABILLA";
// const char* password = "tanyaibukos";
const char* ssid = "PerAiran";
const char* password = "1234567890";
String IP;

AsyncWebServer server(80);
lcd MYLCd;
void ota::init() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  // Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    MYLCd.connectWiFi();
    delay(500);
    // Serial.print(".");
  }
  IP = WiFi.localIP().toString();
  // Serial.println("");
  // Serial.print("Connected to ");
  // Serial.println(ssid);
  // Serial.print("IP address: ");
  // Serial.println(WiFi.localIP());
  MYLCd.statrtingOta();
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Hi! I am ESP32.");
  });

  AsyncElegantOTA.begin(&server);    // Start ElegantOTA
  server.begin();
  // Serial.println("HTTP server started");

 
  delay(1000);
}

void ota::check()
{
  MYLCd.checkWiFi(ssid,password,IP);
}