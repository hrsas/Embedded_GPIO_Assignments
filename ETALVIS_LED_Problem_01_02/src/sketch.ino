void setup() {
  volatile char *portD_DDR;
  portD_DDR = 0x2A;
  *portD_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly: 
  volatile char *x;
  x = 0x2B;
  *x = 128;
}
