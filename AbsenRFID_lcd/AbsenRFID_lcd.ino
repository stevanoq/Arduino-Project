#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16,2);

//Network SSID
const char* ssid = "napa?";
const char* password = "gatauahmales";

//pengenal host (server) = IP Address komputer server
const char* host = "192.168.43.254";

#define LED_PIN 15 //D8
#define LED_PIN_ER 1

//sediakan variabel untuk RFID
#define SDA_PIN 2  //D4
#define RST_PIN 0  //D3
#define BUZER_PIN D0

MFRC522 mfrc522(SDA_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  Wire.begin(D2, D1);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  
  //setting koneksi wifi
  WiFi.hostname("NodeMCU");
  WiFi.begin(ssid, password);

  //cek koneksi wifi
  while(WiFi.status() != WL_CONNECTED)
  {
    lcd.setCursor(0,0);
    lcd.print("===CONNECTING===");
    lcd.setCursor(0,1);
    lcd.print("====TO  WIFI====");
    //progress sedang mencari WiFi
    delay(500);
    Serial.print(".");
  }

  Serial.println("Wifi Connected");
  Serial.println("IP Address : ");
  Serial.println(WiFi.localIP());

  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN_ER, OUTPUT);
  pinMode(BUZER_PIN, OUTPUT);

  SPI.begin();
  mfrc522.PCD_Init();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMPELKAN KARTU");
  lcd.setCursor(6,1);
  lcd.print("ANDA");
  Serial.println("Dekatkan Kartu RFID Anda ke Reader");
}

void loop() {
  while(WiFi.status() != WL_CONNECTED)
  {
    lcd.setCursor(0,0);
    lcd.print("====WIFI NOT====");
    lcd.setCursor(0,1);
    lcd.print("===CONNECTED.===");
    digitalWrite(BUZER_PIN,HIGH);
    digitalWrite(LED_PIN_ER,HIGH);
    //progress sedang mencari WiFi
    delay(500);
    digitalWrite(BUZER_PIN,LOW);
    Serial.print(".");
  }
  //baca status pin button kemudian uji
  digitalWrite(LED_PIN_ER, LOW);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZER_PIN, LOW);

  if(! mfrc522.PICC_IsNewCardPresent())
     return ;

  if(! mfrc522.PICC_ReadCardSerial())
     return ;

  String IDTAG = "";
  for(byte i=0; i<mfrc522.uid.size; i++)
  {
      IDTAG += mfrc522.uid.uidByte[i];
  }

  //nyalakan lampu LED
  digitalWrite(BUZER_PIN, HIGH);

  //kirim nomor kartu RFID untuk disimpan ke tabel tmprfid
  WiFiClient client;
  WiFiClient client1;
  const int httpPort = 443;
  if(!client.connect(host, httpPort))
  {
     lcd.clear();
     lcd.setCursor(6,0);
     lcd.print("GAGAL");
     lcd.setCursor(6,1);
     lcd.print("ABSEN");
     digitalWrite(LED_PIN_ER, HIGH);
     delay(2000);
     digitalWrite(LED_PIN_ER, LOW);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("TEMPELKAN KARTU");
     lcd.setCursor(6,1);
     lcd.print("ANDA");
     Serial.println("Connection Failed");
     return;
  }

  String Link;
  HTTPClient http;
  Link = "http://192.168.43.254/rfidweb/kirimkartu.php?nokartu=" + IDTAG;
  http.begin(client,Link);

  int httpCode = http.GET();
  String payload = http.getString();
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(payload);
 
  Serial.println(payload);
  http.end();

  delay(100);
  String Link1;
  HTTPClient http1;
  Link1 = "http://192.168.43.254/rfidweb/kirimnama.php?nokartu=" + IDTAG;
  http1.begin(client1,Link1);
  int httpCode1 = http1.GET();
  String nama = http1.getString();
  lcd.setCursor(0,1);
  lcd.print(nama);
  http1.end();
  digitalWrite(LED_PIN, HIGH);
  delay(2000);
  digitalWrite(LED_PIN, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMPELKAN KARTU");
  lcd.setCursor(6,1);
  lcd.print("ANDA");
}
