void setup() {
  // put your setup code here, to run once:
  volatile char *portA_DDR = (char*)0x21;
  volatile char *portB_DDR = (char*)0x24;
  *portA_DDR = 0xFF;
  *portB_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly: 
  volatile char *data = (char*)0x22;
  //volatile char *data_B = (char*)0x25;
  *data = 0b01101101;
  data = 0x25;
  *data = 0b01011011;
  
}
