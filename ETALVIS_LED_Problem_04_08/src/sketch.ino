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
  *portA_data = 0x55;
  delay();
  *portA_data = 0x00;
  delay();
  *portA_data = 0xAA;
  delay();
  *portA_data = 0x00;
  delay();
  *portB_data = 0xAA;
  delay();
  *portB_data = 0x00;
  delay();
  *portB_data = 0x55;
  delay();
  *portB_data = 0x00;
  delay();
  *portB_data = 0x55;
  delay();
  *portB_data = 0x00;
  delay();
  *portB_data = 0xAA;
  delay();
  *portB_data = 0x00;
  delay();
  *portA_data = 0xAA;
  delay();
  *portA_data = 0x00;
  delay();
  *portA_data = 0x55;
  delay();
  *portA_data = 0x00;
  delay();
}
  
  