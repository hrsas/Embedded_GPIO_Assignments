void setup() {
  // put your setup code here, to run once:
  volatile char *portK_DDR = (char*)0x107;
  *portK_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x108;
  volatile long i;
  *data = 0b00000000;
  for(volatile long i = 0; i<100000; i++);
  for(volatile int x = 1; x<8; x+=2){
    *data = (*data)|(1<<x);
    for(volatile long i = 0; i<100000; i++);
  }
}
