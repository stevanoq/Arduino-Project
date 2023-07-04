#include <Arduino.h>
#include <Keypad.h>
#include <WString.h>

class MyKeypad
{
private:
    char keys[2][3] = {
        {'E', 'C', 'A'},
        {'F', 'D', 'B'}
    };

    byte pin_cols[3] = {26,25,33};
    byte pin_rows[2] = {5,18};
    Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_cols, 2, 3);
    
public:
    void selectAction(bool state);
    void setting(float up, float down);
    void execute();
    void done(bool state);
    float UP;
    float DOWN;
    String mode;
};
