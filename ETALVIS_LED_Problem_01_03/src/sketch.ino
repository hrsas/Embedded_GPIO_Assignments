void setup() {
  // put your setup code here, to run once:
  volatile char *portH_DDR;
  portH_DDR = 0x101;
  *portH_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data;
  data = 0x102;
  *data = 3;
}
