void setup() {
  // put your setup code here, to run once:
  volatile char *portB_DDR = (char*)0x24;
  *portB_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x25;
  volatile long i;
  *data = 0b00000000;
  for(volatile int x = 0; x<8; x++){
    *data = (*data)|(1<<x);
    for(volatile long i = 0; i<100000; i++);
  }
}
