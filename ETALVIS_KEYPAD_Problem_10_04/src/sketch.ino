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
  volatile char *outA = (char*)0x22;//controls 7-Segment display
  volatile char *outB = (char*)0x25;//controls digit of 7-Segment display
  volatile long i,j;
  char dig[4];
  int res[3];
  dig[0] = waitForKeypad();
  dig[1] = waitForKeypad();
  dig[2] = waitForKeypad();
  dig[3] = waitForKeypad();

  int result = ((dig[0]-'0')*10 + (dig[1]-'0')) + ((dig[2]-'0')*10 + (dig[3]-'0'));

  res[0] = result%10;
  result = result/10;
  res[1] = result%10;
  result = result/10;
  res[2] = result;
  for(j = 0; j<500; j++){
    *outA = getBinary(res[0]); 
    *outB = 0xE0;
    for(i = 0; i<1000; i++);
    *outB = 0xF0; 
    for(i = 0; i<100; i++);

    *outA = getBinary(res[1]);
    *outB = 0xD0;
    for(i = 0; i<1000; i++);
    *outB = 0xF0; 
    for(i = 0; i<100; i++);

    *outA = getBinary(res[2]);
    *outB = 0xB0;
    for(i = 0; i<1000; i++);
    *outB = 0xF0; 
    for(i = 0; i<100; i++);
  }
}
