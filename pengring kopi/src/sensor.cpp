#include "HX711.h"
#include <PZEM004Tv30.h>
#include "DHT.h"
#include "sensor.h"

HX711 scale_atas;
HX711 scale_bawah;

PZEM004Tv30 pzem(PZEM_SERIAL, PZEM_RX_PIN, PZEM_TX_PIN);

DHT dht_sen(dhtPin,dhtType);

void LoadcellAtas::begin()
{
    scale_atas.begin(sc_atas, data_atas);
    scale_atas.set_scale();
    delay(1000);
    scale_atas.tare();
    this->zero_factor_atas = scale_atas.read_average();
}

float LoadcellAtas::read(void)
{
    scale_atas.set_scale(this->calibration_factor_atas);
    this->units_atas = scale_atas.get_units(), 0;
    if (this->units_atas < 0)
    {
        this->units_atas = 0.00;
    }

    this->ounces_atas = this->units_atas * 0.035274;

    return this->units_atas;
}

void LoadcellBawah::begin()
{
    scale_bawah.begin(sc_bawah,data_bawah);
    scale_bawah.set_scale();
    delay(1000);
    scale_bawah.tare();
    this->zero_factor_bawah = scale_bawah.read_average();
}

float LoadcellBawah::read(void)
{
    scale_bawah.set_scale(this->calibration_factor_bawah);
    this->units_bawah = scale_bawah.get_units(), 0;
    if (this->units_bawah < 0)
    {
        this->units_bawah = 0.00;
    }
    this->ounces_bawah = this->units_bawah * 0.035274;
    return this->units_bawah;
}

void PZEM::begin()
{
    CONSOLE_SERIAL.begin(115200);
}

float PZEM::read(String args)
{
    this->voltage = pzem.voltage();
    this->current = pzem.current();
    this->power = pzem.power();
    this->frequency = pzem.frequency();
    this->energy = pzem.energy();
    this->pf = pzem.pf();

    if (args == "volt")
    {
        return this->voltage;
    }
    
    else if (args == "current")
    {
        return this->current;
    }

    else if (args == "power")
    {
        return this->power;
    }
    
    else if (args == "energy")
    {
        return this->energy;
    }
    
}

void dht::begin()
{
    dht_sen.begin();
    
}

float dht::read(String args)
{
    this->temperature = dht_sen.readTemperature();
    this->humidity = dht_sen.readHumidity();
    if (args == "temp")
    {
        return this->temperature;
    }
    
    else if (args == "humy")
    {
        return this->humidity;
    }
}
