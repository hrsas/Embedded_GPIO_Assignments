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
  static int switch_press = 0;
  while(1){
    input = *inB;

    if(switch_press == 0){
      if((input & 0x02) == 0x02){
        debounce();
        switch_press = 1;
      }
    }
    else if(switch_press == 1){
      if((input & 0x80) == 0x80){
        debounce();
        *outA = 0x10;
        delay();
        *outA = 0x00;
        switch_press = 0;
      }
    }
  }

}
