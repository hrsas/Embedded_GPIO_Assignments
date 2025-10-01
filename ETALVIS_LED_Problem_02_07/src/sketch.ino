void setup() {
  // put your setup code here, to run once:
  volatile char *portL_DDR = (char*)0x10A;
  *portL_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x10B;
  volatile long i;
  *data = 0b00000000;
  for(volatile long i = 0; i<100000; i++);
  for(volatile int x = 0; x<4; x++){
    *data = (1<<x);
    for(volatile long i = 0; i<100000; i++);
  }
}
