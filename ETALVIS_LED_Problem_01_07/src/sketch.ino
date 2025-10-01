void setup() {
  // put your setup code here, to run once:
  volatile char *portF_DDR = (char*)0x30;
  *portF_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly: 
  volatile char *data = (char*)0x31;
  *data = 0xFF;
}
