#include "etalvis.h"

void setup() {
  // put your setup code here, to run once:
  volatile char *portA_DDR = (char*)0x21;
  *portA_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x22;
  *data = 0b10001000;
  delay();
  *data = 0b01000100;
  delay();
  *data = 0b00100010;
  delay();
  *data = 0b00010001;
  delay();
}
