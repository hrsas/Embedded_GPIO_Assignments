void setup() {
  // put your setup code here, to run once:
  volatile char *portE_DDR = (char*)0x2D;
  *portE_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x2E;
  *data = 0b00111010;
}
