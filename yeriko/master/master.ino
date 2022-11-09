// Transmitter

int Button1 =  P1^1;

void setup() {

  Serial.begin(9600);
  pinMode(Button1, INPUT_PULLUP); 

}

void loop() {

  if(digitalRead(Button1) == 1)
  {
    Serial.write('1');
  }
  else if(digitalRead(Button1) == 0)
  {
    Serial.write('2');
  }
  delay(200); 
}
