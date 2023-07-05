<<<<<<< HEAD
#include <Arduino.h>
#include "sensor.h"
#include "lcd.h"

#define irPin 33
#define switchDown 32
#define switchUp 16

int irValue;
int switchDownValue;
int switchUpValue;

bool irState;
bool switchUpState;
bool switchDownState;

void sensor::init()
{
    pinMode(irPin, INPUT);
    pinMode(switchUp, INPUT_PULLUP);
    pinMode(switchDown, INPUT_PULLUP);
}

bool sensor::irVal(void)
{
    irValue = digitalRead(irPin);
    if (irValue == 1)
    {
        irState = false;
    }

    else
    {
        irState = true;
    }
    
    return irState;
}

bool sensor::switchUpVal(void)
{
    switchUpValue = digitalRead(switchUp);
    if (switchUpValue == 1)
    {
        switchUpState = false;
    }

    else
    {
        switchUpState = true;
    }
    
    return switchUpState;
}

bool sensor::switchDownVal(void)
{
    switchDownValue = digitalRead(switchDown);
    if (switchDownValue == 1)
    {
        switchDownState = false;
    }

    else
    {
        switchDownState = true;
    }
    
    return switchDownState;
}
=======
#include <Arduino.h>
#include "sensor.h"
#include "lcd.h"

#define irPin 33
#define switchDown 32
#define switchUp 16

int irValue;
int switchDownValue;
int switchUpValue;

bool irState;
bool switchUpState;
bool switchDownState;

void sensor::init()
{
    pinMode(irPin, INPUT);
    pinMode(switchUp, INPUT_PULLUP);
    pinMode(switchDown, INPUT_PULLUP);
}

bool sensor::irVal(void)
{
    irValue = digitalRead(irPin);
    if (irValue == 1)
    {
        irState = false;
    }

    else
    {
        irState = true;
    }
    
    return irState;
}

bool sensor::switchUpVal(void)
{
    switchUpValue = digitalRead(switchUp);
    if (switchUpValue == 1)
    {
        switchUpState = false;
    }

    else
    {
        switchUpState = true;
    }
    
    return switchUpState;
}

bool sensor::switchDownVal(void)
{
    switchDownValue = digitalRead(switchDown);
    if (switchDownValue == 1)
    {
        switchDownState = false;
    }

    else
    {
        switchDownState = true;
    }
    
    return switchDownState;
}
>>>>>>> 9f4c145668b6fb6c7976d9e7904c2a03d2dd6554
