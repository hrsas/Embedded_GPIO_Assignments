#include "etalvis.h"

void setup() {
  // put your setup code here, to run once:
  volatile char *ddrF = (char*)0x30;
  volatile char *ddrK = (char*)0x107;
  *ddrF = 0xFF; *ddrK = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  display_AtoE();
}
