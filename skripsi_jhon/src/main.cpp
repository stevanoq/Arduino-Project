#include <Arduino.h>
#include <ota.h>
#include <usb.h>
#include <lcd.h>
#include <firebase.h>
#include <mykeypad.h>
#include <control.h>
#include <sensor.h>

#define resetArduinoPin 13

ota myota;
usb myusb;
lcd mylcd;
firebase myfire;
mykeypad keypads;
control mycontrol;
sensor mysensor;

String resi, action, mode, Code;
bool doorState, IR_STATE, SWITCH_UP_STATE, SWITCH_DOWN_STATE;
bool atcState, oldState = true;
bool ardu = false;
bool breakState = false;
bool Back = false;
bool usbBREAK = false;
bool modeSTATE;

int count;
int i;
int vo = 0;

void put();
void take();

void setup() {
  Serial.begin(115200);
  mylcd.init();
  delay(1000);
  myota.init(); 
  myfire.init();
  myusb.init();
  mysensor.init();
  pinMode(resetArduinoPin, OUTPUT);
  digitalWrite(resetArduinoPin, LOW);
  
  delay(1000);
  mylcd.succesInit();
  digitalWrite(resetArduinoPin, HIGH);
}

void loop() {
  i = 0;
  if (vo == 0)
  {
    delay(1000);
    // Serial.print('t');
    vo = 1;
  }
  
  atcState = true;
  mylcd.selectAction();
  keypads.selectAction(true);
  action = keypads.action();
  while (action == "ip")
  {
    action = keypads.action();
    if (i == 0)
    {
      myota.check();
      i++;
    }
    keypads.maintenance();
  }
  modeSTATE = keypads.modeState();
  mylcd.selectMode();
  keypads.selectMode(modeSTATE);
  mode = keypads.mode();
  atcState = keypads.MainState();

  while (action == "put" && atcState)
  {
    put();
  }

  while (action == "take" && atcState)
  {
    take();
  }

  mode = "";
  action = "";
  
}

void take(){
  myfire.checkBBarcode(true);

  if (!myfire.state())
  {
    mode = "";
  }
  
  while (mode == "scan")
  {
    
    if (!myusb.initAgain())
    {
      mylcd.initAgainFail();
      delay(4000);
      break;
    }
    
    myusb.task(true);
    usbBREAK = keypads.back();
    if (usbBREAK)
    {
      myusb.Reset(true);
      vo = 0;
      keypads.reset(true);
      Code = "";
      atcState = false;
      break;
    }
    Code = myusb.hasil();
    if (Code != "")
    {
      myfire.findBarcode(Code);
      myfire.deleteBarcode(true);
      myusb.Reset(true);
      
      mode = "";
      Code = "";
    }
    
  }

  while (mode == "key")
  {
    keypads.inputBarcode(true);
    Back = keypads.back();
    if (Back)
    {
      keypads.reset(true);
      vo = 0;
      keypads.reset(true);
      Code = "";
      atcState = false;
      break;
    }
    Code = keypads.result();
    if (Code != "")
    {
      myfire.findBarcode(Code);
      myfire.deleteBarcode(true);
      keypads.reset(true);
      mode = "";
      Code = "";
    }
  }

  if (myfire.state())
  {
    myfire.checkPackege(true);
  }
  
  doorState = myfire.state();

  while (doorState)
  { 
    SWITCH_DOWN_STATE = mysensor.switchDownVal();
   
    if (SWITCH_DOWN_STATE && count == 1)
    {
      mylcd.thanks();
      mycontrol.openDownDoor(false);
      mycontrol.ledDown(false);
      myfire.deleteResi(true);
      count = 0;
      break;
    }

    while (SWITCH_DOWN_STATE && count == 0)
    {
      SWITCH_DOWN_STATE = mysensor.switchDownVal();
      if (vo == 1)
      {
        Serial.print('`');
        vo = 2;
      }
      
       mylcd.pushDownDoor();
       mycontrol.openDownDoor(true);
       delay(1000);
    }

    while (!SWITCH_DOWN_STATE && count == 1)
    {
      SWITCH_DOWN_STATE = mysensor.switchDownVal();
      if (vo == 2)
      {
        Serial.print(">");
        vo = 3;
      }
      mycontrol.ledDown(true);
      mylcd.take();
      delay(1000);
    }

    if (oldState != SWITCH_DOWN_STATE)
    {
     count = 1;
    }
    
  }
  vo = 0;
  keypads.reset(true);
  Code = "";
  atcState = false;
}

void put(){
  while (mode == "scan")
  {
    if (!myusb.initAgain())
    {
      mylcd.initAgainFail();
      delay(2000);
      break;
    }
    myusb.task(true);
    usbBREAK = myusb.usbBreak();
    if (usbBREAK)
    {
      myusb.Reset(true);
      vo = 0;
      keypads.reset(true);
      Code = "";
      atcState = false;
      break;
    }
    
    resi = myusb.hasil();
    if (resi != "")
    {
      myfire.findResi(resi);
      myusb.Reset(true);
      mode = "";
    }
    
  }

  while (mode == "key")
  {
    keypads.selectResiType(true);
    Back = keypads.back();
    if (Back)
    {
      keypads.reset(true);
      vo = 0;
      keypads.reset(true);
      Code = "";
      atcState = false;
      break;
    }
    keypads.inputResi(true);
    resi = keypads.result();
    if (resi != "")
    {
      myfire.findResi(resi);
      mode = "";
    }
  }

  doorState = myfire.state();
  while (doorState)
  {
    IR_STATE = mysensor.irVal();
    SWITCH_UP_STATE = mysensor.switchUpVal();
    if (SWITCH_UP_STATE && count == 1)
    {
      mycontrol.openUpDoor(false);
      mycontrol.ledUp(false);
      if (IR_STATE)
      { 
        mylcd.done();
        mycontrol.motor(true);
        myfire.updateStatus(true, resi);
        count = 0;
        ardu = true;
      }

      else
      {
        myfire.updateStatus(false, resi);
        myfire.updateLog(true, "TITIP", resi, "PAKET TIDAK TERDETEKSI");
        count = 0;
        break;
      }

      while (ardu)
      {
        char arData;
        if (Serial.available())
        {
          arData = Serial.read();
          if (arData == '?')
          {
            // Serial.println(arData);
            mycontrol.motor(false);
            delay(1000);
            mylcd.finish();
            arData = '-';
            breakState = true;
            delay(1000);
            break;
          }
        }
      }

      if (breakState)
      {
        breakState = false;
        break;
      }
      
    }

    while (SWITCH_UP_STATE && count == 0)
    {
      SWITCH_UP_STATE = mysensor.switchUpVal();
      if (vo == 1)
      {
        Serial.print('F');
        vo = 2;
      }
      
      mylcd.pushUpDoor();
      mycontrol.openUpDoor(true);
      delay(1000);
    }

    while (!SWITCH_UP_STATE && count == 1)
    {
      SWITCH_UP_STATE = mysensor.switchUpVal();
      if (vo == 2)
      {
        Serial.print('{');
        vo = 3;
      }
      
      mylcd.put();
      mycontrol.ledUp(true);
      delay(1000);
    }

    if (oldState != SWITCH_UP_STATE)
    {
      count = 1;
    }
  }
  vo = 0;
  keypads.reset(true);
  resi = "";
  atcState = false;
  
}
