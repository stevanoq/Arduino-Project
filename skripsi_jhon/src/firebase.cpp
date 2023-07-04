#include <FirebaseESP32.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "firebase.h"
#include "lcd.h"

#define API_KEY "AIzaSyD-Cf4z72ok1VYrOTvlb6ELVwf1yRagq_g"
#define FIREBASE_PROJECT_ID "smartbox-penerima-barang"
#define USER_EMAIL "evanyap2002@gmail.com"
#define USER_PASS "1234567"
#define DATABASE_URL "https://smartbox-penerima-barang-default-rtdb.firebaseio.com/"

FirebaseData db;
FirebaseAuth auth;
FirebaseConfig config;
FirebaseJson json;
lcd MYlcd;

String UID, path, statusPath, resiPath, status, barcodePath, code, Resi, statePath;
bool posbile;
String dayStr, TIME, logPath[6], date, TIMES;

int J;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "asia.pool.ntp.org", 25200);

void firebase::init(){
    MYlcd.connectFirebase();
    delay(1000);
    config.api_key = API_KEY;
    auth.user.email = USER_EMAIL;
    auth.user.password = USER_PASS;
    config.database_url = DATABASE_URL;
    Firebase.reconnectWiFi(true);
    db.setResponseSize(4096);
    config.token_status_callback = tokenStatusCallback;
    config.max_token_generation_retry = 5;
    Firebase.begin(&config, &auth);
    
    while (auth.token.uid == "")
    {
        // Serial.print(".");
        delay(1000);
    }

    UID = auth.token.uid.c_str();
    timeClient.begin();
    
    // Serial.println("UID = ");
    // Serial.print(UID);
}

void firebase::findResi(String resi){
    path = UID + "/boxData/" + resi;
    resiPath = path + "/resi";
    statusPath = path + "/status";
    MYlcd.verifying();
    if(Firebase.RTDB.pathExisted(&db, resiPath)){
        // Serial.println("Resi is Existed");
        if (Firebase.RTDB.getString(&db, resiPath) && db.dataType() == "string")
        {
            Resi = db.stringData();
            if (Resi == resi)
            {
                if (Firebase.RTDB.getString(&db, statusPath) && db.dataType() == "string")
                {
                    status = db.stringData();
                    if (status == "Proses")
                    {
                        MYlcd.verified();
                        posbile = true;
                        delay(1000);
                    }

                    else
                    {
                        MYlcd.used();
                        this -> updateLog(true, "TITIP", resi, "RESI KADALUARSA");
                        posbile = false;
                        delay(2000);
                    }
                }
                
            }

            else
            {
                MYlcd.unverified();
                posbile = false;
                delay(2000);
            }
        }
    }

    else{
        MYlcd.unverified();
        posbile = false;
        delay(2000);
    }
    
}

void firebase::findBarcode(String barcode)
{
    path = UID + "/barcode";
    barcodePath = path + "/code";
    statePath = path + "/state";

    if (Firebase.RTDB.pathExisted(&db, path))
    {
        // Serial.println("Path barcode ada");
        MYlcd.verifying();
        if (Firebase.RTDB.getString(&db, barcodePath) && db.dataType() == "string")
        {
            code = db.stringData();
            if (barcode == code)
            {
                // Serial.println("barcode benar");
                Firebase.RTDB.setInt(&db, statePath, 1);
                MYlcd.verified();
                this->updateLog(true, "AMBIL", barcode, "BERHASIL");
                posbile = true;
                delay(1000);
            }

            else
            {
                MYlcd.unverified();
                this->updateLog(true, "AMBIL", barcode, "GAGAL");
                posbile = false;
                delay(2000);
            }
        }

        else
        {
            MYlcd.unverified();
            this->updateLog(true, "AMBIL", barcode, "GAGAL");
            posbile = false;
            delay(2000);
        }
    }

    else
    {
        MYlcd.unverified();
        this->updateLog(true, "AMBIL", barcode, "GAGAL");
        posbile = false;
         delay(2000);
    }
    
    
}

void firebase::updateStatus(bool state, String RESI)
{
    path = UID + "/boxData/" + RESI;
    statusPath = path + "/status";
    if (state)
    {
        Firebase.RTDB.setString(&db, statusPath, "Diterima");
        if (Firebase.RTDB.pathExisted(&db, UID + "/recieved"))
        {
            if (Firebase.RTDB.getInt(&db, UID + "/recieved/count") && db.dataType() == "int")
            {
                J = db.intData();
                Firebase.RTDB.setInt(&db, UID + "/recieved/count", J+1);
                Firebase.RTDB.setString(&db, UID + "/recieved/resi" + String(J+1), RESI);                
            }
        }
        
        else
        {
            Firebase.RTDB.setInt(&db, UID + "/recieved/count", 1);
            Firebase.RTDB.setString(&db, UID + "/recieved/resi1", RESI);
        }
        this -> updateLog(true, "TITIP", RESI, "BERHASIL");
    }

    else
    {
        MYlcd.failedPut();
        delay(2000);
    }
}

void firebase::updateLog(bool state, String action, String RESI, String check)
{
    while (state)
    {
        timeClient.update();
        if (!timeClient.update())
        {
            timeClient.forceUpdate();
        }
        
        TIME = timeClient.getFormattedDate();
        path = UID + "/dataLog/" + TIME;
        
        date = TIME.substring(0, TIME.indexOf(" "));
        TIMES = TIME.substring(TIME.indexOf(" ")+1, TIME.length());
    
        logPath[0] = path + "/action";
        logPath[1] = path + "/resi";
        logPath[2] = path + "/barcode";
        logPath[3] = path + "/status";
        logPath[4] = path + "/date";
        logPath[5] = path + "/time";

        if (action == "TITIP")
        {
            Firebase.RTDB.setString(&db, logPath[0], action);
            Firebase.RTDB.setString(&db, logPath[1], RESI);
            Firebase.RTDB.setString(&db, logPath[3], check);
            Firebase.RTDB.setString(&db, logPath[4], date);
            Firebase.RTDB.setString(&db, logPath[5], TIMES);
            state = false;
        }

        else
        {
            Firebase.RTDB.setString(&db, logPath[0], action);
            Firebase.RTDB.setString(&db, logPath[2], RESI);
            Firebase.RTDB.setString(&db, logPath[3], check);
            Firebase.RTDB.setString(&db, logPath[4], date);
            Firebase.RTDB.setString(&db, logPath[5], TIMES);
            state = false;
        }
    }
}

void firebase::checkBBarcode(bool state)
{
    if (Firebase.RTDB.pathExisted(&db, UID + "/barcode"))
    {
        posbile = true;
        state = false;
    }
    else
    {
        MYlcd.noBarcode();
        posbile = false;
        delay(2000);
        state = false;
    }
}

void firebase::deleteBarcode(bool state)
{
    if (Firebase.RTDB.pathExisted(&db, UID + "/barcode"))
    {
        Firebase.RTDB.deleteNode(&db, UID + "/barcode");
    }
}

void firebase::checkPackege(bool state)
{
    while (state)
    {
        if (Firebase.RTDB.pathExisted(&db, UID + "/recieved"))
        {
            posbile = true;
            state = false;
        }
        else
        {
            MYlcd.empty();
            posbile = false;
            delay(2000);
            state = false;
        }
    }
}

void firebase::deleteResi(bool state)
{
    if (Firebase.RTDB.pathExisted(&db, UID + "/recieved"))
    {
        if (Firebase.RTDB.getInt(&db, UID + "/recieved/count") && db.dataType() == "int")
            {
                J = db.intData();
                for (int i = 1; i <= J; i++)
                {
                    if (Firebase.RTDB.getString(&db, UID + "/recieved/resi" + String(i)) && db.dataType() == "string")
                    {
                        String ressi;
                        ressi = db.stringData();
                        Firebase.RTDB.deleteNode(&db, UID + "/boxData/" + ressi);
                        Serial.print("in for loop");
                        Serial.println(ressi);
                    }
                }

                Firebase.RTDB.deleteNode(&db, UID + "/recieved");
                state = false;
            }
    }

}



bool firebase::state(void)
{
    return posbile;
}
