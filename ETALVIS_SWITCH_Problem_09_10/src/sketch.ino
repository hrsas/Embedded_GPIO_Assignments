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
  static int switch_press = 0, LED_ON = 0;

   while(1){
    input = *inB;
    if(LED_ON == 0 && switch_press == 0){
      if((input & 0x01) == 0x01){
        debounce();
        switch_press = 1;
      }
    }
    else if(LED_ON == 0 && switch_press == 1){
      if((input&0x08) == 0x08){
        debounce();
        switch_press = 2;
      }
    }
    else if(LED_ON == 0 && switch_press == 2){
      if((input&0x40) == 0x40){
        debounce();
        switch_press = 3;
      }
    }
    else if(LED_ON == 0 && switch_press == 3){
      if((input&0x80) == 0x80){
        debounce();
        *outA = 0x10;
        LED_ON = 1;
        switch_press = 0;
      }
    }

    if(LED_ON == 1 && switch_press == 0){
      if((input & 0x08) == 0x08){
        debounce();
        switch_press = 1;
      }
    }
    else if(LED_ON == 1 && switch_press == 1){
      if((input&0x40) == 0x40){
        debounce();
        switch_press = 2;
      }
    }
    else if(LED_ON == 1 && switch_press == 2){
      if((input&0x80) == 0x80){
        debounce();
        switch_press = 3;
      }
    }
    else if(LED_ON == 1 && switch_press == 3){
      if((input&0x01) == 0x01){
        debounce();
        *outA = 0x00;
        LED_ON = 0;
      }
    }
  }
}
