<<<<<<< HEAD
#ifndef LCD_H
#define LCD_H
#include <WString.h>
class lcd
{
private:
    String data;
public:
    void init();
    void selectAction();
    void selectMode();
    void scan(bool state);
    void headKeyResi();
    void headKeyBarcode();
    void verifying();
    void empty();
    void noBarcode();
    void key(String data);
    void textResult(String data);
    void connectWiFi();
    void connectFirebase();
    void succesInit();
    void statrtingOta();
    void verified();
    void unverified();
    void take();
    void done();
    void thanks();
    void put();
    void used();
    void failedPut();
    void resiType();
    void finish();
    void initAgainFail();
    void pushUpDoor();
    void pushDownDoor();
    void checkWiFi(String ssid, String pass, String ip);
    void configRelay();
    void selectConfig();
    void configSensor(String upDoor, String downDoor, String closePartition, String openPartition, String ir, int i);
    void configMotor();
};

=======
#ifndef LCD_H
#define LCD_H
#include <WString.h>
class lcd
{
private:
    String data;
public:
    void init();
    void selectAction();
    void selectMode();
    void scan(bool state);
    void headKeyResi();
    void headKeyBarcode();
    void verifying();
    void empty();
    void noBarcode();
    void key(String data);
    void textResult(String data);
    void connectWiFi();
    void connectFirebase();
    void succesInit();
    void statrtingOta();
    void verified();
    void unverified();
    void take();
    void done();
    void thanks();
    void put();
    void used();
    void failedPut();
    void resiType();
    void finish();
    void initAgainFail();
    void pushUpDoor();
    void pushDownDoor();
    void checkWiFi(String ssid, String pass, String ip);
    void configRelay();
    void selectConfig();
    void configSensor(String upDoor, String downDoor, String closePartition, String openPartition, String ir, int i);
    void configMotor();
};

>>>>>>> 9f4c145668b6fb6c7976d9e7904c2a03d2dd6554
#endif