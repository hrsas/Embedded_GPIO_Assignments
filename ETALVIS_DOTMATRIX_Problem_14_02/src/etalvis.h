void my_delay(void);
void send_1(uint8_t command, uint8_t data);
void device_setup(void);
void display(void);

volatile uint8_t *outA = (uint8_t *)0X22;

#define PORTA *outA
#define LOAD 0
#define CLOCK 1
#define DIN 2 

void my_delay(long x)
{
    for(volatile long i = 0; i<x; i++);
}

void send_1(uint8_t command, uint8_t data)
{
  PORTA &= ~(1 << LOAD);
  for(long i = 7; i>=0; i--)
  {
    PORTA &= ~(1 << CLOCK);
    if(command & (1 << i))
    {
      PORTA |= (1 << DIN); 
    }
    else 
    {
      PORTA &= ~(1 << DIN); 
    }
    PORTA |= (1 << CLOCK); 
  }

  for( long j = 7; j>=0; j--)
  {
    PORTA &= ~(1 << CLOCK);
    if( data & (1 << j))
    {
      PORTA |= (1 << DIN);
    }else{
      PORTA &= ~(1 << DIN);
    }
    PORTA |= (1 << CLOCK);
  }
  PORTA |= (1 << LOAD);
}

void device_setup(){
  send_1(0x0F, 0x00);  // Display test off
  send_1(0x0C, 0x01);  // Shutdown off
  send_1(0x0B, 0x07);  // Scan limit = 8 digits
  send_1(0x0A, 0x0F);  // Brightness
  send_1(0x09, 0x00);  // No decode

  for (int i = 1; i <= 8; i++)
    send_1(i,0x00);  // Clear all digits
}

void display()
{
  send_1(1 ,0x01);
}