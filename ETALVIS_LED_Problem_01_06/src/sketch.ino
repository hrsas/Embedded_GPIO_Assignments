void setup() {
  // put your setup code here, to run once:
  volatile char *portB_DDR = (char*)0x24;
  *portB_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*) 0x25;
  *data = 240;
}
