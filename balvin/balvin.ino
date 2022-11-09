#include <NTPClient.h>
#include <WiFiUdp.h>
#include<Servo.h>

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

Servo myservo;
//time
int a = 0;
const long utcOffsetInSeconds = 25200;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Set these to run example.
#define FIREBASE_HOST "appmoaqu-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "h0VkjY1WtVNY5SF5Qb1aXlspKKlEALmb038Mwofd"
#define WIFI_SSID "Cinta Biak"
#define WIFI_PASSWORD "Djorkaef"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "id.pool.ntp.org", utcOffsetInSeconds);

void setup() {
  Serial.begin(115200);
  myservo.attach(D6);
  myservo.write(0);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  timeClient.begin();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;

void makan()
{
  myservo.write(180);
  delay(500);
  myservo.write(0);
  delay(500);
}

void loop() {  // set value
  timeClient.update();
    int jam = timeClient.getHours();
    int menit = timeClient.getMinutes();
    int detik = timeClient.getSeconds();

    Serial.print(daysOfTheWeek[timeClient.getDay()]);
    Serial.print(", ");
    Serial.print(jam);
    Serial.print(":");
    Serial.print(menit);
    Serial.print(":");
    Serial.println(detik);
   
   if(timeClient.getHours() == 14 && a == 0)
  {
    a = a+1;
    makan();
  }
  else if(timeClient.getHours() == 14 && a == 1)
  {
    a = 0;
    makan();
  }
  float data = analogRead(A0)- 205.0;
  if (data <= 0)
  {
    data = 0;
  }
  Firebase.setFloat("data/tds", data);
  Firebase.setInt("data/jam", jam);
  Firebase.setInt("data/menit", menit);
  Firebase.setInt("data/detik", detik);

  
}
