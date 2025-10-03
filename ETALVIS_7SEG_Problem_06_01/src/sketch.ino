#include "etalvis.h"
void setup() {
  // put your setup code here, to run once:
  volatile char *portA_dir = (char*) 0x21;
  *portA_dir = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x22;
  *data = 0b00111111;
  delay();
  *data = 0b00000110;
  delay();
  *data = 0b01011011;
  delay();
  *data = 0b01001111;
  delay();
  *data = 0b01100110;
  delay();
  *data = 0b01101101;
  delay();
  *data = 0b01111101;
  delay();
  *data = 0b00000111;
  delay();
  *data = 0b01111111;
  delay();
  *data = 0b01100111;
  delay();
}