void delay(void);

void delay(){
  for(volatile long i = 0; i<400000; i++);
}