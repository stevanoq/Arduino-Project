#include <usbhid.h>
#include <hiduniversal.h>
#include <Usb.h>
#include <usbhub.h>
#include <hidboot.h>

USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD> Keyboard(&Usb);
String result;
bool x = false;
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
  Serial.println(key);
  Serial.print((char) key);
//  if(key == 0){
//    x = true;
//  }
//  else{
//    result += char(key);
//  }
};

KbdRptParser Prs;

void setup()
{
  Serial.begin( 115200 );
  delay(1000);
  
  

  if (Usb.Init() == -1)
  {
    Serial.println("OSC did not start.");
  }

  delay( 200 );

  Hid.SetReportParser(0, (HIDReportParser*)&Prs);
  
  delay( 200 );
}

void loop()
{
  Usb.Task();
  if(x){
    Serial.println("Result : " + (String)result);
    x = false;
    result = "";
  }
  
}
