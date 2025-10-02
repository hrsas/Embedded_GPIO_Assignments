#include "etalvis.h"

void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *portA_data = (char*)0x22;
  volatile char *portB_data = (char*)0x25;
  *portA_data = 0;
  *portB_data = 0;
  for(volatile int x = 0; x<5; x+=4){
    *portA_data = (0b00001111<<x);
    delay();
    *portA_data = 0x00;
    delay();
  }
  for(volatile int x = 4; x>=0; x-=4){
    *portB_data = (15<<x);
    delay();
    *portB_data = 0x00;
    delay();
  }
  for(volatile int x = 0; x<5; x+=4){
    *portB_data = (15<<x);
    delay();
    *portB_data = 0x00;
    delay();
  }
  for(volatile int x = 4; x>=0; x-=4){
    *portA_data = (15<<x);
    delay();
    *portA_data = 0x00;
    delay();
  }
}
  
  