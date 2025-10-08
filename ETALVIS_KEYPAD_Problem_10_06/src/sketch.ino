#include "keypad.h"
void setup() {
  // put your setup code here, to run once:
  volatile char *dirF = (char*)0x30, *dirK = (char*)0x107;
  volatile char *dirA = (char*)0x21, *dirB = (char*)0x24;
  *dirA = 0xFF; *dirB = 0xFF;
  *dirF = 0x0F; *dirK = 0x00; 
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int result = performAddition();
  display(result);
  
}
