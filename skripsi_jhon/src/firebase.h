<<<<<<< HEAD
#ifndef FIREBAS_H
#define FIREBASE_H
#include <WString.h>

class firebase
{
private:
    String resi;
public:
    void init();
    void findResi(String resi);
    void findBarcode(String barcode);
    void updateStatus(bool state, String RESI);
    void updateLog(bool state, String action, String RESI, String check);
    void checkBBarcode(bool state);
    void deleteBarcode(bool state);
    void checkPackege(bool state);
    void deleteResi(bool state);
    bool state(void);
};

=======
#ifndef FIREBAS_H
#define FIREBASE_H
#include <WString.h>

class firebase
{
private:
    String resi;
public:
    void init();
    void findResi(String resi);
    void findBarcode(String barcode);
    void updateStatus(bool state, String RESI);
    void updateLog(bool state, String action, String RESI, String check);
    void checkBBarcode(bool state);
    void deleteBarcode(bool state);
    void checkPackege(bool state);
    void deleteResi(bool state);
    bool state(void);
};

>>>>>>> 9f4c145668b6fb6c7976d9e7904c2a03d2dd6554
#endif