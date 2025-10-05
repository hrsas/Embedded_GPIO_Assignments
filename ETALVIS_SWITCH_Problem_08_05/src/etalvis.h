void delay(void);

void delay(){
  for(volatile long i = 0; i<100000; i++);
}