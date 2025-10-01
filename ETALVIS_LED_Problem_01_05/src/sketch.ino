void setup() {
  // put your setup code here, to run once:
  volatile char *portA_DDR;
  portA_DDR = 0x21;
  *portA_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data;
  data = 0x22;
  *data = 15;
}
