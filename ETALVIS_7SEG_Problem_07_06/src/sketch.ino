void setup() {
  // put your setup code here, to run once:
  volatile char *DDR;
  DDR = 0x21; //A
  *DDR = 0xFF;
  DDR = 0x24; //B
  *DDR = 0xFF;
  DDR = 0x30; //F
  *DDR = 0xFF;
  DDR = 0x107; //K
  *DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly: 
  volatile char *data;
  data = 0x22;
  *data = 0b01101101;
  data = 0x25;
  *data = 0b01011011;
  data = 0x31;
  *data = 0b00111111;
  data = 0x108;
  *data = 0b01011011;
}
