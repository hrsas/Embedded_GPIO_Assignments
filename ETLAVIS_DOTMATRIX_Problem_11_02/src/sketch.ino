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
}
  
