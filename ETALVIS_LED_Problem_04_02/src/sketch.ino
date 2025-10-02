#include "etalvis.h"

void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *portA_data = (char*)0x22;
  volatile char *portB_data = (char*)0x25;
  *portA_data = 0xFF;
  *portB_data = 0x00;
  delay();
  *portA_data = 0x00;
  *portB_data = 0xFF;
  delay();
}
  
  