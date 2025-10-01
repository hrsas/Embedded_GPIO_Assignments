void setup() {
  // put your setup code here, to run once:
  volatile char *portC_DDR = (char*)0x27;
  *portC_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x28;
  volatile long i;
  for(volatile int x = 0; x<8; x++){
    *data = (1<<x);
    for(volatile long i = 0; i<50000; i++);
  }
}
