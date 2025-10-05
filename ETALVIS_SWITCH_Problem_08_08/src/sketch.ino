#include "etalvis.h"

void setup() {
  // put your setup code here, to run once:
  volatile char *dirA, *dirB;
  dirA = 0x21; dirB = 0x24;
  *dirA = 0xFF; *dirB = 0x00;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *outA, *inB, input; 
  outA = 0x22; inB = 0x23;

  while(1){
    input = *inB;

    if((input & 0x01) == 0x01){
      *outA = 0x80;
    }
    else if((input & 0x2) == 0x02){
      *outA = 0x40;
    }
    else if((input & 0x04) == 0x04){
      *outA = 0x20;
    }
    else if((input & 0x08) == 0x08){
      *outA = 0x10;
    }
    else if((input & 0x10) == 0x10){
      *outA = 0x08;
    }
    else if((input & 0x20) == 0x20){
      *outA = 0x04;
    }
    else if((input & 0x40) == 0x40){
      *outA = 0x02;
    }
    else if((input & 0x80) == 0x80){
      *outA = 0x01;
    }
    else{
      *outA = 0x00;
    }
  }

}
