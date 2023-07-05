<<<<<<< HEAD
#include "mykeypad.h"
#include "lcd.h"
#include "sensor.h"

LoadcellAtas la;
LoadcellBawah lb;
MonitorKanan lcd_r;
MonitorKiri lcd_l;

void MyKeypad::selectAction(bool state)
{
    lcd_l.selectAction();
    lcd_r.selectAction();
    while (state)
    {
        char key = this->keypad.getKey();
        if (key)
        {
            if (key == 'A')
            {
                this->mode = "setting";
                state = false;
            }
        }
    }
}

void MyKeypad::setting(float up, float down)
{
    lcd_l.sensor(up, down, 0,0);
    lcd_r.setting();
    char key1 = this->keypad.getKey();
    if (key1)
    {
        if (key1 == 'A')
        {
            this->UP = up;
            this->DOWN = down;
            this->mode = "start";
        }

        else if (key1 == 'B')
        {
            this->mode = "batal";
        }

        else if (key1 == 'C')
        {
            la.calibration_factor_atas+=5;
            Serial.print("LA = ");
            Serial.println(la.calibration_factor_atas);
        }

        else if (key1 == 'D')
        {
            la.calibration_factor_atas--;
            Serial.print("LA = ");
            Serial.println(la.calibration_factor_atas);
        }
        
        else if (key1 == 'E')
        {
            lb.calibration_factor_bawah+=5;
            Serial.print("LB = ");
            Serial.println(lb.calibration_factor_bawah);
        }
        
        else if (key1 == 'F')
        {
            lb.calibration_factor_bawah--;
            Serial.print("LB = ");
            Serial.println(lb.calibration_factor_bawah);
        }
        
    }
    
}

void MyKeypad::execute()
{
    char key2 = this->keypad.getKey();
    if (key2)
    {
        if (key2 == 'B')
        {
            this->mode = 'batal';
        }
    }
    
}

void MyKeypad::done(bool state)
{
    while (state)
    {
        char key3 = this->keypad.getKey();
        if (key3)
        {
            this->mode = "";
            state = false;
        }
    }
    
}
=======
#include "mykeypad.h"
#include "lcd.h"
#include "sensor.h"

LoadcellAtas la;
LoadcellBawah lb;
MonitorKanan lcd_r;
MonitorKiri lcd_l;

void MyKeypad::selectAction(bool state)
{
    lcd_l.selectAction();
    lcd_r.selectAction();
    while (state)
    {
        char key = this->keypad.getKey();
        if (key)
        {
            if (key == 'A')
            {
                this->mode = "setting";
                state = false;
            }
        }
    }
}

void MyKeypad::setting(float up, float down)
{
    lcd_l.sensor(up, down, 0,0);
    lcd_r.setting();
    char key1 = this->keypad.getKey();
    if (key1)
    {
        if (key1 == 'A')
        {
            this->UP = up;
            this->DOWN = down;
            this->mode = "start";
        }

        else if (key1 == 'B')
        {
            this->mode = "batal";
        }

        else if (key1 == 'C')
        {
            la.calibration_factor_atas+=5;
            Serial.print("LA = ");
            Serial.println(la.calibration_factor_atas);
        }

        else if (key1 == 'D')
        {
            la.calibration_factor_atas--;
            Serial.print("LA = ");
            Serial.println(la.calibration_factor_atas);
        }
        
        else if (key1 == 'E')
        {
            lb.calibration_factor_bawah+=5;
            Serial.print("LB = ");
            Serial.println(lb.calibration_factor_bawah);
        }
        
        else if (key1 == 'F')
        {
            lb.calibration_factor_bawah--;
            Serial.print("LB = ");
            Serial.println(lb.calibration_factor_bawah);
        }
        
    }
    
}

void MyKeypad::execute()
{
    char key2 = this->keypad.getKey();
    if (key2)
    {
        if (key2 == 'B')
        {
            this->mode = 'batal';
        }
    }
    
}

void MyKeypad::done(bool state)
{
    while (state)
    {
        char key3 = this->keypad.getKey();
        if (key3)
        {
            this->mode = "";
            state = false;
        }
    }
    
}
>>>>>>> 9f4c145668b6fb6c7976d9e7904c2a03d2dd6554
