void my_delay(void);
void send_1(uint8_t command, uint8_t data);
void send_2(uint8_t command1,uint8_t command2, uint8_t data1, uint8_t data2);
void device_setup(void);
void display(void);

volatile uint8_t *outA = (uint8_t *)0X22;

#define PORTA *outA
#define LOAD 0
#define CLOCK 1
#define DIN 2 

uint8_t display_1[8] = {0x10,0x18,0x14,0x10,0x10,0x10,0x10,0x7e};
uint8_t display_2[8] = {0x7e,0x40,0x40,0x7e,0x02,0x02,0x02,0x7e};

void my_delay(long x)
{
    for(volatile long i = 0; i<x; i++);
}

void send_2(uint8_t command1,uint8_t command2, uint8_t data1, uint8_t data2)
{
  PORTA &= ~(1 << LOAD);
  for(long i = 7; i>=0; i--)
  {
    PORTA &= ~(1 << CLOCK);
    if(command1 & (1 << i))
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
    if( data1 & (1 << j))
    {
      PORTA |= (1 << DIN);
    }else{
      PORTA &= ~(1 << DIN);
    }
    PORTA |= (1 << CLOCK);
  }

  for(long i = 7; i>=0; i--)
  {
    PORTA &= ~(1 << CLOCK);
    if(command2 & (1 << i))
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
    if( data2 & (1 << j))
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
  send_2(0x0F,0x0F,0x00, 0x00);  // Display test off
  send_2(0x0C,0x0C,0x01, 0x01);  // Shutdown off
  send_2(0x0B,0x0B,0x07, 0x07);  // Scan limit = 8 digits
  send_2(0x0A,0x0A,0x08, 0x08);  // Brightness
  send_2(0x09,0x09,0x00, 0x00);  // No decode

  for (int i = 1; i <= 8; i++){
    send_2(i,i,0x00,0x00);  // Clear all digits
  }
}

void display()
{
  for(volatile long i = 1; i<=8; i++){
    send_2(i,i,display_1[i-1], display_2[i-1]);
  }
}