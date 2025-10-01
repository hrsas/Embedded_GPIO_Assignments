void setup() {
  // put your setup code here, to run once:
  volatile char *portL_DDR = (char*)0x10A;
  *portL_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x10B;
  *data = 0b01010101;
}
