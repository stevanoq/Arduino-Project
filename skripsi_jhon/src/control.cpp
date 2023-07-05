<<<<<<< HEAD
#include <Arduino.h>
#include "control.h"

void control::openUpDoor(bool state)
{
    if (state)
    {
        Serial.print('U');
    }

    else
    {
        Serial.print('u');
    }
}

void control::openDownDoor(bool state)
{
    if (state)
    {
        Serial.print('D');
    }
    
    else
    {
        Serial.print('d');
    }
}

void control::ledDown(bool state)
{
    if (state)
    {
        Serial.print('L');
    }

    else
    {
        Serial.print('l');
    }
}

void control::ledUp(bool state)
{
    if (state)
    {
        Serial.print('Q');
    }

    else
    {
        Serial.print('q');
    }
}

void control::motor(bool state)
{
    if (state)
    {
        Serial.print('M');
    }

    else
    {
        Serial.print("!");
    }
}
=======
#include <Arduino.h>
#include "control.h"

void control::openUpDoor(bool state)
{
    if (state)
    {
        Serial.print('U');
    }

    else
    {
        Serial.print('u');
    }
}

void control::openDownDoor(bool state)
{
    if (state)
    {
        Serial.print('D');
    }
    
    else
    {
        Serial.print('d');
    }
}

void control::ledDown(bool state)
{
    if (state)
    {
        Serial.print('L');
    }

    else
    {
        Serial.print('l');
    }
}

void control::ledUp(bool state)
{
    if (state)
    {
        Serial.print('Q');
    }

    else
    {
        Serial.print('q');
    }
}

void control::motor(bool state)
{
    if (state)
    {
        Serial.print('M');
    }

    else
    {
        Serial.print("!");
    }
}
>>>>>>> 9f4c145668b6fb6c7976d9e7904c2a03d2dd6554
