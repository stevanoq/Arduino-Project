#include <usbhid.h>
#include <hiduniversal.h>
#include <Usb.h>
#include <usbhub.h>
#include <hidboot.h>
#include <lcd.h>
#include <mykeypad.h>
#include "usb.h"

lcd Mylcd;
mykeypad pad;
USB Usb;
USBHub hub(&Usb);
HIDUniversal Hid(&Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD> Keyboard(&Usb);
String Result;
bool x = false;
bool t = false;

class KbdRptParser : public KeyboardReportParser
{
    void PrintKey(uint8_t mod, uint8_t key);
  protected:
    virtual void OnKeyDown  (uint8_t mod, uint8_t key);
    virtual void OnKeyPressed(uint8_t key);
};

void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
  uint8_t c = OemToAscii(mod, key);

  if (c)
    OnKeyPressed(c);
}

/* what to do when symbol arrives */
unsigned char n_char[7];
unsigned char  i_n = 0;

void led_on();
void led_off();
void led_on_all();

unsigned char border;
void KbdRptParser::OnKeyPressed(uint8_t key)
{
    // Serial.println(key);
    // Serial.print((char) key);
    if(key == 13){
        x = true;
        t = false;
        Mylcd.textResult(Result);
        delay(1000);
    }
    else{
        Result += char(key);
    }
};

KbdRptParser Prs;

void usb::init(){
    if (Usb.Init() == -1)
    {
        ESP.restart();
    }
    
    delay( 200 );

    Hid.SetReportParser(0, (HIDReportParser*)&Prs);
    
    delay( 200 );
}

void usb::task(bool state){
    t = state;
    Serial.print('R');
    delay(2000);
    while (t)
    {
        Usb.Task();
        pad.USBKEYPAD();
        Serial.print('c');
        if (pad.back())
        {
            Serial.print('C');
            this->back = true;
            break;
        }
    }
}

void usb::Reset(bool reset){
    this->reset = reset;
    if (x && this->reset)
    {
        Serial.print('C');
        x = false;
        t = false;
        this->reset = false;
        Result = "";
        this->result = "";
    }
}

bool usb::initAgain(void)
{
    if (Usb.Init() == -1)
    {
        // Serial.print("fail");
        this->INIT = false;
    }

    else
    {
        // Serial.print("succes");
        this->INIT = true;
    }
    
    delay( 200 );

    Hid.SetReportParser(0, (HIDReportParser*)&Prs);
    
    delay( 200 );

    return this->INIT;
}

bool usb::usbBreak(void)
{
    return this->back;
}

String usb::hasil(void){
    if (x)
    {
        this->result = Result;
    }
    return this->result;
}