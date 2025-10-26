void my_delay(void);
void send_4(uint8_t command1,uint8_t command2,uint8_t command3,uint8_t command4, uint8_t data1, uint8_t data2,uint8_t data3, uint8_t data4);
void device_setup(void);
void display(void);

volatile uint8_t *outA = (uint8_t *)0X22;

#define PORTA *outA
#define LOAD 0
#define CLOCK 1
#define DIN 2 

uint8_t display_E[8] = {0x7e,0x02,0x02,0x7e,0x02,0x02,0x02,0x7e};
uint8_t display_T[8] = {0x7e,0x18,0x18,0x18,0x18,0x18,0x18,0x18};
uint8_t display_A[8] = {0x7e,0x42,0x42,0x7e,0x42,0x42,0x42,0x42};
uint8_t display_L[8] = {0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x7e};


void my_delay(long x)
{
    for(volatile long i = 0; i<x; i++);
}

void send_4(uint8_t command1,uint8_t command2,uint8_t command3,uint8_t command4, uint8_t data1, uint8_t data2,uint8_t data3, uint8_t data4)
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

  for(long i = 7; i>=0; i--)
  {
    PORTA &= ~(1 << CLOCK);
    if(command3 & (1 << i))
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
    if( data3 & (1 << j))
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
    if(command4 & (1 << i))
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
    if( data4 & (1 << j))
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
  send_4(0x0F,0x0F,0x0F,0x0F, 0x00, 0x00,0x00,0x00);  // Display test off
  send_4(0x0C,0x0C,0x0C,0x0C, 0x01, 0x01, 0x01, 0x01);  // Shutdown off
  send_4(0x0B,0x0B,0x0B,0x0B,0x07, 0x07,0x07, 0x07);  // Scan limit = 8 digits
  send_4(0x0A,0x0A,0x0A,0x0A, 0x08, 0x08, 0x08, 0x08);  // Brightness
  send_4(0x09,0x09,0x09,0x09, 0x00, 0x00, 0x00, 0x00);  // No decode

  for (int i = 1; i <= 8; i++){
    send_4(i,i,i,i,0x00,0x00,0x00, 0x00);  // Clear all digits
  }
}

void display()
{

  for (int i = 1; i <= 8; i++) {
    send_4(i, i, i, i, 0x00, 0x00, 0x00, 0x00);
  }
  for (int i = 1; i <= 8; i++) {
    send_4(i, i, i, i, display_E[i-1], display_T[i-1], display_A[i-1], display_L[i-1]);
    my_delay(100000); 
  }
  
  for (int i = 1; i <= 8; i++) {
    send_4(i, i, i, i, 0x00, 0x00, 0x00, 0x00);
  }
  my_delay(100000);
}