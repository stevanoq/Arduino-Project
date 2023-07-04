#include <LiquidCrystal_I2C.h>
#include "lcd.h"

LiquidCrystal_I2C lcdkiri(0x27, 16, 2);
LiquidCrystal_I2C lcdkanan(0x21,16,2);

void MonitorKiri::begin()
{
    lcdkiri.init();
    lcdkiri.backlight();
    lcdkiri.setCursor(0,0);
    lcdkiri.print("  INSTALIZING");
    lcdkiri.setCursor(0,1);
    lcdkiri.print("    SYSTEM");
}

void MonitorKiri::sensor(float atas, float bawah, float up, float down)
{
    lcdkiri.clear();
    lcdkiri.setCursor(0,0);
    lcdkiri.print("WA:");
    lcdkiri.print(atas,0);
    lcdkiri.print("g PA:");
    lcdkiri.print(up,0);
    lcdkiri.print("%");
    lcdkiri.setCursor(0,1);
    lcdkiri.print("WB:");
    lcdkiri.print(bawah,0);
    lcdkiri.print("g PB:");
    lcdkiri.print(down,0);
    lcdkiri.print("%");
}

void MonitorKiri::selectAction()
{
    lcdkiri.clear();
    lcdkiri.setCursor(0,0);
    lcdkiri.print("PENGERING BIJI");
    lcdkiri.setCursor(0,1);
    lcdkiri.print("      KOPI");
}

void MonitorKiri::done()
{
    lcdkiri.clear();
    lcdkiri.setCursor(0,0);
    lcdkiri.print("  PENGERINGAN");
    lcdkiri.setCursor(0,1);
    lcdkiri.print(" TELAH SELSEAI");
}

void MonitorKanan::begin()
{
    lcdkanan.init();
    lcdkanan.backlight();
    lcdkanan.clear();
    lcdkanan.setCursor(0,0);
    lcdkanan.print("  WAIT A MOMENT");
}

void MonitorKanan::sensor(float suhu, float kel, float volt, float current)
{
    lcdkanan.clear();
    lcdkanan.setCursor(0,0);
    lcdkanan.print("T:");
    lcdkanan.print(suhu);
    lcdkanan.print("C H:");
    lcdkanan.print(kel,0);
    lcdkanan.print("%");
    lcdkanan.setCursor(0,1);
    lcdkanan.print("V:");
    lcdkanan.print(volt);
    lcdkanan.print("V I:");
    lcdkanan.print(current);
    lcdkanan.print("A");
}

void MonitorKanan::selectAction()
{
    lcdkanan.clear();
    lcdkanan.setCursor(0,0);
    lcdkanan.print(" TEKAN TOMBOL A");
    lcdkanan.setCursor(0,1);
    lcdkanan.print(" UNTUK MEMULAI");
}

void MonitorKanan::setting()
{
    lcdkanan.clear();
    lcdkanan.setCursor(0,0);
    lcdkanan.print(" MASUKAN KOPI");
    lcdkanan.setCursor(0,1);
    lcdkanan.print("A.MULAI B.BATAL");
}

void MonitorKanan::done()
{
    lcdkanan.clear();
    lcdkanan.setCursor(0,0);
    lcdkanan.print("  TEKAN TOMBOL");
    lcdkanan.setCursor(0,1);
    lcdkanan.print("   MANA SAJA");
}
