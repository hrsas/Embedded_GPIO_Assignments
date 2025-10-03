#include "etalvis.h"
void setup() {
  // put your setup code here, to run once:
  volatile char *portA_dir = (char*) 0x21;
  *portA_dir = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x22;
  *data = 0b10001000; 
  delay();
  *data = 0b10000011; 
  delay();
  *data = 0b11000110; 
  delay();
  *data = 0b10100001;
  delay();
  *data = 0b10000110;
  delay();
  *data = 0b10001110;
  delay();
  // *data = 0b10001110;
  // delay();
  *data = 0b10010000;
  delay();
  *data = 0b10001001;
  delay();
  *data = 0b11111001; 
  delay();
  *data = 0b11110001;
  delay();
  *data = 0b11000111;
  delay();
  *data = 0b11000000;
  delay();
  *data = 0b10001100;
  delay();
  *data = 0b10011000; 
  delay();
  *data = 0b10010001; 
  delay();
  *data = 0b11000001; 
  delay();
  *data = 0b10010001; 
  delay();

}