void setup() {
  // put your setup code here, to run once:
  volatile char *portJ_DDR = (char*)0x104;
  *portJ_DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *data = (char*)0x105;
  volatile long i;
  *data = 1;
  for(i = 0; i<500000; i++);
  *data = 0;
  for(i = 0; i<500000; i++);
}
