#include <Arduino.h>
#include <HX711.h>
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <addons/RTDBHelper.h>
#include <addons/TokenHelper.h>

HX711 merah;
HX711 kuning;
HX711 hijau;

#define API_KEY "AIzaSyBBzBpl2ZC1zcGSo8r1GYRAGkQbW9HrAZE"
#define FIREBASE_PROJECT_ID "loadcell-f9d72"
#define URL_DATABASE "https://loadcell-f9d72-default-rtdb.firebaseio.com/"
#define EMAIL "esp32@gmail.com"
#define PASSWORD "1234567"
#define ssid "Galaxy A52"
#define pass "Ecelso011"

FirebaseData db;
FirebaseConfig config;
FirebaseAuth auth;
String UID;

float calibration_factor = -471.497;

float unit_merah;
float onces_merah;
float unit_kuning;
float onces_kuning;
float unit_hijau;
float onces_hijau;
float unit_total;

float current_merah, old_merah;
float current_kuning, old_kuning;
float current_hijau, old_hijau;
float new_value;

bool merah_state = true;
bool kuning_state = true;
bool hijau_state = true;
bool first = true;

int in_merah;
int in_hijau;
int in_kuning;
int in_total;
int in_new;

void setup() {

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,pass);
  while (WiFi.status() != WL_CONNECTED)
  {
      delay(500);
  }
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

  Firebase.RTDB.setInt(&db, "data/merah", in_merah);
  Firebase.RTDB.setInt(&db, "data/kuning", in_kuning);
  Firebase.RTDB.setInt(&db, "data/hijau", in_hijau);
  Firebase.RTDB.setInt(&db, "data/total", in_total);
  Firebase.RTDB.setInt(&db, "data/baru", in_new);

  Serial.begin(115200);
  merah.begin(13,12);
  merah.set_scale();
  merah.tare();

  kuning.begin(27,14);
  kuning.set_scale();
  kuning.tare();

  hijau.begin(25,26);
  hijau.set_scale();
  hijau.tare();
}

void loop() {
  merah.set_scale(calibration_factor);
  unit_merah = merah.get_units(), 10;
  if (unit_merah < 0)
  {
    unit_merah = 0.00;
  }

  onces_merah = unit_merah * 0.035274;

  kuning.set_scale(calibration_factor);
  unit_kuning = kuning.get_units(), 10;
  if (unit_kuning < 0)
  {
    unit_kuning = 0.00;
  }

  onces_kuning = unit_kuning * 0.035274;

  hijau.set_scale(calibration_factor);
  unit_hijau = hijau.get_units(), 10;
  if (unit_hijau < 0)
  {
    unit_hijau = 0.00;
  }

  onces_hijau = unit_hijau * 0.035274;
  
  if (merah_state)
  {
    in_merah = unit_merah;
    Firebase.RTDB.setInt(&db, "data/merah", in_merah);
    old_merah = unit_merah;
    merah_state = false;
  }

  if (kuning_state)
  {
    in_kuning = unit_kuning;
    Firebase.RTDB.setInt(&db, "data/kuning", in_kuning);
    old_kuning = unit_kuning;
    kuning_state = false;
  }
  
  if (hijau_state)
  {
    in_hijau = unit_hijau;
    Firebase.RTDB.setInt(&db, "data/hijau", unit_hijau);
    old_hijau = unit_hijau;
    hijau_state = false;
  }
  
  if (old_merah != unit_merah)
  {
    new_value = unit_merah - old_merah;
    unit_total = unit_hijau + unit_kuning + unit_kuning;
    in_new = new_value;
    in_total = unit_total;
    Firebase.RTDB.setInt(&db, "data/total", in_total);
    Firebase.RTDB.setInt(&db, "data/baru", in_new);
    merah_state = true;
  }
  
  if (old_kuning != unit_kuning)
  {
    new_value = unit_kuning - old_kuning;
    unit_total = unit_hijau + unit_kuning + unit_kuning;
    in_new = new_value;
    in_total = unit_total;
    Firebase.RTDB.setInt(&db, "data/total", in_total);
    Firebase.RTDB.setInt(&db, "data/baru", in_new);
    
    kuning_state = true;
  }

  if (old_hijau != unit_hijau)
  {
    new_value = unit_hijau - old_hijau;
    unit_total = unit_hijau + unit_kuning + unit_kuning;
    in_new = new_value;
    in_total = unit_total;
    Firebase.RTDB.setInt(&db, "data/total", in_total);
    Firebase.RTDB.setInt(&db, "data/baru", in_new);
    
    hijau_state = true;
  }
  
  Serial.print("merah = ");
  Serial.print(unit_merah);
  Serial.print(" gram || kuning = ");
  Serial.print(unit_kuning);
  Serial.print(" gram || hijau = ");
  Serial.print(unit_hijau);
  Serial.println(" gram");
}
