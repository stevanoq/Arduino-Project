#define in1 3
#define in2 5
#define in3 6
#define in4 9
#define led_depan A4
#define led_belakang A5
#define buzzer 2
int w = 0;
char msg, cmd;

int duty25 = 64;
int duty50 = 127;
int duty75 = 191;
int duty100 = 255;

void setup() {

  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(led_depan, OUTPUT);
  pinMode(led_belakang, OUTPUT);
  pinMode(buzzer, OUTPUT);
 
  msg = "";

}

void loop() {

  while (Serial.available() > 0) { // Check if there is data coming
    msg = Serial.read(); // Read the message as String
    
    Serial.println(msg);

    if(msg == 'f'){
      Serial.println("maju");
      maju();
      digitalWrite(led_belakang, LOW);
    }

    else if(msg == 'b'){
      Serial.println("mundur");
      mundur();
      digitalWrite(led_belakang, LOW);
    }

    else if(msg == 'l'){
      Serial.println("kiri");
      digitalWrite(led_belakang, LOW);
      kiri();
    }

    else if(msg == 'r'){
      kanan();
      digitalWrite(led_belakang, LOW);
    }

    else if(msg == 't'){
      kananMaju();
      digitalWrite(led_belakang, LOW);
    }

    else if(msg == 'x'){
      kananMundur();
      digitalWrite(led_belakang, LOW);
    }

    else if(msg == 'z'){
      kiriMaju();
      digitalWrite(led_belakang, LOW);
    }

    else if(msg == 'c'){
      kiriMundur();
      digitalWrite(led_belakang, LOW);
    }

    else if(msg == 'k')
    {
      digitalWrite(buzzer, HIGH);
    }
    
    else if(msg == 'm')
    {
      digitalWrite(buzzer, LOW);
    }

    else if(msg == 'n')
    {
      digitalWrite(led_depan, HIGH);
    }

    else if(msg == 'o')
    {
      digitalWrite(led_depan, LOW);
    }
    
    else if(msg == 's')
    {
      Serial.println("stop");
      berhenti();
      digitalWrite(led_belakang, HIGH);
    }

    else 
    {
      digitalWrite(led_belakang, LOW);
    }
    
    
  }

delay(10);

}

void maju() {
  analogWrite(in1, 200);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  analogWrite(in4, 255);
}

void mundur() {
  digitalWrite(in1, LOW);
  analogWrite(in2, 200);
  analogWrite(in3, 255);
  digitalWrite(in4, LOW);
}

void kiriMaju() {
  analogWrite(in1, duty25);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void kananMaju() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  analogWrite(in4, duty25);
}

void kanan() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void kiri() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void kiriMundur() {
  digitalWrite(in1, LOW);
  analogWrite(in2, duty25);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void kananMundur() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(in3, duty25);
  digitalWrite(in4, LOW);
}

void berhenti() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
