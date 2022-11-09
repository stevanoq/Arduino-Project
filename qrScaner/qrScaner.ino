#include "esp_camera.h"
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "quirc.h"
#include "camera.h"
#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>

TaskHandle_t QRCodeReader_Task; 

#define FIREBASE_HOST "qr-loc-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "kY32xGDjFvZOBr3BKWr8jlJagZWSAbhPv9dvA6nC"

#define WIFI_SSID "PerAiran"
#define WIFI_PASSWORD "12345678"

struct QRCodeData
{
  bool valid;
  int dataType;
  uint8_t payload[1024];
  int payloadLen;
};

struct quirc *q = NULL;
uint8_t *image = NULL;  
camera_fb_t * fb = NULL;
struct quirc_code code;
struct quirc_data data;
quirc_decode_error_t err;
struct QRCodeData qrCodeData;  
String QRCodeResult = "";

void setup() {

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to wifi");
  while(WiFi.status() != WL_CONNECTED);
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println("Connected to wifi");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setString("esp32cam/scan", "stanby");
  Firebase.setString("esp32cam/connection", "connected");
  
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);

  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  initCamera();
  
  xTaskCreatePinnedToCore(
             QRCodeReader,          /* Task function. */
             "QRCodeReader_Task",   /* name of task. */
             10000,                 /* Stack size of task */
             NULL,                  /* parameter of the task */
             1,                     /* priority of the task */
             &QRCodeReader_Task,    /* Task handle to keep track of created task */
             0);                    /* pin task to core 0 */
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1);
}

void firedata(){
  String noLoker = Firebase.getString("noLoker");
  int qrcode = Firebase.getInt(noLoker + "/qrcode");
  String kamera = Firebase.getString("esp32cam/status");

  if(kamera == "ON");{
    if(QRCodeResult.toInt() == qrcode){
      Firebase.setString("esp32cam/scan", "berhasil");
      Firebase.setString(noLoker +"/status", "buka");
      Firebase.setInt(noLoker + "/qrcode", 0);
      Firebase.setString("esp32cam/status", "OFF");
      Serial.println("firebase ok");   
    }
    else{
      Firebase.setString("esp32cam/scan", "gagal");
    }
  }
}

// This function is to instruct the camera to take or capture a QR Code image, then it is processed and translated into text.
void QRCodeReader( void * pvParameters ){
  /* ---------------------------------------- */
  Serial.println("QRCodeReader is ready.");
  Serial.print("QRCodeReader running on core ");
  Serial.println(xPortGetCoreID());
  Serial.println();
  /* ---------------------------------------- */

  /* Loop to read QR Code in real time. */
  while(1){
      q = quirc_new();
      if (q == NULL){
        Serial.print("can't create quirc object\r\n");  
        continue;
      }
    
      fb = esp_camera_fb_get();
      if (!fb)
      {
        Serial.println("Camera capture failed");
        continue;
      }   
      
      quirc_resize(q, fb->width, fb->height);
      image = quirc_begin(q, NULL, NULL);
      memcpy(image, fb->buf, fb->len);
      quirc_end(q);
      
      int count = quirc_count(q);
      if (count > 0) {
        quirc_extract(q, 0, &code);
        err = quirc_decode(&code, &data);
    
        if (err){
          Serial.println("Decoding FAILED");
          QRCodeResult = "Decoding FAILED";
          //Firebase.setString("esp32cam/scan", "scaning");
        } else {
          Serial.printf("Decoding successful:\n");
          dumpData(&data);
          firedata();
        }
        Serial.println();
      } 
      
      esp_camera_fb_return(fb);
      fb = NULL;
      image = NULL;  
      quirc_destroy(q);
  }
  /* ---------------------------------------- */
}

/*Function to display the results of reading the QR Code on the serial monitor. */
void dumpData(const struct quirc_data *data)
{
  Serial.printf("Version: %d\n", data->version);
  Serial.printf("ECC level: %c\n", "MLHQ"[data->ecc_level]);
  Serial.printf("Mask: %d\n", data->mask);
  Serial.printf("Length: %d\n", data->payload_len);
  Serial.printf("Payload: %s\n", data->payload);
  
  QRCodeResult = (const char *)data->payload;
}
