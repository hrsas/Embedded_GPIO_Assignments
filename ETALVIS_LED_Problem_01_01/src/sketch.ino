void setup() {
  // put your setup code here, to run once:
  volatile char *portJ_DDR;
  portJ_DDR = 0x104;
  *portJ_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *x;
  volatile long i;
  x = 0x105;
  *x = 1;
  for(i = 0; i<100000; i++);
  *x = 0;
  for(i = 0; i<100000; i++);
}
