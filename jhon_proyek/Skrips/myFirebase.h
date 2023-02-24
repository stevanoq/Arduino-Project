#include "HardwareSerial.h"
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>
#include "lcd.h"

#define API_KEY "AIzaSyD-Cf4z72ok1VYrOTvlb6ELVwf1yRagq_g"
#define EMAIL "evanyap2002@gmai.com"
#define PASSWORD "1234567"
#define DATABASE_URL "smartbox-penerima-barang-default-rtdb.firebaseio.com/"

FirebaseData db;
FirebaseAuth auth;
FirebaseConfig config;
FirebaseJson json;

String UID, parentPath;

class FIRE {
  public:
    void init(){
      config.api_key = API_KEY;
      auth.user.emai = EMAIL;
      auth.user.password = PASSWORD;
      config.database_url = DATABASE_URL;
      Firebase.reconnectWiFi(true);
      db.setResponseSize(4096);
      config.token_status_callback = tokenStatusCallback;
      config.max_token_generation_retry = 5;
      Firebase.begin();
      
      while ((auth.token.uid) == "") {
        delay(1000);
      }

      UID = auth.token.uid.c_str();
      parentPath = UID + "/boxData";      
      mylcd.setFirebase();
    }

    void getData(){
      Firebase.
    }
}