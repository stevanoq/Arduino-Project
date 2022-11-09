const int latchPin = 10; 
const int clockPin = 12; 
const int dataPin = 11;

int angka[] = {
  B11111100, //angka 0
  B01100000, //angka 1
  B11011010, //angka 2
  B11110010, //angka 3
  B01100110, //angka 4
  B10110110, //angka 5
  B10111110, //angka 6
  B11100000, //angka 7
  B11111110, //angka 8
  B11110110 //angka 9
};

;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, angka[i]);
    digitalWrite(latchPin, HIGH); 
    delay(200);
  }
}
