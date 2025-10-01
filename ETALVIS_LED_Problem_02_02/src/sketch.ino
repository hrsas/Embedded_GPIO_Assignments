void setup() {
  // put your setup code here, to run once:
  volatile char *portA_DDR = (char*)0x21;
  *portA_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x22;
  volatile long i;
  *data = 0xFF;
  for(i = 0; i<500000; i++);
  *data = 0x00;
  for(i = 0; i<500000; i++);
}
