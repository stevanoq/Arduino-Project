#include <WiFi.h>
#include <FirebaseESP32.h>
#include <addons/RTDBHelper.h>
#include <addons/TokenHelper.h>
#include <AsyncElegantOTA.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include "mynetwork.h"

#define API_KEY "AIzaSyCApS4nZWlCut9RBIh662psgYkcMLLmz78"
#define FIREBASE_PROJECT_ID "coffee-been-dryer"
#define URL_DATABASE "https://coffee-been-dryer-default-rtdb.firebaseio.com/"
#define EMAIL "yosefpamungkas97@gmail.com"
#define PASSWORD "1234567"

FirebaseData db;
FirebaseConfig config;
FirebaseAuth auth;
String UID;
AsyncWebServer server(80);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "asia.pool.ntp.org", 25200);

void myfirebase::begin()
{
    timeClient.begin();
    config.api_key = API_KEY;
    auth.user.email = EMAIL;
    auth.user.password = PASSWORD;
    config.database_url = URL_DATABASE;
    Firebase.reconnectWiFi(true);
    db.setResponseSize(4096);
    config.token_status_callback = tokenStatusCallback;
    config.max_token_generation_retry = 5;
    Firebase.begin(&config,&auth);

    while (auth.token.uid == "")
    {
        delay(1000);
    }
    
    UID = auth.token.uid.c_str();
}

void myfirebase::send(String PATH, String data)
{
    String path;
    path = "data/" + PATH;
    Firebase.RTDB.setString(&db, path, data);
}

void myfirebase::send_time(String path)
{
    String PATH, data;
    PATH = "data/time/" + path;
    int minutes, hours;
    float fHours, fMinutes;
    timeClient.update();
    while (!timeClient.update())
    {
        timeClient.forceUpdate();
    }

    hours = timeClient.getHours();
    minutes = timeClient.getMinutes();
    if (minutes < 10)
    {
        data = String(hours) + ":" + "0" + String(minutes);
    }

    else
    {
        data = String(hours) + ":" + String(minutes);
    }
    
    // if (path == "startTime")
    // {
    //     fMinutes = minutes/60;
    //     fHours = hours/1;
    //     this->TIME1 = fHours + fMinutes;
    // }
    
    // else if (path == "endTime")
    // {
    //     fMinutes = minutes/60;
    //     fHours = hours/1;
    //     this->TIME2 = fHours + fMinutes;
    // }
    
    Firebase.RTDB.setString(&db, PATH, data);
}

void myfirebase::get_time(String path)
{
    String endTime, startTime, hours, minutes;
    if (path == "start")
    {
        if (Firebase.RTDB.pathExisted(&db, "data"))
        {
            if (Firebase.RTDB.getString(&db, "data/time/startTime") && db.dataType() == "string")
            {
                startTime = db.stringData();
                hours = startTime.substring(0,startTime.indexOf(":"));
                minutes = startTime.substring(startTime.indexOf(":")+1,5);
                this->TIME1 = hours.toFloat() + (minutes.toFloat()/60);
                Serial.print("hours ");
                Serial.println(hours);
                Serial.print("minute ");
                Serial.println(minutes);
                Serial.print("TIME1 ");
                Serial.println(TIME1);
            }
        }
    }

    else if (path == "end")
    {
        if (Firebase.RTDB.pathExisted(&db, "data"))
        {
            if (Firebase.RTDB.getString(&db, "data/time/endTime") && db.dataType() == "string")
            {
                endTime = db.stringData();
                hours = endTime.substring(0,endTime.indexOf(":"));
                minutes = endTime.substring(endTime.indexOf(":")+1,5);
                this->TIME2 = hours.toFloat() + (minutes.toFloat()/60);
                ;
            }
        }
                Serial.print("hours ");
                Serial.println(hours);
                Serial.print("minute ");
                Serial.println(minutes);
                Serial.print("TIME2 ");
                Serial.println(TIME2);
    }
}

void ota::begin()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid,pass);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Hi! I am ESP32.");
    });
    AsyncElegantOTA.begin(&server);
    server.begin();
}
