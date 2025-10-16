void setup() {
  // put your setup code here, to run once:
  volatile char *ddrF = (char*)0x30;
  volatile char *ddrK = (char*)0x107;
  *ddrF = 0xFF; *ddrK = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *outF = (char*)0x31;
  volatile char *outK = (char*)0x108;
  *outF = 0x01;
  *outK = 0x7F;
  for(volatile int i = 0; i<5000; i++);
  *outF = 0x02;
  *outK = 0xBF;
  for(volatile int i = 0; i<5000; i++);
    *outF = 0x04;
  *outK = 0xDF;
  for(volatile int i = 0; i<5000; i++);
  *outF = 0x08;
  *outK = 0xEF;
  for(volatile int i = 0; i<5000; i++);
  *outF = 0x10;
  *outK = 0xF7;
  for(volatile int i = 0; i<5000; i++);
    *outF = 0x20;
  *outK = 0xFB;
  for(volatile int i = 0; i<5000; i++);
    *outF = 0x40;
  *outK = 0xFD;
  for(volatile int i = 0; i<5000; i++);
  *outF = 0x80;
  *outK = 0xFE;
  for(volatile int i = 0; i<5000; i++);
}
