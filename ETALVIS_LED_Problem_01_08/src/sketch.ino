void setup() {
  // put your setup code here, to run once:
  volatile char *portK_DDR = (char*) 0x107;
  *portK_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly: 
  volatile char *data;
  data = 0x108;
  *data = 0b10101010;
}
