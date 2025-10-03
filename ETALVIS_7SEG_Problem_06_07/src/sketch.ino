#include "etalvis.h"
void setup() {
  // put your setup code here, to run once:
  volatile char *portA_dir = (char*) 0x21;
  *portA_dir = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x22;
 *data = 0b11000000;
  delay();
  *data = 0b10100100;
  delay();
  *data = 0b10011001;
  delay();
  *data = 0b10000010;
  delay();
  *data = 0b10000000;
  delay();
}