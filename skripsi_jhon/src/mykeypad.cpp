#include <Keypad.h>
#include <Arduino.h>
#include "mykeypad.h"
#include "lcd.h"
#include "control.h"
#include "sensor.h"

const int ROW_NUM    = 4;
const int COLUMN_NUM = 4;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

lcd MYLcd;
control con;
sensor sens;
String hasil, ACT, MOD, fixHasil, type, confStr;
String upVal, downVal, cpVal, opVal, irVal;
bool check = false;
bool mainSatate = true;
bool BACK;
bool modStates = true;
bool RELAY;
bool CONF;
bool SENSOR;
bool UPval;
bool DOWNval;
bool IRval;
bool MOTOR;
byte pin_rows[ROW_NUM]      = {4,0,2,15};
byte pin_column[COLUMN_NUM] = {25,26,27,14}; 

int p,q,r,g,u;

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

void mykeypad::selectAction(bool state){
    while (state)
    {
        char key = keypad.getKey();
        if (key)
        {
            
            if (key == 'A')
            {
                mainSatate = true;
                ACT = "take";
                state = false;
                modStates = true;
            }

            else if (key == 'B')
            {
                mainSatate = true;
                ACT = "put";
                state = false;
                modStates = true;
            }

            else if (key == '#')
            {
                mainSatate = true;
                ACT = "ip";
                state = false;
            }
        }
    }
}

void mykeypad::selectMode(bool state)
{
    while (state)
    {
        char key = keypad.getKey();
        if (key){
            if (key == 'A')
            {
                MOD = "scan";
                state = false;
                
                MYLcd.scan(true);
            }

            else if (key == 'B')
            {
                MOD = "key";
                state = false;
            }

            else if (key == 'C')
            {
                state = false;
                BACK = true;
            }
        }
        
    }
}

void mykeypad::selectResiType(bool state)
{
    MYLcd.resiType();
    while (state)
    {
        BACK = false;
        char key = keypad.getKey();
        if (key)
        {
            BACK = false;
            if (key == 'A')
            {
                hasil = "JP";
                state = false;
            }

            else if (key == 'B')
            {
                hasil = "SPXID";
                state = false;
            }

            else if (key == 'C')
            {
                hasil = "";
                state = false;
            }

            else if (key == 'D')
            {
                BACK = true;
                state = false;
            }
        }
    }
    
}

void mykeypad::maintenance()
{
    p = 0;
    q = 0;
    r = 0;
    g = 0;
    u = 0;
    char key = keypad.getKey();
    if (key)
    {
        if (key == 'A')
        {
            CONF = true;
            modStates = false;
        }

        else if (key == 'B')
        {
            ESP.restart();
        }
        
        else if (key == 'C')
        {
            ACT = "1";
            modStates = false;
        }
    }

    while (CONF)
    {
        if (q == 0)
        {
            MYLcd.selectConfig();
            q++;
        }
        
        char key2 = keypad.getKey();
        if (key2)
        {
            if (key2 == 'A')
            {
                RELAY = true;
                CONF = false;
                break;
            }
            
            else if (key2 == 'B')
            {
                SENSOR = true;
                CONF = false;
                break;
            }

            else if(key2 == 'C'){
                ACT = "1";
                modStates = false;
                CONF = false;
                break;
            }
            else if (key2 == 'D')
            {
                MOTOR = true;
                CONF = false;
                break;
            }
            
        }
    }
    

    while (RELAY)
    {
        if (p == 0)
        {
            MYLcd.configRelay();
            p++;
        }
       
        char key1 = keypad.getKey();
        if (key1)
        {
            if (key1 == 'A')
            {
                for (size_t i = 0; i < 3; i++)
                {
                    con.openUpDoor(true);
                    delay(500);
                    con.openUpDoor(false);
                    delay(500);
                }
            }

            else if (key1 == 'B')
            {
                for (size_t i = 0; i < 3; i++)
                {
                    con.openDownDoor(true);
                    delay(500);
                    con.openDownDoor(false);
                    delay(500);
                }
            }

            else if (key1 == 'C')
            {
                for (size_t i = 0; i < 3; i++)
                {
                    con.ledUp(true);
                    delay(500);
                    con.ledUp(false);
                    delay(500);
                }
            }

            else if (key1 == 'D')
            {
                for (size_t i = 0; i < 3; i++)
                {
                    con.ledDown(true);
                    delay(500);
                    con.ledDown(false);
                    delay(500);
                }
            }

            else if (key1 == '#')
            {
              ACT = "1";
              modStates = false;
              RELAY = false; 
            }
        }
        
    }
    
    while (SENSOR)
    {
        
        char key3 = keypad.getKey();
        if (key3)
        {
            if (key3 == 'C')
            {
                SENSOR = false;
                ACT = "1";
                modStates = false;
                Serial.print('[');
            }
        }
        

        if (Serial.available() > 0)
        {
            char data = Serial.read();
            if (data == '.')
            {
               opVal = "F";
            }

            else if (data == ',')
            {
                opVal = 'N';
            }
            
            else if (data == '+')
            {
                cpVal = 'F';
            }

            else if (data == '=')
            {
                cpVal = 'N';
            }
            
        }
        UPval = sens.switchUpVal();
        DOWNval = sens.switchDownVal();
        IRval = sens.irVal();
        if (UPval)
        {
            upVal = "N";
        }

        if (!UPval)
        {
            upVal = "F";
        }

        if (DOWNval)
        {
            downVal = "N";
        }

        if (!DOWNval)
        {
            downVal = "F";
        }

        if (IRval)
        {
            irVal = "N";
        }

        if(!IRval)
        {
            irVal = "F";
        }
        
        if (g == 0)
        {
            Serial.print("]");
            MYLcd.configSensor(upVal,downVal,cpVal,opVal,irVal, g);
            g++;
        }
        
        MYLcd.configSensor(upVal,downVal,cpVal,opVal,irVal, g);
    }
    
    while (MOTOR)
    {
        if (u == 0)
        {
            MYLcd.configMotor();
            u++;
        }

        char key4 = keypad.getKey();
        if (key4)
        {
            if (key4 == 'A')
            {
                Serial.print("@");
            }
            
            else if (key4 == 'B')
            {
                Serial.print("^");
            }
            
            else if (key4 == 'C')
            {
                Serial.print("*");
            }

            else if (key4 == '*')
            {
                Serial.print("<");
            }

            else if (key4 == '#')
            {
                Serial.print('>');
            }
            

            else
            {
                MOTOR = false;
                ACT = "1";
                modStates = false;
                Serial.print('*');
            }
            
        }
        
    }
    
}

void mykeypad::USBKEYPAD()
{
    char key = keypad.getKey();
    BACK = false;
    if (key)
    { 
        if (key == 'C')
        {
          BACK = true;   
        }

        else if (key == 'A')
        {
            Serial.print('C');
            delay(100);
            Serial.print('c');
        }
    }
    
}

bool mykeypad::back(void)
{
    return BACK;
}

bool mykeypad::MainState(void)
{
    return mainSatate;
}

bool mykeypad::modeState(void)
{
    return modStates;
}

void mykeypad::reset(bool res){
    if (res)
    {
        hasil = "";
        fixHasil = "";
        this->resi = "";
        res = false;
        check = false;
    }
}

void mykeypad::resetState(bool state){
    if (state)
    {
        MOD = "";
        ACT = "";
        state = false;
    }
    
}

void mykeypad::inputResi(bool state){
    MYLcd.headKeyResi();
    while (state)
    {
        char key = keypad.getKey();
        if (key)
        {
            MYLcd.key(String(key));
            if (key == '*')
            {
                fixHasil = "";
                MYLcd.headKeyResi();
            }

            else if (key == '#')
            {
                check = true;
                state = false;
            }

            else if (key == 'C')
            {
                state = false;
                BACK = true;
            }
            
            else
            {
                fixHasil += key;
                MYLcd.key(hasil + fixHasil);
            }
        }
    }
}

void mykeypad::inputBarcode(bool state)
{
    BACK = false;
    MYLcd.headKeyBarcode();
    while (state)
    {
        char key = keypad.getKey();
        if (key)
        {
            MYLcd.key(String(key));
            if (key == '*')
            {
                fixHasil = "";
                MYLcd.headKeyBarcode();
            }

            else if (key == '#')
            {
                check = true;
                state = false;
            }

            else if (key == 'C')
            {
                BACK = true;
                state = false;
            }
            
            else
            {
                fixHasil += key;
                MYLcd.key(fixHasil);
            }
        }
    }
}

String mykeypad::result(void){
    if (check)
    {
        if (hasil != "")
        {
            this->resi = hasil + fixHasil;
        }
        
        else
        {
            this->resi = fixHasil;
        }
    }
    return this->resi;
}

String mykeypad::action(void){
    if (ACT != "")
    {
        this->act = ACT;
    }
    return this->act;
}

String mykeypad::mode(void){
    if (MOD != "")
    {
        this->mod = MOD;
    }
    return this->mod;
}