<<<<<<< HEAD
// load eeprom library
#include <EEPROM.h>
// alokasi pin BCD dari MT8870
const int BCDPin1 = 4;
const int BCDPin2 = 3;
const int BCDPin3 = 2;
const int BCDPin4 = 1;
const int BCDPinX = 0;
// state BCD dari MT8870
int BCDState1 = 0;
int BCDState2 = 0;
int BCDState3 = 0;
int BCDState4 = 0;
int BCDStateX = 0;
// state hasil decode ke desimal
int S0 = 0;
int S1 = 0;
int S2 = 0;
int S3 = 0;
int S4 = 0;
int S5 = 0;
int S6 = 0;
int S7 = 0;
int S8 = 0;
int S9 = 0;
int SB0 = 0; // bintang
int SP0 = 0; // pager
// state combination key
int D1 = 0; // *
int D2 = 0; // pass1
int D3 = 0; // pass2
int D4 = 0; // pass3
int D5 = 0; // *
int D6 = 0; // relaynumber
int D7 = 0; // ending
// alokasi pin output / relay
const int LedPin1 =  5;
const int LedPin2 =  6;
const int LedPin3 =  7;
const int LedPin4 =  8;
const int LedPin5 =  9;
const int LedPin6 =  10;
const int LedPin7 =  11;
const int LedPin8 =  12;
const int LedPin9 =  13;
// status relay
int rstat1 = 0;
int rstat2 = 0;
int rstat3 = 0;
int rstat4 = 0;
int rstat5 = 0;
int rstat6 = 0;
int rstat7 = 0;
int rstat8 = 0;
// loading status sebelum mati listrik
int lstat1 = 0;
int lstat2 = 0;
int lstat3 = 0;
int lstat4 = 0;
int lstat5 = 0;
int lstat6 = 0;
int lstat7 = 0;
int lstat8 = 0;
// bootstat
int bootstat0 = 0;
 
void setup() {
  //alokasi pin input ( BCD )
  pinMode(BCDPin1, INPUT);  
  pinMode(BCDPin2, INPUT);
  pinMode(BCDPin3, INPUT);
  pinMode(BCDPin4, INPUT);
  pinMode(BCDPinX, INPUT);  
  // alokasi pin output ( Relay )
  pinMode(LedPin1, OUTPUT);
  pinMode(LedPin2, OUTPUT);
  pinMode(LedPin3, OUTPUT);
  pinMode(LedPin4, OUTPUT);
  pinMode(LedPin5, OUTPUT);
  pinMode(LedPin6, OUTPUT);
  pinMode(LedPin7, OUTPUT);
  pinMode(LedPin8, OUTPUT);
  pinMode(LedPin9, OUTPUT);
 }
 
void checkboot() {
if (bootstat0 == 0) {
  lstat1 = EEPROM.read(1);
  lstat2 = EEPROM.read(2);
  lstat3 = EEPROM.read(3);
  lstat4 = EEPROM.read(4);
  lstat5 = EEPROM.read(5);
  lstat6 = EEPROM.read(6);
  lstat7 = EEPROM.read(7);
  lstat8 = EEPROM.read(8);
  if (lstat1 == 1) {
    digitalWrite(LedPin1, HIGH);
    rstat1 = lstat1;
  }
  if (lstat2 == 1) {
    digitalWrite(LedPin2, HIGH);
    rstat2 = lstat2;
  }
  if (lstat3 == 1) {
    digitalWrite(LedPin3, HIGH);
    rstat3 = lstat3;
  }
  if (lstat4 == 1) {
    digitalWrite(LedPin4, HIGH);
    rstat4 = lstat4;
  }
  if (lstat5 == 1) {
    digitalWrite(LedPin5, HIGH);
    rstat5 = lstat5;
  }
  if (lstat6 == 1) {
    digitalWrite(LedPin6, HIGH);
    rstat6 = lstat6;
  }
  if (lstat7 == 1) {
    digitalWrite(LedPin7, HIGH);
    rstat7 = lstat7;
  }
  if (lstat8 == 1) {
    digitalWrite(LedPin8, HIGH);
    rstat8 = lstat8;
  }
  bootstat0 = 1;
}
 
}
 
void reset() {  
 
 
D1 = 0; // *
D2 = 0; // pass1
D3 = 0; // pass2
D4 = 0; // pass3
D5 = 0; // *
D6 = 0; // relaynumber
D7 = 0;
}
 
void reset2() {
  S1 = 0;
  S2 = 0;
  S3 = 0;
  S4 = 0;
  S5 = 0;
  S6 = 0;
  S7 = 0;
  S8 = 0;
  S9 = 0;
  SB0 = 0;
  S0 = 0;
  SP0 = 0;
}
 
void exerelay1() {
  if (rstat1 == 0) {
    digitalWrite(LedPin1, LOW);
    EEPROM.write(1,0);
  }
  else if (rstat1 == 1) {
    digitalWrite(LedPin1, HIGH);
    EEPROM.write(1,1);
  }
}
 
void exerelay2() {
  if (rstat2 == 0) {
    digitalWrite(LedPin2, HIGH);
    EEPROM.write(2,1);
    rstat2 = 1;
  }
  else if (rstat2 == 1) {
    digitalWrite(LedPin2, LOW);
    EEPROM.write(2,0);
    rstat2 = 0;
  }
}
 
void exerelay3() {
  if (rstat3 == 0) {
    digitalWrite(LedPin3, HIGH);
    EEPROM.write(3,1);
    rstat3 = 1;
  }
  else if (rstat3 == 1) {
    digitalWrite(LedPin3, LOW);
    EEPROM.write(3,0);
    rstat3 = 0;
  }
}  
 
void exerelay4() {
  if (rstat4 == 0) {
    digitalWrite(LedPin4, HIGH);
    EEPROM.write(4,1);
    rstat4 = 1;
  }
  else if (rstat4 == 1) {
    digitalWrite(LedPin4, LOW);
    EEPROM.write(4,0);
    rstat4 = 0;
  }
}
 
void exerelay5() {
  if (rstat5 == 0) {
    digitalWrite(LedPin5, HIGH);
    EEPROM.write(5,1);
    rstat5 = 1;
  }
  else if (rstat5 == 1) {
    digitalWrite(LedPin5, LOW);
    EEPROM.write(5,0);
    rstat5 = 0;
  }
}  
 
void exerelay6() {
  if (rstat6 == 0) {
    digitalWrite(LedPin6, HIGH);
    EEPROM.write(6,1);
    rstat6 = 1;
  }
  else if (rstat6 == 1) {
    digitalWrite(LedPin6, LOW);
    EEPROM.write(6,0);
    rstat6 = 0;
  }
}
 
void exerelay7() {
  if (rstat7 == 0) {
    digitalWrite(LedPin7, HIGH);
    EEPROM.write(7,1);
    rstat7 = 1;
  }
  else if (rstat7 == 1) {
    digitalWrite(LedPin7, LOW);
    EEPROM.write(7,0);
    rstat7 = 0;
  }
}
 
void exerelay8() {
  if (rstat8 == 0) {
    digitalWrite(LedPin8, HIGH);
    EEPROM.write(8,1);
    rstat8 = 1;
  }
  else if (rstat8 == 1) {
    digitalWrite(LedPin8, LOW);
    EEPROM.write(8,0);
    rstat8 = 0;
  }
}
 
// final check
void check2() {
 
  if (D6 == 1) {
  if (S1 == 1) {
    exerelay1();    
    reset();
  }
}
 
  if (D6 == 1) {
  if (S2 == 1) {
    exerelay2();
    reset();
  }
}
 
  if (D6 == 1) {
  if (S3 == 1) {
    exerelay3();
    reset();
  }
}
 
  if (D6 == 1) {
  if (S4 == 1) {
    exerelay4();
    reset();
  }
}
 
  if (D6 == 1) {
  if (S5 == 1) {
    exerelay5();
    reset();
  }
}
 
  if (D6 == 1) {
  if (S6 == 1) {
    exerelay6();
    reset();
  }
}
 
  if (D6 == 1) {
  if (S7 == 1) {
    exerelay7();
    reset();
  }
}
 
  if (D6 == 1) {
  if (S8 == 1) {
    exerelay8();
    reset();
  }
}
 
}
 
 
void check() {
 
    BCDState1 = digitalRead(BCDPin1);
    BCDState2 = digitalRead(BCDPin2);
    BCDState3 = digitalRead(BCDPin3);
    BCDState4 = digitalRead(BCDPin4);
    BCDStateX = digitalRead(BCDPinX);
 
   
  if (BCDStateX == HIGH) {
        // detek 0    
        if (BCDState1 == LOW) {
          if (BCDState2 == HIGH) {
            if (BCDState3 == LOW) {
              if (BCDState4 == HIGH) {
                S0 = 1;
               
               
              }
            }
          }
        }
 
        // detek 1
        if (BCDState1 == HIGH) {
          if (BCDState2 == LOW) {
            if (BCDState3 == LOW) {
              if (BCDState4 == LOW) {
                S1 = 1;
               
              }
            }
          }
        }
       
        // detek 2
        if (BCDState1 == LOW) {
          if (BCDState2 == HIGH) {
            if (BCDState3 == LOW) {
              if (BCDState4 == LOW) {
                S2 = 1;
               
              }
            }
          }
        }
       
        // detek 3
        if (BCDState1 == HIGH) {
          if (BCDState2 == HIGH) {
            if (BCDState3 == LOW) {
              if (BCDState4 == LOW) {
                S3 = 1;
               
              }
            }
          }
        }
       
        // detek 4
        if (BCDState1 == LOW) {
          if (BCDState2 == LOW) {
            if (BCDState3 == HIGH) {
              if (BCDState4 == LOW) {
                S4 = 1;
               
              }
            }
          }
        }
       
        // detek 5
        if (BCDState1 == HIGH) {
          if (BCDState2 == LOW) {
            if (BCDState3 == HIGH) {
              if (BCDState4 == LOW) {
                S5 = 1;
               
              }
            }
          }
        }
       
        // detek 6
        if (BCDState1 == LOW) {
          if (BCDState2 == HIGH) {
            if (BCDState3 == HIGH) {
              if (BCDState4 == LOW) {
                S6 = 1;
               
              }
            }
          }
        }
       
        // detek 7
        if (BCDState1 == HIGH) {
          if (BCDState2 == HIGH) {
            if (BCDState3 == HIGH) {
              if (BCDState4 == LOW) {
                S7 = 1;
               
              }
            }
          }
        }
       
        // detek 8
        if (BCDState1 == LOW) {
          if (BCDState2 == LOW) {
            if (BCDState3 == LOW) {
              if (BCDState4 == HIGH) {
                S8 = 1;
               
              }
            }
          }
        }
       
        // detek 9
        if (BCDState1 == HIGH) {
          if (BCDState2 == LOW) {
            if (BCDState3 == LOW) {
              if (BCDState4 == HIGH) {
                SP0 = 1;
               
              }
            }
          }
        }
       
        // detek *
        if (BCDState1 == HIGH) {
          if (BCDState2 == HIGH) {
            if (BCDState3 == LOW) {
              if (BCDState4 == HIGH) {
                SB0 = 1;
               
              }
            }
          }
        }
       
        // detek #
        if (BCDState1 == LOW) {
          if (BCDState2 == LOW) {
            if (BCDState3 == HIGH) {
              if (BCDState4 == HIGH) {
                SP0 = 1;
               
              }
            }
          }
        }
 
// end of state BCDStateX
  }
 
 
 // end of check  
}
 
void loop(){
 
checkboot();  
check();  
check2();
 
 
// password 123
// lengkap nya *123#0x
// x = nomor relay
 
 
// x & * menjadi D1
if (BCDStateX == HIGH) {
  if (SB0 == 1) {
    D1 = 1;
  }
}
 
// 1 & D1 menjadi D2
if (S1 == 1 && D1 == 1) {
  D2 = 1;
}
 
 
// 2 dan D2 menjadi D3
if (S2 == 1 && D2 == 1) {
  D3 = 1;
}
 
// S3 dan D3 menjadi D4
 
if (S3 == 1 && D3 == 1) {
    D4 = 1;
}
 
// pager & D4 menjadi D5
 
if (SP0 == 1 && D4 == 1) {
    D5 = 1;
}
 
 
 
// detek password kao D nya sudah up tidak ada action tapi kalo D nya off langsung reset ajahhhh
 
if (S1 == 1) {
  if ( D2 == 1 ) {
    // no action
  }
  else {
    reset();
  }
}
 
if (S2 == 1) {
  if ( D3 == 1 ) {
    // no action
  }
  else {
    reset();
  }
}
 
if (S3 == 1) {
  if ( D4 == 1 ) {
    // no action
  }
  else {
    reset();
  }
}
 
 
if (SP0 == 1) {
  if ( D5 == 1 ) {
    // no action
  }
  else {
    reset();
  }
}
 
 
// selain angka2 password reset ajah sikat coyy
 
 
if (S4 == 1) {
  reset();
}
 
if (S5 == 1) {
  reset();
}
 
if (S6 == 1) {
  reset();
}
 
if (S7 == 1) {
  reset();
}
 
if (S8 == 1) {
  reset();
}
 
if (S0 == 1) {
  if (D5 == 1) {
    rstat1 = 0;
    D6 = 1;
  }
  else {
    reset();
  }
}

if (S9 == 1)
{
  if (D5 == 1)
  {
    rstat1 = 1;
    D6 == 1;
  }
  else{
    reset();
  }
}

if (D1 == 1) {
  digitalWrite(LedPin9, HIGH);
}
else if (D1 == 0) {
  digitalWrite(LedPin9, LOW);
}
 
 
reset2();
 
 
delay(10);
// end of state loop
=======
// load eeprom library
#include <EEPROM.h>
// alokasi pin BCD dari MT8870
const int BCDPin1 = 4;
const int BCDPin2 = 3;
const int BCDPin3 = 2;
const int BCDPin4 = 1;
const int BCDPinX = 0;
// state BCD dari MT8870
int BCDState1 = 0;
int BCDState2 = 0;
int BCDState3 = 0;
int BCDState4 = 0;
int BCDStateX = 0;
// state hasil decode ke desimal
int S0 = 0;
int S1 = 0;
int S2 = 0;
int S3 = 0;
int S4 = 0;
int S5 = 0;
int S6 = 0;
int S7 = 0;
int S8 = 0;
int S9 = 0;
int SB0 = 0; // bintang
int SP0 = 0; // pager
// state combination key
int D1 = 0; // *
int D2 = 0; // pass1
int D3 = 0; // pass2
int D4 = 0; // pass3
int D5 = 0; // *
int D6 = 0; // relaynumber
int D7 = 0; // ending
// alokasi pin output / relay
const int LedPin1 =  5;
const int LedPin2 =  6;
const int LedPin3 =  7;
const int LedPin4 =  8;
const int LedPin5 =  9;
const int LedPin6 =  10;
const int LedPin7 =  11;
const int LedPin8 =  12;
const int LedPin9 =  13;
// status relay
int rstat1 = 0;
int rstat2 = 0;
int rstat3 = 0;
int rstat4 = 0;
int rstat5 = 0;
int rstat6 = 0;
int rstat7 = 0;
int rstat8 = 0;
// loading status sebelum mati listrik
int lstat1 = 0;
int lstat2 = 0;
int lstat3 = 0;
int lstat4 = 0;
int lstat5 = 0;
int lstat6 = 0;
int lstat7 = 0;
int lstat8 = 0;
// bootstat
int bootstat0 = 0;
 
void setup() {
  //alokasi pin input ( BCD )
  pinMode(BCDPin1, INPUT);  
  pinMode(BCDPin2, INPUT);
  pinMode(BCDPin3, INPUT);
  pinMode(BCDPin4, INPUT);
  pinMode(BCDPinX, INPUT);  
  // alokasi pin output ( Relay )
  pinMode(LedPin1, OUTPUT);
  pinMode(LedPin2, OUTPUT);
  pinMode(LedPin3, OUTPUT);
  pinMode(LedPin4, OUTPUT);
  pinMode(LedPin5, OUTPUT);
  pinMode(LedPin6, OUTPUT);
  pinMode(LedPin7, OUTPUT);
  pinMode(LedPin8, OUTPUT);
  pinMode(LedPin9, OUTPUT);
 }
 
void checkboot() {
if (bootstat0 == 0) {
  lstat1 = EEPROM.read(1);
  lstat2 = EEPROM.read(2);
  lstat3 = EEPROM.read(3);
  lstat4 = EEPROM.read(4);
  lstat5 = EEPROM.read(5);
  lstat6 = EEPROM.read(6);
  lstat7 = EEPROM.read(7);
  lstat8 = EEPROM.read(8);
  if (lstat1 == 1) {
    digitalWrite(LedPin1, HIGH);
    rstat1 = lstat1;
  }
  if (lstat2 == 1) {
    digitalWrite(LedPin2, HIGH);
    rstat2 = lstat2;
  }
  if (lstat3 == 1) {
    digitalWrite(LedPin3, HIGH);
    rstat3 = lstat3;
  }
  if (lstat4 == 1) {
    digitalWrite(LedPin4, HIGH);
    rstat4 = lstat4;
  }
  if (lstat5 == 1) {
    digitalWrite(LedPin5, HIGH);
    rstat5 = lstat5;
  }
  if (lstat6 == 1) {
    digitalWrite(LedPin6, HIGH);
    rstat6 = lstat6;
  }
  if (lstat7 == 1) {
    digitalWrite(LedPin7, HIGH);
    rstat7 = lstat7;
  }
  if (lstat8 == 1) {
    digitalWrite(LedPin8, HIGH);
    rstat8 = lstat8;
  }
  bootstat0 = 1;
}
 
}
 
void reset() {  
 
 
D1 = 0; // *
D2 = 0; // pass1
D3 = 0; // pass2
D4 = 0; // pass3
D5 = 0; // *
D6 = 0; // relaynumber
D7 = 0;
}
 
void reset2() {
  S1 = 0;
  S2 = 0;
  S3 = 0;
  S4 = 0;
  S5 = 0;
  S6 = 0;
  S7 = 0;
  S8 = 0;
  S9 = 0;
  SB0 = 0;
  S0 = 0;
  SP0 = 0;
}
 
void exerelay1() {
  if (rstat1 == 0) {
    digitalWrite(LedPin1, LOW);
    EEPROM.write(1,0);
  }
  else if (rstat1 == 1) {
    digitalWrite(LedPin1, HIGH);
    EEPROM.write(1,1);
  }
}
 
void exerelay2() {
  if (rstat2 == 0) {
    digitalWrite(LedPin2, HIGH);
    EEPROM.write(2,1);
    rstat2 = 1;
  }
  else if (rstat2 == 1) {
    digitalWrite(LedPin2, LOW);
    EEPROM.write(2,0);
    rstat2 = 0;
  }
}
 
void exerelay3() {
  if (rstat3 == 0) {
    digitalWrite(LedPin3, HIGH);
    EEPROM.write(3,1);
    rstat3 = 1;
  }
  else if (rstat3 == 1) {
    digitalWrite(LedPin3, LOW);
    EEPROM.write(3,0);
    rstat3 = 0;
  }
}  
 
void exerelay4() {
  if (rstat4 == 0) {
    digitalWrite(LedPin4, HIGH);
    EEPROM.write(4,1);
    rstat4 = 1;
  }
  else if (rstat4 == 1) {
    digitalWrite(LedPin4, LOW);
    EEPROM.write(4,0);
    rstat4 = 0;
  }
}
 
void exerelay5() {
  if (rstat5 == 0) {
    digitalWrite(LedPin5, HIGH);
    EEPROM.write(5,1);
    rstat5 = 1;
  }
  else if (rstat5 == 1) {
    digitalWrite(LedPin5, LOW);
    EEPROM.write(5,0);
    rstat5 = 0;
  }
}  
 
void exerelay6() {
  if (rstat6 == 0) {
    digitalWrite(LedPin6, HIGH);
    EEPROM.write(6,1);
    rstat6 = 1;
  }
  else if (rstat6 == 1) {
    digitalWrite(LedPin6, LOW);
    EEPROM.write(6,0);
    rstat6 = 0;
  }
}
 
void exerelay7() {
  if (rstat7 == 0) {
    digitalWrite(LedPin7, HIGH);
    EEPROM.write(7,1);
    rstat7 = 1;
  }
  else if (rstat7 == 1) {
    digitalWrite(LedPin7, LOW);
    EEPROM.write(7,0);
    rstat7 = 0;
  }
}
 
void exerelay8() {
  if (rstat8 == 0) {
    digitalWrite(LedPin8, HIGH);
    EEPROM.write(8,1);
    rstat8 = 1;
  }
  else if (rstat8 == 1) {
    digitalWrite(LedPin8, LOW);
    EEPROM.write(8,0);
    rstat8 = 0;
  }
}
 
// final check
void check2() {
 
  if (D6 == 1) {
  if (S1 == 1) {
    exerelay1();    
    reset();
  }
}
 
  if (D6 == 1) {
  if (S2 == 1) {
    exerelay2();
    reset();
  }
}
 
  if (D6 == 1) {
  if (S3 == 1) {
    exerelay3();
    reset();
  }
}
 
  if (D6 == 1) {
  if (S4 == 1) {
    exerelay4();
    reset();
  }
}
 
  if (D6 == 1) {
  if (S5 == 1) {
    exerelay5();
    reset();
  }
}
 
  if (D6 == 1) {
  if (S6 == 1) {
    exerelay6();
    reset();
  }
}
 
  if (D6 == 1) {
  if (S7 == 1) {
    exerelay7();
    reset();
  }
}
 
  if (D6 == 1) {
  if (S8 == 1) {
    exerelay8();
    reset();
  }
}
 
}
 
 
void check() {
 
    BCDState1 = digitalRead(BCDPin1);
    BCDState2 = digitalRead(BCDPin2);
    BCDState3 = digitalRead(BCDPin3);
    BCDState4 = digitalRead(BCDPin4);
    BCDStateX = digitalRead(BCDPinX);
 
   
  if (BCDStateX == HIGH) {
        // detek 0    
        if (BCDState1 == LOW) {
          if (BCDState2 == HIGH) {
            if (BCDState3 == LOW) {
              if (BCDState4 == HIGH) {
                S0 = 1;
               
               
              }
            }
          }
        }
 
        // detek 1
        if (BCDState1 == HIGH) {
          if (BCDState2 == LOW) {
            if (BCDState3 == LOW) {
              if (BCDState4 == LOW) {
                S1 = 1;
               
              }
            }
          }
        }
       
        // detek 2
        if (BCDState1 == LOW) {
          if (BCDState2 == HIGH) {
            if (BCDState3 == LOW) {
              if (BCDState4 == LOW) {
                S2 = 1;
               
              }
            }
          }
        }
       
        // detek 3
        if (BCDState1 == HIGH) {
          if (BCDState2 == HIGH) {
            if (BCDState3 == LOW) {
              if (BCDState4 == LOW) {
                S3 = 1;
               
              }
            }
          }
        }
       
        // detek 4
        if (BCDState1 == LOW) {
          if (BCDState2 == LOW) {
            if (BCDState3 == HIGH) {
              if (BCDState4 == LOW) {
                S4 = 1;
               
              }
            }
          }
        }
       
        // detek 5
        if (BCDState1 == HIGH) {
          if (BCDState2 == LOW) {
            if (BCDState3 == HIGH) {
              if (BCDState4 == LOW) {
                S5 = 1;
               
              }
            }
          }
        }
       
        // detek 6
        if (BCDState1 == LOW) {
          if (BCDState2 == HIGH) {
            if (BCDState3 == HIGH) {
              if (BCDState4 == LOW) {
                S6 = 1;
               
              }
            }
          }
        }
       
        // detek 7
        if (BCDState1 == HIGH) {
          if (BCDState2 == HIGH) {
            if (BCDState3 == HIGH) {
              if (BCDState4 == LOW) {
                S7 = 1;
               
              }
            }
          }
        }
       
        // detek 8
        if (BCDState1 == LOW) {
          if (BCDState2 == LOW) {
            if (BCDState3 == LOW) {
              if (BCDState4 == HIGH) {
                S8 = 1;
               
              }
            }
          }
        }
       
        // detek 9
        if (BCDState1 == HIGH) {
          if (BCDState2 == LOW) {
            if (BCDState3 == LOW) {
              if (BCDState4 == HIGH) {
                SP0 = 1;
               
              }
            }
          }
        }
       
        // detek *
        if (BCDState1 == HIGH) {
          if (BCDState2 == HIGH) {
            if (BCDState3 == LOW) {
              if (BCDState4 == HIGH) {
                SB0 = 1;
               
              }
            }
          }
        }
       
        // detek #
        if (BCDState1 == LOW) {
          if (BCDState2 == LOW) {
            if (BCDState3 == HIGH) {
              if (BCDState4 == HIGH) {
                SP0 = 1;
               
              }
            }
          }
        }
 
// end of state BCDStateX
  }
 
 
 // end of check  
}
 
void loop(){
 
checkboot();  
check();  
check2();
 
 
// password 123
// lengkap nya *123#0x
// x = nomor relay
 
 
// x & * menjadi D1
if (BCDStateX == HIGH) {
  if (SB0 == 1) {
    D1 = 1;
  }
}
 
// 1 & D1 menjadi D2
if (S1 == 1 && D1 == 1) {
  D2 = 1;
}
 
 
// 2 dan D2 menjadi D3
if (S2 == 1 && D2 == 1) {
  D3 = 1;
}
 
// S3 dan D3 menjadi D4
 
if (S3 == 1 && D3 == 1) {
    D4 = 1;
}
 
// pager & D4 menjadi D5
 
if (SP0 == 1 && D4 == 1) {
    D5 = 1;
}
 
 
 
// detek password kao D nya sudah up tidak ada action tapi kalo D nya off langsung reset ajahhhh
 
if (S1 == 1) {
  if ( D2 == 1 ) {
    // no action
  }
  else {
    reset();
  }
}
 
if (S2 == 1) {
  if ( D3 == 1 ) {
    // no action
  }
  else {
    reset();
  }
}
 
if (S3 == 1) {
  if ( D4 == 1 ) {
    // no action
  }
  else {
    reset();
  }
}
 
 
if (SP0 == 1) {
  if ( D5 == 1 ) {
    // no action
  }
  else {
    reset();
  }
}
 
 
// selain angka2 password reset ajah sikat coyy
 
 
if (S4 == 1) {
  reset();
}
 
if (S5 == 1) {
  reset();
}
 
if (S6 == 1) {
  reset();
}
 
if (S7 == 1) {
  reset();
}
 
if (S8 == 1) {
  reset();
}
 
if (S0 == 1) {
  if (D5 == 1) {
    rstat1 = 0;
    D6 = 1;
  }
  else {
    reset();
  }
}

if (S9 == 1)
{
  if (D5 == 1)
  {
    rstat1 = 1;
    D6 == 1;
  }
  else{
    reset();
  }
}

if (D1 == 1) {
  digitalWrite(LedPin9, HIGH);
}
else if (D1 == 0) {
  digitalWrite(LedPin9, LOW);
}
 
 
reset2();
 
 
delay(10);
// end of state loop
>>>>>>> 9f4c145668b6fb6c7976d9e7904c2a03d2dd6554
  }