#include <LiquidCrystal_I2C.h>
#include "lcd.h"
#include <Arduino.h>
LiquidCrystal_I2C LCD(0x27, 20, 4);

void lcd::init(){
    
    LCD.init();
    LCD.backlight();
    LCD.clear();
    LCD.setCursor(1,1);
    LCD.print("STARTING SMARTBOX");
    LCD.setCursor(7,2);
    LCD.print("SYSTEM");
    Serial.print('Z');
    delay(1000);
}

void lcd::selectAction(){
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("SILAHKAN PILIH MODE:");
    LCD.setCursor(0,1);
    LCD.print("--------------------");
    LCD.setCursor(0,2);
    LCD.print("A.AMBIL");
    LCD.setCursor(0,3);
    LCD.print("B.TITIP");
}

void lcd::selectMode(){
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("SILAHKAN PILIH MODE:");
    LCD.setCursor(0,1);
    LCD.print("--------------------");
    LCD.setCursor(0,2);
    LCD.print("A.Scan Barcode");
    LCD.setCursor(0,3);
    LCD.print("B.Input Manual C.<-");
}

void lcd::textResult(String data){
    LCD.clear();
    LCD.setCursor(4,0);
    LCD.print("BARCODE ANDA");
    LCD.setCursor(0,1);
    LCD.print("--------------------");
    LCD.setCursor(0,2);
    LCD.print(data);
}

void lcd::scan(bool state){
    if (state)
    {
        delay(500);
        LCD.clear();
        LCD.setCursor(0,0);
        LCD.print("ARAHKAN BARCODE RESI");
        LCD.setCursor(5,1);
        LCD.print("KE  KAMERA");
        LCD.setCursor(2,3);
        LCD.print("A.RETRY C.BATAL");
        state = false;
    }
}

void lcd::connectWiFi()
{
    LCD.clear();
    LCD.setCursor(1,1);
    LCD.print("CONNECTING TO WIFI");
}

void lcd::connectFirebase()
{
    LCD.clear();
    LCD.setCursor(3,1);
    LCD.print("CONNECTING TO");
    LCD.setCursor(5,2);
    LCD.print("FIREBASE");
}

void lcd::succesInit()
{
    LCD.clear();
    LCD.setCursor(1,1);
    LCD.print("INSTALIZING SYSTEM");
    LCD.setCursor(3,2);
    LCD.print("ARE SUCCESFULLY");
    Serial.print('z');
    delay(3000);
}

void lcd::statrtingOta()
{
    LCD.clear();
    LCD.setCursor(4,1);
    LCD.print("STARTING OTA");
    LCD.setCursor(7,2);
    LCD.print("SERVER");
}

void lcd::unverified()
{
    LCD.clear();
    LCD.setCursor(3,1);
    LCD.print("DATA ANDA TIDAK");
    LCD.setCursor(4,2);
    LCD.print("TERVERIFIKASI");
}

void lcd::verified()
{
    LCD.clear();
    LCD.setCursor(1,1);
    LCD.print("DATA ANDA BERHASIL");
    LCD.setCursor(4,2);
    LCD.print("TERVERIFIKASI");
}

void lcd::take()
{
    LCD.clear();
    LCD.setCursor(6,0);
    LCD.print("SILAHKAN");
    LCD.setCursor(2,1);
    LCD.print("AMBIL PAKET ANDA");
    LCD.setCursor(1,2);
    LCD.print("LALU DORONG UNTUK");
    LCD.setCursor(0,3);
    LCD.print("TUTUP PINTU KEMBALI");
    
}

void lcd::done()
{
  LCD.clear();
  LCD.setCursor(0,2);
  LCD.print("    TERIMAKASIH");
  Serial.print(',');
  delay(2000);
  LCD.clear();
  LCD.setCursor(2,0);
  LCD.print("TUNGGU SEBENTAR");
  LCD.setCursor(1,1);
  LCD.print("PROSES SEBELUMNYA");
  LCD.setCursor(3,2);
  LCD.print("MASIH BERJALAN");
}

void lcd::thanks(){
    LCD.clear();
  LCD.setCursor(0,2);
  LCD.print("    TERIMAKASIH");
  Serial.print(',');
  delay(2000);
}

void lcd::put()
{
    LCD.clear();
    LCD.setCursor(2,0);
    LCD.print("SILAHKAN MASUKAN");
    LCD.setCursor(5,1);
    LCD.print("PAKET ANDA");
    LCD.setCursor(1,2);
    LCD.print("LALU DORONG UNTUK");
    LCD.setCursor(0,3);
    LCD.print("TUTUP PINTU KEMBALI");
    
}

void lcd::used()
{
    LCD.clear();
    LCD.setCursor(3,1);
    LCD.print("RESI PAKET INI");
    LCD.setCursor(3,2);
    LCD.print("TELAH TERPAKAI");
}

void lcd::failedPut()
{
    LCD.clear();
    LCD.setCursor(8,1);
    LCD.print("ERROR");
    LCD.setCursor(2,2);
    LCD.print("PAKET TIDAK ADA");
}

void lcd::resiType()
{
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("PILIH JASA PENGIRIM:");
    LCD.setCursor(0,1);
    LCD.print("--------------------");
    LCD.setCursor(0,2);
    LCD.print("A.J&T      B.SHOPEE");
    LCD.setCursor(0,3);
    LCD.print("C.LAINNYA  D.BATAL");
}

void lcd::finish()
{
    LCD.clear();
    LCD.setCursor(0,1);
    LCD.print("PROSES TELAH SELESAI");
}

void lcd::initAgainFail()
{
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("MOHON MAAF KAMERA");
    LCD.setCursor(0,1);
    LCD.print("SEDANG TIDAK DAPAT");
    LCD.setCursor(0,2);
    LCD.print("DIGUNAKAN SILAHKAN");
    LCD.setCursor(0,3);
    LCD.print("COBA INPUT MANUAL");
}

void lcd::pushUpDoor()
{
    
    LCD.clear();
    LCD.setCursor(6,0);
    LCD.print("SILAHKAN");
    LCD.setCursor(1,1);
    LCD.print("DORONG PINTU ATAS");
    LCD.setCursor(0,2);
    LCD.print("UNTUK MEMBUKA PINTU");
}

void lcd::pushDownDoor(){
    LCD.clear();
    LCD.setCursor(6,0);
    LCD.print("SILAHKAN");
    LCD.setCursor(0,1);
    LCD.print("DORONG PINTU BAWAH");
    LCD.setCursor(0,2);
    LCD.print("UNTUK MEMBUKA PINTU");
    
}

void lcd::checkWiFi(String ssid, String pass, String ip)
{
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("SSID:");
    LCD.print(ssid);
    LCD.setCursor(0,1);
    LCD.print("PASS:");
    LCD.print(pass);
    LCD.setCursor(0,2);
    LCD.print("IP:");
    LCD.print(ip);
    LCD.setCursor(0,3);
    LCD.print("A.CONF B.RST C.BACK");
}

void lcd::configRelay()
{
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("A.UP DOOR");
    LCD.setCursor(0,1);
    LCD.print("B.DOWN DOOR");
    LCD.setCursor(0,2);
    LCD.print("C.UP LED");
    LCD.setCursor(0,3);
    LCD.print("D.DOWN LED #.BACK");
}

void lcd::selectConfig()
{
    LCD.clear();
    LCD.setCursor(1,0);
    LCD.print("SELECT YOUR CONFIG");
    LCD.setCursor(0,1);
    LCD.print("--------------------");
    LCD.setCursor(0,2);
    LCD.print("A.RELAY    D.MOTOR");
    LCD.setCursor(0,3);
    LCD.print("B.SENSOR   C.BACK");
}

void lcd::configSensor(String upDoor, String downDoor, String closePartition, String openPartition, String ir, int i)
{
    if (i == 0)
    {
        LCD.clear();
        i++;
    }
    
    LCD.setCursor(0,0);
    LCD.print("UPDOOR:");
    LCD.print(upDoor);
    LCD.setCursor(0,1);
    LCD.print("DOWNDOOR:");
    LCD.print(downDoor);
    LCD.setCursor(0,2);
    LCD.print("CP:");
    LCD.print(closePartition);
    LCD.print("  ");
    LCD.print("OP:");
    LCD.print(openPartition);
    LCD.setCursor(0,3);
    LCD.print("IR:");
    LCD.print(ir);
    LCD.print("          C.BACK");
}

void lcd::configMotor()
{
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("A.STEPDOWN");
    LCD.setCursor(0,1);
    LCD.print("B.STEPUP");
    LCD.setCursor(0,2);
    LCD.print("C. STOP");
    LCD.setCursor(0,3);
    LCD.print("D. BACK");
}

void lcd::headKeyResi(){
    LCD.clear();
    LCD.setCursor(6,0);
    LCD.print("SILAHKAN");
    LCD.setCursor(1,1);
    LCD.print("MASUKAN RESI ANDA");
    LCD.setCursor(0,3);
    LCD.print("#.ENTER *.HAPUS C.<-");
    Serial.print('G');
}

void lcd::headKeyBarcode(){
    LCD.clear();
    LCD.setCursor(6,0);
    LCD.print("SILAHKAN");
    LCD.setCursor(1,1);
    LCD.print("MASUKAN KODE ANDA");
    LCD.setCursor(0,3);
    LCD.print("#.ENTER *.HAPUS C.<-");
}

void lcd::key(String data){
    LCD.setCursor(0,2);
    LCD.print(data);
}

void lcd::verifying(){
    LCD.clear();
    LCD.setCursor(2,1);
    LCD.print("TUNGGU SEBENTAR");
    LCD.setCursor(1,2);
    LCD.print("MEMVERIVIKASI DATA");
}

void lcd::empty(){
    LCD.clear();
    LCD.setCursor(0,1);
    LCD.print("PAKET ANDA TIDAK ADA");
    LCD.setCursor(0,2);
    LCD.print("  DI DALAM LOKER");
    Serial.print('.');
}

void lcd::noBarcode(){
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("BARCODE  PENGAMBILAN");
    LCD.setCursor(0,1);
    LCD.print("   ANDA TIDAK ADA");
    LCD.setCursor(0,2);
    LCD.print(" SILAHKAN MELAKUKAN");
    LCD.setCursor(0,3);
    LCD.print("REQUEST DI APLIKASI");
}