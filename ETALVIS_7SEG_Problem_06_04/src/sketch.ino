#include "etalvis.h"
void setup() {
  // put your setup code here, to run once:
  volatile char *portA_dir = (char*) 0x21;
  *portA_dir = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x22;
  *data = 0b01000000;
  delay();
  *data = 0b01111001;
  delay();
  *data = 0b00100100;
  delay();
  *data = 0b00110000;
  delay();
  *data = 0b00011001;
  delay();
  *data = 0b00010010;
  delay();
  *data = 0b00000010;
  delay();
  *data = 0b01111000;
  delay();
  *data = 0b00000000;
  delay();
  *data = 0b00011000;
  delay();
}