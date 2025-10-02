#include "etalvis.h"

void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *portA_data = (char*)0x22;
  volatile char *portB_data = (char*)0x25;
  for(volatile int x = 0; x<8; x+=2){
    *portA_data = (3<<x);
    delay();
    *portA_data = 0x00;
    delay();
  }
  for(volatile int x = 6; x>=0; x-=2){
    *portB_data = (3<<x);
    delay();
    *portB_data = 0x00;
    delay();
  }
  for(volatile int x = 0; x<8; x+=2){
    *portB_data = (3<<x);
    delay();
    *portB_data = 0x00;
    delay();
  }
  for(volatile int x = 6; x>=0; x-=2){
    *portA_data = (3<<x);
    delay();
    *portA_data = 0x00;
    delay();
  }
  
}
  
  