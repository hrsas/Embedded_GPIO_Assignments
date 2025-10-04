void setup() {
  // put your setup code here, to run once:
  volatile char *DDR = (char*)0x21;
  *DDR = 0xFF;
  DDR = 0x24;
  *DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly: 
  volatile char *data = (char*)0x22, *common = (char*)0x25;

  *data = 0b01101101;
  *common = 0x0E;
  for(volatile long i = 0; i<10000; i++);
  *common = 0x0F;
  for(int i = 0; i <1000; i++);

  *data = 0b01011011;
  *common = 0x0D;
  for(volatile long i = 0; i<10000; i++);
  *common = 0x0F;
  for(int i = 0; i <1000; i++);

  *data = 0b00111111;
  *common = 0x0B;
  for(volatile long i = 0; i<10000; i++);
  *common = 0x0F;
  for(int i = 0; i <1000; i++);

  *data = 0b01011011;
  *common = 0x07;
  for(volatile long i = 0; i<10000; i++);
  *common = 0x0F;
  for(int i = 0; i <1000; i++);
}
