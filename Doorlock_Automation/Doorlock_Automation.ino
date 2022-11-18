#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo servo;

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ROW_NUM    = 4;
const int COLUMN_NUM = 4;
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte pin_rows[ROW_NUM] = {2,3,4,5};
byte pin_column[COLUMN_NUM] = {6,7,8,9}; 

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

const String password_1 = "12345678"; // change your password here
String input_password;

int huruf = 0;
int conf = 0;

void setup()
{
  Serial.begin(9600); 
  servo.attach(11);
  servo.write(0);
  
  lcd.begin();
  lcd.backlight();
  lcd.setCursor (4, 0);
  lcd.print(F("Door Lock"));
  lcd.setCursor (3, 1);
  lcd.print(F("Pace/Ronny"));
  
  delay(2000);
  lcd.clear();
  input_password = "";
  key_1 = "";
  input_password.reserve(32); 
  
}

void loop()                 
{
    if(conf == 0){
      lcd.setCursor(0,0);
      lcd.print("Masukan Password");
      
    }
    else if(conf == 1){
      lcd.setCursor(0,0);
      lcd.print("Confirm Password");
      
    }
    else if(conf == 2){    
      lcd.setCursor(0,0);
      lcd.print("Pintu Terbuka"); 
      char key = keypad.getKey();
      if(key == '#'){
         lcd.setCursor(0,0);
         lcd.print("Pintu Tertutup");
         servo.write(0);
         conf = 0;
         huruf = 0;
         input_password = "";
         delay(3000);
         lcd.clear();
        }  
      
    }
    lcd.setCursor(0,1);
    lcd.print(input_password);
    
    pass(); 
    delay(50);
}

void pass()
{
  char key = keypad.getKey();
  if (key){
    Serial.println(key);
    input_password += key;
    huruf +=1;
      if(input_password == password_1 && huruf >= 8 && conf == 0) {
        conf = 1;
        huruf = 0;
        input_password = "";
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Password Benar");
        delay(3000);
        lcd.clear();
      }
      
      else if(input_password != password_1 && huruf >= 8 && conf == 0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Password Salah");
        input_password = "";
        huruf = 0;
        delay(3000);
        lcd.clear();
      }

      else if(conf == 1){       
        if(input_password == password_1 && huruf >= 8) {
        conf = 2;
        huruf = 0;
        input_password = "";
        key_1 = "";
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Password Benar");
        delay(3000);
        lcd.clear();
        servo.write(90);
      }

      else if (input_password != password_1 && huruf >= 8){
        conf = 0;
        huruf = 0;
        input_password = "";
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Password Salah");
        delay(3000);
        lcd.clear();
      }
      }
  }
}
