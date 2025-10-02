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

  *portA_data = 0x01;
  *portB_data = 0x01;
  delay();
  *portA_data = 0x00;
  *portB_data = 0x00;
  delay();
  *portA_data = 0x02;
  *portB_data = 0x02;
  delay();
  *portA_data = 0x00;
  *portB_data = 0x00;
  delay();
  *portA_data = 0x04;
  *portB_data = 0x04;
  delay();
  *portA_data = 0x00;
  *portB_data = 0x00;
  delay();
  *portA_data = 0x08;
  *portB_data = 0x08;
  delay();
  *portA_data = 0x00;
  *portB_data = 0x00;
  delay();
  *portA_data = 0x10;
  *portB_data = 0x10;
  delay();
  *portA_data = 0x00;
  *portB_data = 0x00;
  delay();
  *portA_data = 0x20;
  *portB_data = 0x20;
  delay();
  *portA_data = 0x00;
  *portB_data = 0x00;
  delay();
  *portA_data = 0x40;
  *portB_data = 0x40;
  delay();
  *portA_data = 0x00;
  *portB_data = 0x00;
  delay();
  *portA_data = 0x80;
  *portB_data = 0x80;
  delay();
  *portA_data = 0x00;
  *portB_data = 0x00;
  delay();
}
  
  