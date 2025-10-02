void delay(void);

void delay(void){
  for(volatile long i = 0; i<250000; i++);
}