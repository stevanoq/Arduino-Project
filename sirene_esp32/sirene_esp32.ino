const int TONE_OUTPUT_PIN = 13;

// The ESP32 has 16 channels which can generate 16 independent waveforms
// We'll just choose PWM channel 0 here
const int TONE_PWM_CHANNEL = 0; 
int i = 0;
int j = 0;
void setup() {
  // ledcAttachPin(uint8_t pin, uint8_t channel);
  ledcAttachPin(TONE_OUTPUT_PIN, TONE_PWM_CHANNEL);
}

void loop() {

  if(i >= 0 && i <=100 && j == 0){
    i++;
    ledcWriteNote(TONE_PWM_CHANNEL, NOTE_A, 5);
    if(i == 100){
      j+=1;
      i=0;
    }
    delay(1);
  }
  if(i >= 0 && i <= 175 && j == 1){
    i++;
    ledcWriteNote(TONE_PWM_CHANNEL, NOTE_C, 5);
    if(i == 175){
      j-=1;
      i=0;
    }
    delay(1);
  }
}
