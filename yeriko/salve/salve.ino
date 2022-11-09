//Reciever
 #include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int LED1 = 10;
char message;

void setup() {
  
   lcd.begin(16, 2);
  Serial.begin(9600); 
  pinMode(LED1, OUTPUT);
  
}

void loop() {
  
  if(Serial.available())
  {
    message = Serial.read();
    if(message == '2')
    {
      digitalWrite(LED1, 0);
      int x;
    lcd.setCursor(1, 0);
    lcd.print("NAMA MU DIISI ");
    lcd.setCursor(1, 1);
    lcd.print("NAMA TEMAN MU");
    for (x = 0 ; x < 12 ; x++)
    {
      lcd.scrollDisplayRight();
      delay(10);
    }
    }
  else
{
digitalWrite(LED1, 1);
int z;
    lcd.setCursor(1, 0);
    lcd.print("NIM MU SETAN");
    lcd.setCursor(1, 1);
    lcd.print("NIM TEMAN MU SETAN");
    for (z = 0 ; z < 16 ; z++)
    {
      lcd.scrollDisplayLeft();
      delay(10);
    }
}  

  }
  delay(200);
  
}
