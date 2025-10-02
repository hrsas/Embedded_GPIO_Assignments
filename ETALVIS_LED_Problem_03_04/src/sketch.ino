#include "etalvis.h"

void setup() {
  // put your setup code here, to run once:
  volatile char *portA_DDR = (char*)0x21;
  *portA_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x22;
  *data = 0b00000001;
  delay();
  *data = 0b00000101;
  delay();
  *data = 0b00000111;
  delay();
  *data = 0b00001111;
  delay();
  *data = 0b00011111;
  delay();
  *data = 0b01011111;
  delay();
  *data = 0b01111111;
  delay();
  *data = 0b11111111;
  delay();

}
  
