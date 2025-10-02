#include "etalvis.h"

void setup() {
  // put your setup code here, to run once:
  volatile char *portA_DDR = (char*)0x21;
  *portA_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x22;
  *data = 0;
  for(int x = 7; x>=0; x--){
    *data = (*data)|(1<<x);
    delay();
  }
}
  
  