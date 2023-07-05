<<<<<<< HEAD
#ifndef MYKEYPAD_H
#define MYKEYPAD_H
#include <WString.h>

class mykeypad
{
private:
    String resi;
    String mod;
    String act;
public:
    void selectAction(bool state);
    void reset(bool res);
    void resetState(bool state);
    void inputResi(bool state);
    void inputBarcode(bool state);
    void selectMode(bool state);
    void selectResiType(bool state);
    void maintenance();
    void USBKEYPAD();
    bool back(void);
    bool MainState(void);
    bool modeState(void);
    String result(void);
    String mode(void);
    String action(void);
};



=======
#ifndef MYKEYPAD_H
#define MYKEYPAD_H
#include <WString.h>

class mykeypad
{
private:
    String resi;
    String mod;
    String act;
public:
    void selectAction(bool state);
    void reset(bool res);
    void resetState(bool state);
    void inputResi(bool state);
    void inputBarcode(bool state);
    void selectMode(bool state);
    void selectResiType(bool state);
    void maintenance();
    void USBKEYPAD();
    bool back(void);
    bool MainState(void);
    bool modeState(void);
    String result(void);
    String mode(void);
    String action(void);
};



>>>>>>> 9f4c145668b6fb6c7976d9e7904c2a03d2dd6554
#endif