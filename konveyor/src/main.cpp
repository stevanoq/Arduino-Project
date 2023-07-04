/*
   Developed By Muhamad Fahrur Radzi, S.T.
   Baraya Code Startup Company
   Copyright 2022
*/
#include <Arduino.h>
#include <elapsedMillis.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

elapsedMillis SERVOMILLIS;
elapsedMillis SCANNINGMILLIS;

Servo pendorong;
Servo penyortir;
Servo palang;

//DEKLARASI PIN DAN VARIABEL
const int pinS0_KANAN      = 10;
const int pinS1_KANAN      = 9;
const int pinS2_KANAN      = 12;
const int pinS3_KANAN      = 11;
const int pinOUT_KANAN     = 13;

const int pinS0_KIRI      = 5;
const int pinS1_KIRI      = 4;
const int pinS2_KIRI      = 7;
const int pinS3_KIRI      = 6;
const int pinOUT_KIRI     = 8;

bool STOPKONVEYOR = 0;
bool SERVOSTATE = 0;

int logicRGB    = 0;

int R_KANAN   = 0;
int G_KANAN   = 0;
int B_KANAN   = 0;

int R_KIRI    = 0;
int G_KIRI    = 0;
int B_KIRI    = 0;

int MERAH_KANAN   = 0;
int KUNING_KANAN  = 0;
int HIJAU_KANAN   = 0;

int MERAH_KIRI    = 0;
int KUNING_KIRI   = 0;
int HIJAU_KIRI    = 0;

int MERAH_TOTAL   = 0;
int KUNING_TOTAL  = 0;
int HIJAU_TOTAL   = 0;

String LCD1   = "TOMAT BERWARNA  ";
String LCD2   = "TIDAK TERDETEKSI";
String SENSOR_KANAN = "TIDAK TERDETEKSI";
String SENSOR_KIRI  = "TIDAK TERDETEKSI";
String SCAN         = "";
String HASIL_SCAN   = "";
String breakloop;

void HOME();
void RGB_Final();
void convertRGBtoTOMAT_KANAN();
void convertRGBtoTOMAT_KIRI();
void SCANNING();
void EKSEKUSI();

void setup() {
  Serial.begin(9600);
  pendorong.attach(A1);
  penyortir.attach(A0);
  palang.attach(A2);
  pinMode(pinS0_KANAN, OUTPUT);
  pinMode(pinS1_KANAN, OUTPUT);
  pinMode(pinS2_KANAN, OUTPUT);
  pinMode(pinS3_KANAN, OUTPUT);
  pinMode(pinOUT_KANAN, INPUT);
  digitalWrite(pinS0_KANAN, HIGH); //Putting pinS0_KANAN/pinS1_KANAN on HIGH/HIGH levels means the output frequency scalling is at 100% (recommended)
  digitalWrite(pinS1_KANAN, HIGH); //LOW/LOW is off HIGH/LOW is 20% and LOW/HIGH is  2%

  pinMode(pinS0_KIRI, OUTPUT);
  pinMode(pinS1_KIRI, OUTPUT);
  pinMode(pinS2_KIRI, OUTPUT);
  pinMode(pinS3_KIRI, OUTPUT);
  pinMode(pinOUT_KIRI, INPUT);
  digitalWrite(pinS0_KIRI, HIGH); //Putting pinS0_KIRI/pinS1_KIRI on HIGH/HIGH levels means the output frequency scalling is at 100% (recommended)
  digitalWrite(pinS1_KIRI, HIGH); //LOW/LOW is off HIGH/LOW is 20% and LOW/HIGH is  2%

  breakloop = "HOME";

  /*INISIALISASI LCD*/
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME    ");
  lcd.setCursor(0, 1);
  lcd.print("               ");
  delay(500);
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME    ");
  lcd.setCursor(0, 1);
  lcd.print("       .       ");
  delay(500);
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME    ");
  lcd.setCursor(0, 1);
  lcd.print("      ...      ");
  delay(500);
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME    ");
  lcd.setCursor(0, 1);
  lcd.print("     .....     ");
  delay(500);
  lcd.clear();
}

void loop() {
  HOME();
  //  RGB_Final() ;
  //  Serial.print(SCAN);  Serial.print("\t");
  //  Serial.print(STOPKONVEYOR);  Serial.println("\t");
  // palang.write(0);
  // pendorong.write(0);
  // delay(1000);
  // pendorong.write(30);
  // delay(1000);
  // penyortir.write(0);
}

void RGB_Final() {
  //RED
  digitalWrite(pinS2_KANAN, LOW);
  digitalWrite(pinS3_KANAN, LOW);
  R_KANAN = pulseIn(pinOUT_KANAN, LOW);

  digitalWrite(pinS2_KIRI, LOW);
  digitalWrite(pinS3_KIRI, LOW);
  R_KIRI = pulseIn(pinOUT_KIRI, LOW);
  delay(100);

  //GREEN
  digitalWrite(pinS2_KANAN, HIGH);
  digitalWrite(pinS3_KANAN, HIGH);
  G_KANAN = pulseIn(pinOUT_KANAN, LOW);

  digitalWrite(pinS2_KIRI, HIGH);
  digitalWrite(pinS3_KIRI, HIGH);
  G_KIRI = pulseIn(pinOUT_KIRI, LOW);
  delay(100);

  //BLUE
  digitalWrite(pinS2_KANAN, LOW);
  digitalWrite(pinS3_KANAN, HIGH);
  B_KANAN = pulseIn(pinOUT_KANAN, LOW);

  digitalWrite(pinS2_KIRI, LOW);
  digitalWrite(pinS3_KIRI, HIGH);
  B_KIRI = pulseIn(pinOUT_KIRI, LOW);
  delay(100);

  convertRGBtoTOMAT_KANAN();
  convertRGBtoTOMAT_KIRI();

  MERAH_TOTAL   = MERAH_KANAN + MERAH_KIRI;
  KUNING_TOTAL  = KUNING_KANAN + KUNING_KIRI;
  HIJAU_TOTAL   = HIJAU_KANAN + HIJAU_KIRI;

  if (SENSOR_KANAN == "TIDAK TERDETEKSI" && SENSOR_KIRI == "TIDAK TERDETEKSI") {
    SCAN = "TIDAK TERDETEKSI";
    STOPKONVEYOR = 0;
  }
  else {
    STOPKONVEYOR = 1;
    if (MERAH_TOTAL >= 1) {
      SCAN = "MERAH";
    }
    else if (KUNING_TOTAL >= 1) {
      SCAN = "KUNING";
    }
    else if (HIJAU_TOTAL >= 1) {
      SCAN = "HIJAU";
    }
    else {
      SCAN = "BELANG";
    }
  }
}

void convertRGBtoTOMAT_KANAN() {
  //MERAH
  if ((R_KANAN >= 15 && R_KANAN <= 130) && (G_KANAN >= 60 && G_KANAN <= 160) && (B_KANAN >= 50 && B_KANAN <= 140)) {
    SENSOR_KANAN = "MERAH";
    MERAH_KANAN   = 1;
    KUNING_KANAN  = 0;
    HIJAU_KANAN   = 0;
  }
  //KUNING
  else if ((R_KANAN >= 15 && R_KANAN <= 85) && (G_KANAN >= 30 && G_KANAN <= 61) && (B_KANAN >= 30 && B_KANAN <= 96)) {
    SENSOR_KANAN = "KUNING";
    MERAH_KANAN   = 0;
    KUNING_KANAN  = 1;
    HIJAU_KANAN   = 0;
  }
  //HIJAU
  else if ((R_KANAN >= 20 && R_KANAN <= 35) && (G_KANAN >= 22 && G_KANAN <= 32) && (B_KANAN >= 35 && B_KANAN <= 47)) {
    SENSOR_KANAN = "HIJAU";
    MERAH_KANAN   = 0;
    KUNING_KANAN  = 0;
    HIJAU_KANAN   = 1;
  }
  else if ((R_KANAN >= 0 && R_KANAN <= 8) && (G_KANAN >= 0 && G_KANAN <= 8) && (B_KANAN >= 0 && B_KANAN <= 8)) {
    SENSOR_KANAN = "TIDAK TERDETEKSI";
  }
  else {
    SENSOR_KANAN = "BELANG";
    MERAH_KANAN   = 0;
    KUNING_KANAN  = 0;
    HIJAU_KANAN   = 0;
  }  
}

void convertRGBtoTOMAT_KIRI() {
  //MERAH
  if ((R_KIRI >= 19 && R_KIRI <= 55) && (G_KIRI >= 110 && G_KIRI <= 155) && (B_KIRI >= 100 && B_KIRI <= 135)) {
    SENSOR_KIRI = "MERAH";
    MERAH_KIRI    = 1;
    KUNING_KIRI   = 0;
    HIJAU_KIRI    = 0;
  }
  //KUNING
  else if ((R_KIRI >= 15 && R_KIRI <= 40) && (G_KIRI >= 43 && G_KIRI <= 75) && (B_KIRI >= 60 && B_KIRI <= 95)) {
    SENSOR_KIRI = "KUNING";
    MERAH_KIRI    = 0;
    KUNING_KIRI   = 1;
    HIJAU_KIRI    = 0;
  }
  //HIJAU
  else if ((R_KIRI >= 25 && R_KIRI <= 55) && (G_KIRI >= 30 && G_KIRI <= 60) && (B_KIRI >= 60 && B_KIRI <= 85)) {
    SENSOR_KIRI = "HIJAU";
    MERAH_KIRI    = 0;
    KUNING_KIRI   = 0;
    HIJAU_KIRI    = 1;
  }
  //TIDAK TERDETEKSI
  else if ((R_KIRI >= 0 && R_KIRI <= 8) && (G_KIRI >= 0 && G_KIRI <= 8) && (B_KIRI >= 0 && B_KIRI <= 8)) {
    SENSOR_KIRI = "TIDAK TERDETEKSI";
  }
  else {
    SENSOR_KIRI = "BELANG";
    MERAH_KIRI    = 0;
    KUNING_KIRI   = 0;
    HIJAU_KIRI    = 0;
  }
}


void HOME() {
  while (breakloop == "HOME") {
    lcd.setCursor(0, 0);
    lcd.print("MESIN RUNNING   ");
    lcd.setCursor(0, 1);
    lcd.print("KONVEYOR ON     ");

    //Servo Buka-Tutup setiap 2 detik
    if (SERVOMILLIS >= 2000) {
      SERVOSTATE = !SERVOSTATE;
      SERVOMILLIS = 0;
    }
    if (SERVOSTATE == 1) {
      pendorong.write(90);//SERVO DORONG AKTIF
    }
    else {
      pendorong.write(0); //SERVO DORONG MATI
    }

    //Servo Penyortir Default 0 Drajat ditengah
    penyortir.write(135); //SERVO SORTIR KE BELANG
    palang.write(0); //SERVO PALANG TUTUP

    //    Serial.print(breakloop); Serial.print("\t");
    //    Serial.print(SCAN);  Serial.print("\t");
    //    Serial.print(SENSOR_KANAN);  Serial.print("\t");
    //    Serial.print(SENSOR_KIRI);  Serial.print("\t");
    //    Serial.print(STOPKONVEYOR);  Serial.print("\t");
    //    Serial.println();

    Serial.print(breakloop); Serial.print("\t");
    Serial.print(R_KANAN); Serial.print("\t");
    Serial.print(G_KANAN); Serial.print("\t");
    Serial.print(B_KANAN); Serial.print("\t\t");
    Serial.print(R_KIRI); Serial.print("\t");
    Serial.print(G_KIRI); Serial.print("\t");
    Serial.print(B_KIRI); Serial.print("\t");
    Serial.print(SENSOR_KANAN); Serial.print("\t");
    Serial.print(SENSOR_KIRI); Serial.print("\t");
    Serial.print(SCAN); Serial.print("\t");
        Serial.println();

    //Scan IR jika ada tomat konveyor mati dan scanning dimulai
    RGB_Final();
    if (STOPKONVEYOR == 1) { //Jika TCS MENDETEKSI
      SERVOMILLIS = 0;
      SCANNINGMILLIS = 0;
      pendorong.write(0); //SERVO DORONG MATI
      palang.write(0); //SERVO PALANG TUTUP

      lcd.clear(); //LCD dibersihkan
      breakloop = "SCANNING";
      delay(100);
      break;
    }
  }
  if (breakloop == "SCANNING") {
    SCANNING();
    lcd.clear(); //LCD dibersihkan
  }
}

void SCANNING() {
  while (breakloop == "SCANNING") {
    lcd.setCursor(0, 0);
    lcd.print("SCANNING...     ");
    lcd.setCursor(0, 1);
    lcd.print("                ");

    //    Serial.print(breakloop); Serial.print("\t");
    //    Serial.print(R_KANAN); Serial.print("\t");
    //    Serial.print(G_KANAN); Serial.print("\t");
    //    Serial.print(B_KANAN); Serial.print("\t\t");
    //    Serial.print(R_KIRI); Serial.print("\t");
    //    Serial.print(G_KIRI); Serial.print("\t");
    //    Serial.print(B_KIRI); Serial.print("\t");
    //    Serial.print(SENSOR_KANAN); Serial.print("\t");
    //    Serial.print(SENSOR_KIRI); Serial.print("\t");
    //    Serial.print(SCAN); Serial.print("\t");
    //    Serial.println();

    Serial.print(breakloop); Serial.print("\t");
    Serial.print(SCAN);  Serial.print("\t");
    Serial.print(STOPKONVEYOR);  Serial.print("\t");
    Serial.println();

    SERVOMILLIS = 0;
    SCANNINGMILLIS; //Mulai Menghitung
    pendorong.write(0); //SERVO DORONG MATI
    palang.write(0); //SERVO PALANG TUTUP

    RGB_Final();

    if (SCANNINGMILLIS > 2000) { //Scanning sealam 2 detik menentukan warna tomat kemudian eksekusi
      HASIL_SCAN = SCAN;
      breakloop = "EKSEKUSI";
      delay(200);
      lcd.clear(); //LCD dibersihkan
      lcd.setCursor(0, 0);
      lcd.print("HASIL TOMAT :   ");
      lcd.setCursor(0, 1);
      lcd.print(SCAN);
      delay(3000);
      break;
    }
  }
  if (breakloop == "EKSEKUSI") {
    lcd.clear(); //LCD dibersihkan
    EKSEKUSI();
  }
}

void EKSEKUSI() {
  while (breakloop == "EKSEKUSI") {
    //Relay Konveyor Aktif
    SERVOMILLIS = 0;
    SCANNINGMILLIS = 0;


    Serial.print(breakloop); Serial.print("\t");
    Serial.print(SCAN);  Serial.print("\t");
    Serial.print(HASIL_SCAN);  Serial.print("\t");
    Serial.println();

    if (HASIL_SCAN == "MERAH") {
      penyortir.write(0); //SERVO SORTIR KE 0 DRAJAT
      delay(1000);
    }
    else if (HASIL_SCAN == "KUNING") {
      penyortir.write(45); //SERVO SORTIR KE 45 DRAJAT
      delay(1000);
    }
    else if (HASIL_SCAN == "HIJAU") {
      penyortir.write(90); //SERVO SORTIR KE 90 DRAJAT
      delay(1000);
    }
    else if (HASIL_SCAN == "BELANG") {
      penyortir.write(135); //SERVO SORTIR KE 135 DRAJAT
      delay(1000);
    }

    pendorong.write(0); //SERVO DORONG MATI
    palang.write(90); //SERVO PALANG BUKA
    breakloop = "HOME";
    lcd.clear(); //LCD dibersihkan
    delay(2000);
    break;

  }
  if (breakloop == "HOME") {
    lcd.clear(); //LCD dibersihkan
    HOME();
  }
}
