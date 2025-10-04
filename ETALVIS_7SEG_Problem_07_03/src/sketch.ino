#include "etalvis.h"
static int x = 0;
void setup() {
  // put your setup code here, to run once:
  volatile char *portA_DDR = (char*)0x21;
  volatile char *portB_DDR = (char*)0x24;
  *portA_DDR = 0xFF;
  *portB_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly: 
  volatile char *data = (char*)0x25;
  //volatile char *data_B = (char*)0x25;
  if(x == 0){*data = 0b10111111; x++;}
  else if(x == 1){*data = 0b10000110; x++;}
  else if(x == 2){*data = 0b11011011; x++;}
  else if(x == 3){*data = 0b11001111; x++;}
  else if(x == 4){*data = 0b11100110; x++;}
  else if(x == 5){*data = 0b11101101; x++;}
  else if(x == 6){*data = 0b11111101; x++;}
  else if(x == 7){*data = 0b10000111; x++;}
  else if(x == 8){*data = 0b11111111; x++;}
  else{*data = 0b11100111; x = 0;}
  data = 0x22;
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
