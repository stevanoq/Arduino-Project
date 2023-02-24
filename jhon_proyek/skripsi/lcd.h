#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

class LCD{
  public: 
    void begin(){
        lcd.init();
        lcd.backlight();
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("Setting Up");
        lcd.setCursor(1,1);
        lcd.print("Smartbox System");
        delay(1000);
    }  

    void setOta(){
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("Starting OTA");
        lcd.setCursor(2,1);
        lcd.print("SUCCESSFULLY");
        delay(1000);
    }

    void updateOTA(){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("UPDATING SYSTEM");
    }

    void successUpdate(){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("SYSTEM UPDATED");
        delay(500);
    }

    void reboot(){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Rebooting System");
        delay(500);
    }

    void setFirebase(){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Firebase is Set");
        delay(1000);
    }
};