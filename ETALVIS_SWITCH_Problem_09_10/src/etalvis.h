void delay(void);
void debounce(void);

void delay(){
  for(volatile long i = 0; i<300000; i++);
}
void debounce(){
  for(int i = 0; i<5000; i++);
}