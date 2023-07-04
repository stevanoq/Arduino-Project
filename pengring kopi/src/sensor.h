#include <WString.h>

class LoadcellAtas
{
private:
    float units_atas;
    float ounces_atas;
    long zero_factor_atas;
    
    #define sc_atas 14
    #define data_atas 27

public:
    float  calibration_factor_atas = -414;
    void begin();
    float read(void);
};

class LoadcellBawah
{
private:
    float units_bawah;
    float ounces_bawah;
    long zero_factor_bawah;
    
    #define sc_bawah 13
    #define data_bawah 12

public:
    float calibration_factor_bawah = -414 ;
    void begin();
    float read(void);
};

class PZEM
{
private:
    #define PZEM_RX_PIN 16
    #define PZEM_TX_PIN 17
    #define PZEM_SERIAL Serial2
    #define CONSOLE_SERIAL Serial

    float voltage;
    float current;
    float power;
    float energy;
    float frequency;
    float pf;

public:
    void begin();
    float read(String args);
};

class dht
{
private:
    #define dhtPin 15
    #define dhtType DHT22
    float temperature;
    float humidity;

public:
    void begin();
    float read(String args);
};


