#include <Wire.h>
#include "MAX30105.h"
#include "Adafruit_MLX90614.h"
#include "heartRate.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <NTPClient.h>
//#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

int nilai = 0;

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64

#define FIREBASE_HOST "heart-beat-monitoring-475bf-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "uekvdjcCtnXWo4OICStf0nNjQoOoD2XS8wRNwzRa"
#define WIFI_SSID "PerAiran"
#define WIFI_PASSWORD "gatauahmales"

MAX30105 particleSensor;
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const long utcOffsetInSeconds = 25200;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred

uint8_t irmlx90614_address = 0x5A;
float beatsPerMinute;
int beatAvg;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//WiFiUDP ntpUDP;
//NTPClient timeClient(ntpUDP, "id.pool.ntp.org", utcOffsetInSeconds);

void setup()
{
  Serial.begin(115200);
  Serial.println("Initializing...");

  // Initialize sensor
  if (!particleSensor.begin(Wire, 100000)) //Use default I2C port, 400kHz speed
  {
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1);
  }

  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }
  
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(WHITE);     
  oled.setCursor(0, 10);        
  oled.println("Loading..."); 
  oled.display();
  delay(2000);
  
  Serial.println("Place your index finger on the sensor with steady pressure.");
  mlx.begin();
  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
   Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  //timeClient.begin();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop()
{
  long irValue = particleSensor.getIR();
  if (checkForBeat(irValue) == true)
  {
    //We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable

      //Take average of readings
      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
  }

  Serial.print("IR=");
  Serial.print(irValue);
  Serial.print(", BPM=");
  Serial.print(beatsPerMinute);
  Serial.print(", Avg BPM=");
  Serial.print(beatAvg);
  Serial.print("Temp : ");
  Serial.print(mlx.readObjectTempC());

  oled.clearDisplay();
  oled.setCursor(0,0);
  oled.setTextSize(2);
  oled.println("BPM:");
  oled.setCursor(60,0);
  oled.setTextSize(2);
  oled.print(beatAvg);
  oled.setCursor(0,30);
  oled.setTextSize(2);
  oled.println("Temp: ");
  oled.setCursor(65,30);
  oled.setTextSize(2);
  oled.print(mlx.readObjectTempC());
  oled.display();

  /*timeClient.update();
    int jam = timeClient.getHours();
    int menit = timeClient.getMinutes();
    int detik = timeClient.getSeconds();  
*/
  if (irValue < 50000)
  {
    Serial.print(" No finger?");
    oled.setCursor(60,0);
    oled.setTextSize(2);
    oled.print("NF");
    oled.display();
  }
  if (beatAvg == 0){
    oled.setCursor(60,0);
    oled.setTextSize(2);
    oled.print("NF");
    oled.display();
  }

  
firebase();
 
  /*Firebase.setInt("data/jam", jam);
  Firebase.setInt("data/menit", menit);
  Firebase.setInt("data/detik", detik);
  */
  Serial.println();
}

void firebase()
{
  Firebase.setFloat("data/suhu",mlx.readObjectTempC());
  Firebase.setInt("data/detak",beatAvg);
 
}
