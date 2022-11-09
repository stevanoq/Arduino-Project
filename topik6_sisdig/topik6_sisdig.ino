int in1 = 11;
int in2 = 10;
int en = 9;
int button = 12;
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int a = 0;

void setup () {
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(en, OUTPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);
pinMode(button, INPUT);
}

void mode1()
{
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   analogWrite(en, 50);   
   digitalWrite(led1, LOW);
   digitalWrite(led3, LOW);
   digitalWrite(led5, LOW);
   digitalWrite(led2, HIGH);
   digitalWrite(led4, HIGH);
   digitalWrite(led6, HIGH);
}

void mode2()
{
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   analogWrite(en, 150);   
   digitalWrite(led1, HIGH);
   digitalWrite(led3, HIGH);
   digitalWrite(led5, HIGH);
   digitalWrite(led2, LOW);
   digitalWrite(led4, LOW);
   digitalWrite(led6, LOW);
}

void mode3()
{
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   analogWrite(en, 250);   
   digitalWrite(led1, HIGH);
   digitalWrite(led3, HIGH);
   digitalWrite(led5, HIGH);
   digitalWrite(led2, HIGH);
   digitalWrite(led4, HIGH);
   digitalWrite(led6, HIGH);
}

void mode4()
{
   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   digitalWrite(led1, LOW);
   digitalWrite(led3, LOW);
   digitalWrite(led5, LOW);
   digitalWrite(led2, LOW);
   digitalWrite(led4, LOW);
   digitalWrite(led6, LOW);
    a = 0;
}

void loop() 
{
  if(digitalRead(button) == 0)
  {
    a = a+1;
    if (a == 1)
  {
    mode1();
  }
  if (a == 2)
  {
    mode2();
  }
   if (a == 3)
  {
    mode3();
  }
  if (a == 4)
  {
   mode4();
  }
  }
  delay(100);
}
