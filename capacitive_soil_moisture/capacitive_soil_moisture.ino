#define sensor A0
#define wet 430
#define dry 840


void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);

}

void loop() {
  int value=analogRead(sensor);
  Serial.println("Moisture Value");
  Serial.println(value);
  int pre = map (value,wet,dry,100,0);
  Serial.println(pre);
  delay(500);
}
