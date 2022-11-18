
#define pin 9
int i = 2850;
int j = 0;
void setup() {
  
}

void loop() {
  //tone(pin, 3000, 500);
  if(i >= 2850 && i < 3000 && j == 0){
    i++;
    tone(pin,i);
    delay(1);
    if(i == 3000){     
      j+=1;
    }
  }
  else if(i <= 3000 &&  i >= 2850 && j == 1){
    i--;
    tone(pin,i);
    delay(1);
    if(i == 2850){
      j-=1;
    }
  }
  
  
 /* for(int i=2000;i<3000;i++){   // for police siren
  tone(pin,i);
  delay(2);
  }
  for(int j=3000;j>2000;j--){
  tone(pin,j);
  delay(1);
  }*/
}
