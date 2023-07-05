<<<<<<< HEAD
#include <Arduino.h>
#include <sensor.h>
#include <lcd.h>
#include <mykeypad.h>
#include <mynetwork.h>

LoadcellAtas lc_atas;
LoadcellBawah lc_bawah;
PZEM pzem_sensor;
dht DHT;
MonitorKanan lcd_kanan;
MonitorKiri lcd_kiri;
MyKeypad keypads;
ota myOta;
myfirebase fire;

#define fan 2
#define heater1 4
#define heater2 23

float lc_up_value;
float lc_down_value;
int presentance_up;
int presentance_down;
int TIME;
bool state = true;
bool state1 = true;

void serialMonitor();

void setup(){
    lcd_kanan.begin();
    lcd_kiri.begin();
    myOta.begin();
    fire.begin();
    Serial.begin(115200);
    lc_atas.begin();
    lc_bawah.begin();
    pzem_sensor.begin();
    DHT.begin();
    pinMode(fan, OUTPUT);
    pinMode(heater1, OUTPUT);
    pinMode(heater2, OUTPUT);
    digitalWrite(fan, HIGH);
    digitalWrite(heater1, HIGH);
    digitalWrite(heater2, HIGH);
}

void loop(){
    digitalWrite(fan, HIGH);
    digitalWrite(heater1, HIGH);
    digitalWrite(heater2, HIGH);
    keypads.selectAction(true);

    while (keypads.mode == "setting")
    {
        if (state1)
        {
            fire.send("time/endTime", "-");
            fire.send("loadUp/status","Proses");
            fire.send("loadDown/status","Proses");
            state1 = false;
        }
        
        digitalWrite(fan, HIGH);
        digitalWrite(heater1, HIGH);
        digitalWrite(heater2, LOW);
        lc_up_value = lc_atas.read();
        lc_down_value = lc_bawah.read();
        keypads.setting(lc_up_value, lc_down_value);
        // delay(500);
    }

    while (keypads.mode == "start")
    {
        float estimation;
        digitalWrite(fan, LOW);
        if (DHT.read("temp") >= 55)
        {
            digitalWrite(heater1, HIGH);
        }

        else if (DHT.read("temp") <= 50)
        {
            digitalWrite(heater1, LOW);
        }
        
        keypads.execute();
        lc_up_value = lc_atas.read();
        lc_down_value = lc_bawah.read();
        presentance_up = ((keypads.UP-lc_up_value)/keypads.UP)*100;
        presentance_down = ((keypads.DOWN-lc_down_value)/keypads.DOWN)*100;
        lcd_kiri.sensor(lc_up_value, lc_down_value, presentance_up, presentance_down);
        lcd_kanan.sensor(DHT.read("temp"),DHT.read("humy"), pzem_sensor.read("volt"), pzem_sensor.read("current"));
        
        if (TIME == 10)
        {
            fire.send("loadUp/value", String(lc_up_value));
            fire.send("loadDown/value", String(lc_down_value));
            fire.send("dht/temp", String(DHT.read("temp")));
            fire.send("dht/humi", String(DHT.read("humy")));
            fire.send("pzem/voltage", String(pzem_sensor.read("volt")));
            fire.send("pzem/current", String(pzem_sensor.read("current")));
            fire.send("pzem/energy", String(pzem_sensor.read("energy")));
            fire.send("pzem/power", String(pzem_sensor.read("power")));
            TIME = 0;
        }

        if (state)
        {
            fire.send_time("startTime");
            fire.send("loadUp/value", String(lc_up_value));
            fire.send("loadDown/value", String(lc_down_value));
            fire.send("dht/temp", String(DHT.read("temp")));
            fire.send("dht/humi", String(DHT.read("humy")));
            fire.send("pzem/voltage", String(pzem_sensor.read("volt")));
            fire.send("pzem/current", String(pzem_sensor.read("current")));
            fire.send("pzem/energy", String(pzem_sensor.read("energy")));
            fire.send("pzem/power", String(pzem_sensor.read("power")));
            state = false;
        }
        
        
        if (presentance_up >= 20 && fire.count == 0)
        {
            Serial.println("update atas");
            fire.send("loadUp/status","Selesai");
            fire.count = 1;
        }

        else if (presentance_down >= 20 && fire.count == 1)
        {
            Serial.println("update bawah");
            fire.send("loadDown/status","Selesai");
            fire.count = 2;
        }
        
        else if (presentance_up >= 20 && presentance_down >= 20 && fire.count == 2)
        {
            fire.send_time("endTime");
            Serial.println("selesai");
            
            fire.get_time("start");
            fire.get_time("end");
            estimation = (fire.TIME2 - fire.TIME1) * pzem_sensor.read("energy")*1500;
            fire.send("estimation", String(estimation));
            digitalWrite(fan, HIGH);
            digitalWrite(heater1, HIGH);
            digitalWrite(heater2, HIGH);
            delay(100);
            lcd_kanan.done();
            lcd_kiri.done();
            fire.count = 0;
            keypads.mode = "selesai";
            state = true;
            state1 = true;
        }
        TIME ++;
        delay(500);
    }
    
    keypads.done(true);
    
}

void serialMonitor(){
    Serial.print("Up value = ");
    Serial.print(lc_up_value, 0);
    Serial.print(" grams || ");
    Serial.print("Down value = ");
    Serial.print(lc_down_value, 0);
    Serial.print(" grams");
    Serial.print(" || voltage = ");
    Serial.print(pzem_sensor.read("volt"));
    Serial.print("V");
    Serial.print(" || current = ");
    Serial.print(pzem_sensor.read("current"));
    Serial.print("A");
    Serial.print(" || power = ");
    Serial.print(pzem_sensor.read("power"));
    Serial.print("W");
    Serial.print(" || energy = ");
    Serial.print(pzem_sensor.read("energy"), 3);
    Serial.print("kWh");
    Serial.print(" || suhu = ");
    Serial.print(DHT.read("temp"));
    Serial.print("C");
    Serial.print(" || kelembaban = ");
    Serial.print(DHT.read("humy"));
    Serial.print("%");
    Serial.println();
=======
#include <Arduino.h>
#include <sensor.h>
#include <lcd.h>
#include <mykeypad.h>
#include <mynetwork.h>

LoadcellAtas lc_atas;
LoadcellBawah lc_bawah;
PZEM pzem_sensor;
dht DHT;
MonitorKanan lcd_kanan;
MonitorKiri lcd_kiri;
MyKeypad keypads;
ota myOta;
myfirebase fire;

#define fan 2
#define heater1 4
#define heater2 23

float lc_up_value;
float lc_down_value;
int presentance_up;
int presentance_down;
int TIME;
bool state = true;
bool state1 = true;

void serialMonitor();

void setup(){
    lcd_kanan.begin();
    lcd_kiri.begin();
    myOta.begin();
    fire.begin();
    Serial.begin(115200);
    lc_atas.begin();
    lc_bawah.begin();
    pzem_sensor.begin();
    DHT.begin();
    pinMode(fan, OUTPUT);
    pinMode(heater1, OUTPUT);
    pinMode(heater2, OUTPUT);
    digitalWrite(fan, HIGH);
    digitalWrite(heater1, HIGH);
    digitalWrite(heater2, HIGH);
}

void loop(){
    digitalWrite(fan, HIGH);
    digitalWrite(heater1, HIGH);
    digitalWrite(heater2, HIGH);
    keypads.selectAction(true);

    while (keypads.mode == "setting")
    {
        if (state1)
        {
            fire.send("time/endTime", "-");
            fire.send("loadUp/status","Proses");
            fire.send("loadDown/status","Proses");
            state1 = false;
        }
        
        digitalWrite(fan, HIGH);
        digitalWrite(heater1, HIGH);
        digitalWrite(heater2, LOW);
        lc_up_value = lc_atas.read();
        lc_down_value = lc_bawah.read();
        keypads.setting(lc_up_value, lc_down_value);
        // delay(500);
    }

    while (keypads.mode == "start")
    {
        float estimation;
        digitalWrite(fan, LOW);
        if (DHT.read("temp") >= 55)
        {
            digitalWrite(heater1, HIGH);
        }

        else if (DHT.read("temp") <= 50)
        {
            digitalWrite(heater1, LOW);
        }
        
        keypads.execute();
        lc_up_value = lc_atas.read();
        lc_down_value = lc_bawah.read();
        presentance_up = ((keypads.UP-lc_up_value)/keypads.UP)*100;
        presentance_down = ((keypads.DOWN-lc_down_value)/keypads.DOWN)*100;
        lcd_kiri.sensor(lc_up_value, lc_down_value, presentance_up, presentance_down);
        lcd_kanan.sensor(DHT.read("temp"),DHT.read("humy"), pzem_sensor.read("volt"), pzem_sensor.read("current"));
        
        if (TIME == 10)
        {
            fire.send("loadUp/value", String(lc_up_value));
            fire.send("loadDown/value", String(lc_down_value));
            fire.send("dht/temp", String(DHT.read("temp")));
            fire.send("dht/humi", String(DHT.read("humy")));
            fire.send("pzem/voltage", String(pzem_sensor.read("volt")));
            fire.send("pzem/current", String(pzem_sensor.read("current")));
            fire.send("pzem/energy", String(pzem_sensor.read("energy")));
            fire.send("pzem/power", String(pzem_sensor.read("power")));
            TIME = 0;
        }

        if (state)
        {
            fire.send_time("startTime");
            fire.send("loadUp/value", String(lc_up_value));
            fire.send("loadDown/value", String(lc_down_value));
            fire.send("dht/temp", String(DHT.read("temp")));
            fire.send("dht/humi", String(DHT.read("humy")));
            fire.send("pzem/voltage", String(pzem_sensor.read("volt")));
            fire.send("pzem/current", String(pzem_sensor.read("current")));
            fire.send("pzem/energy", String(pzem_sensor.read("energy")));
            fire.send("pzem/power", String(pzem_sensor.read("power")));
            state = false;
        }
        
        
        if (presentance_up >= 20 && fire.count == 0)
        {
            Serial.println("update atas");
            fire.send("loadUp/status","Selesai");
            fire.count = 1;
        }

        else if (presentance_down >= 20 && fire.count == 1)
        {
            Serial.println("update bawah");
            fire.send("loadDown/status","Selesai");
            fire.count = 2;
        }
        
        else if (presentance_up >= 20 && presentance_down >= 20 && fire.count == 2)
        {
            fire.send_time("endTime");
            Serial.println("selesai");
            
            fire.get_time("start");
            fire.get_time("end");
            estimation = (fire.TIME2 - fire.TIME1) * pzem_sensor.read("energy")*1500;
            fire.send("estimation", String(estimation));
            digitalWrite(fan, HIGH);
            digitalWrite(heater1, HIGH);
            digitalWrite(heater2, HIGH);
            delay(100);
            lcd_kanan.done();
            lcd_kiri.done();
            fire.count = 0;
            keypads.mode = "selesai";
            state = true;
            state1 = true;
        }
        TIME ++;
        delay(500);
    }
    
    keypads.done(true);
    
}

void serialMonitor(){
    Serial.print("Up value = ");
    Serial.print(lc_up_value, 0);
    Serial.print(" grams || ");
    Serial.print("Down value = ");
    Serial.print(lc_down_value, 0);
    Serial.print(" grams");
    Serial.print(" || voltage = ");
    Serial.print(pzem_sensor.read("volt"));
    Serial.print("V");
    Serial.print(" || current = ");
    Serial.print(pzem_sensor.read("current"));
    Serial.print("A");
    Serial.print(" || power = ");
    Serial.print(pzem_sensor.read("power"));
    Serial.print("W");
    Serial.print(" || energy = ");
    Serial.print(pzem_sensor.read("energy"), 3);
    Serial.print("kWh");
    Serial.print(" || suhu = ");
    Serial.print(DHT.read("temp"));
    Serial.print("C");
    Serial.print(" || kelembaban = ");
    Serial.print(DHT.read("humy"));
    Serial.print("%");
    Serial.println();
>>>>>>> 9f4c145668b6fb6c7976d9e7904c2a03d2dd6554
}