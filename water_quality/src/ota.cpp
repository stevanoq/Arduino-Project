
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

