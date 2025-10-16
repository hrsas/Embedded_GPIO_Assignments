void setup() {
  // put your setup code here, to run once:
  volatile char *ddrA = (char*)0x21;
  volatile char *ddrB = (char*)0x24;
  *ddrA = 0xFF; *ddrB = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *outA = (char*)0x22;
  volatile char *outB = (char*)0x25;
  *outA = 0x01;
  *outB = 0xFE;
}
