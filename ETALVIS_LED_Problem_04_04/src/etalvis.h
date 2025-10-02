void delay(void);
void init(void);

void delay(void){
  for(volatile long i = 0; i<250000; i++);
}

void init(){
  volatile char *portA_DDR = (char*)0x21;
  volatile char *portB_DDR = (char*)0x24;
  *portA_DDR = 0xFF;
  *portB_DDR = 0xFF;
}