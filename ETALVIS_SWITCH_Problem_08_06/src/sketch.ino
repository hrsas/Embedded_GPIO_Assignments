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

    if((input & 0x80) == 0x80){
      *outA = 0b10101010;
    }
    else{
      *outA = 0x00;
    }
  }

}
