#include "etalvis.h"

void setup() {
  // put your setup code here, to run once:
  volatile char *ddrA = (char*)0x21, *ddrB = (char*) 0x24;
  *ddrA = 0x0F; *ddrB = 0x0F;
  device_setup();
} 
   
void loop() {
  // put your main code here, to run repeatedly:
  display();
}
