<<<<<<< HEAD

#include <AsyncElegantOTA.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <ota.h>

AsyncWebServer server(80);

void ota::task(){
 
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Hi! I am ESP32.");
  });

  AsyncElegantOTA.begin(&server);    
  server.begin();
  delay(1000);
}

=======

#include <AsyncElegantOTA.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <ota.h>

AsyncWebServer server(80);

void ota::task(){
 
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Hi! I am ESP32.");
  });

  AsyncElegantOTA.begin(&server);    
  server.begin();
  delay(1000);
}

>>>>>>> 9f4c145668b6fb6c7976d9e7904c2a03d2dd6554
