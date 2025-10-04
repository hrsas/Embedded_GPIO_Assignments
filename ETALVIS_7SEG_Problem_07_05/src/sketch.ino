#include "etalvis.h"
char arr[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101,0b01111101,0b00000111, 0b01111111, 0b01100111};
volatile int x = 0;
void setup() {
  // put your setup code here, to run once:
  volatile char *portA_DDR = (char*)0x21;
  volatile char *portB_DDR = (char*)0x24;
  *portA_DDR = 0xFF;
  *portB_DDR = 0xFF;

}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x22, *common = (char*)0x25;
  for(int i =0; i<10; i++){
    for(int j = 0;j<20; j++){
      *data = arr[i];
      *common = 0x02;
      for(volatile long i = 0; i<10000; i++);
      *common = 0x03;
      for(volatile long i = 0; i<1000; i++);
      *data = arr[x];
      *common = 0x01;
      for(volatile long i = 0; i<10000; i++);
      *common = 0x03;
      for(volatile long i = 0; i<1000; i++);
    }
  }
  x++;
  if(x == 10) x = 0;
}
