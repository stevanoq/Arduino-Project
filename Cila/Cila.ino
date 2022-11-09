#include <Wire.h>
#include<OneWire.h>
#include<DallasTemperature.h>

#define SuhuSen 2
#define TSen A0
#define PHSen A1

OneWire oneWire(SuhuSen);
DallasTemperature tempSen(&oneWire);

float turbidity, phSenVal, voltage;
float kalibrasi = 21.34-0.7;
float temperature;
int phVal = 0;
unsigned long int avgval;
int buffer_arr[10],temp;

float ph_act;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  tempSen.begin();
}

void loop() {
  Serial.println("Arduino");
  getTurbidity();
  getPH();
  getSuhu();
  
  
}

void getSuhu(){
  tempSen.requestTemperatures();
  temperature = tempSen.getTempCByIndex(0);
  Serial.print("Suhu : ");
  Serial.println(temperature);
}

void getTurbidity(){
  voltage = 0;
  for(int i=0; i<800; i++){
    voltage += ((float)analogRead(TSen)/1023)*5;
  }

  voltage = voltage/800;
  voltage = round_to_dp(voltage,2);
  if(voltage < 2.5){
    turbidity = 3000;
  }

  else{
    turbidity = -1120.4*square(voltage)+5742.3*voltage-4352.9;
  }
  
  Serial.print("Turbidity : ");
  Serial.println(turbidity);
}

float round_to_dp(float in_value, int decimal){
  float multiplier = powf(10.0f, decimal);
  in_value = roundf(in_value*multiplier)/multiplier;
  return in_value;
}

void getPH(){
  phSenVal = analogRead(A1);
  for(int i=0;i<10;i++){
    buffer_arr[i]=phSenVal;
    //delay(30);
  }
  for(int i=0;i<9;i++)
  {
    for(int j=i+1;j<10;j++){
      if(buffer_arr[i]>buffer_arr[j]){
        temp = buffer_arr[i];
        buffer_arr[i] = buffer_arr[j];
        buffer_arr[j] = temp;  
      }
    }
  }

  avgval = 0;
  for(int i=2;i<8;i++)
  avgval += buffer_arr[i];
  float voltage_ph = (float)avgval*5/1024/6;
  phVal = -5.70*voltage_ph + kalibrasi;

  Serial.print("PH : ");
  Serial.println(phVal);
}
