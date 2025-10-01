void setup() {
  // put your setup code here, to run once:
  volatile char *portC_DDR;
  portC_DDR = 0x27;
  *portC_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data;
  data = 0x28;
  *data = 192;
}
