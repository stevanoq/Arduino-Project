<<<<<<< HEAD
#ifndef USB_H
#define USB_H
#include <WString.h>
class usb
{
    private:
        bool reset = false;
        String result;
        bool back = false;
        bool INIT = true;
    public:
        void init();
        void initAgain(bool state);
        void task(bool state); 
        void Reset(bool reset);
        bool initAgain(void);
        bool usbBreak(void);
        String hasil(void);
};

=======
#ifndef USB_H
#define USB_H
#include <WString.h>
class usb
{
    private:
        bool reset = false;
        String result;
        bool back = false;
        bool INIT = true;
    public:
        void init();
        void initAgain(bool state);
        void task(bool state); 
        void Reset(bool reset);
        bool initAgain(void);
        bool usbBreak(void);
        String hasil(void);
};

>>>>>>> 9f4c145668b6fb6c7976d9e7904c2a03d2dd6554
#endif