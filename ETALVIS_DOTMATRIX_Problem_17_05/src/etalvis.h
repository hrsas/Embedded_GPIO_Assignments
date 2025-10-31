void my_delay(void);
void send_4(uint8_t command1,uint8_t command2,uint8_t command3,uint8_t command4, uint8_t data1, uint8_t data2,uint8_t data3, uint8_t data4);
void device_setup(void);
void display(void);

volatile uint8_t *outA = (uint8_t *)0X22;
volatile uint8_t *outB = (uint8_t *)0X25;
#define PORTA *outA
#define PORTB *outB
#define LOAD 0
#define CLOCK 1
#define DIN 2 

uint8_t display_E[8] = {0x7e,0x02,0x02,0x7e,0x02,0x02,0x02,0x7e};
uint8_t display_T[8] = {0x7e,0x18,0x18,0x18,0x18,0x18,0x18,0x18};
uint8_t display_A[8] = {0x7e,0x42,0x42,0x7e,0x42,0x42,0x42,0x42};
uint8_t display_L[8] = {0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x7e};

uint8_t display_1[8] = {0x10,0x18,0x14,0x10,0x10,0x10,0x10,0x7e};
uint8_t display_2[8] = {0x7e,0x40,0x40,0x7e,0x02,0x02,0x02,0x7e};
uint8_t display_3[8] = {0x7e,0x40,0x40,0x7e,0x40,0x40,0x40,0x7e};
uint8_t display_4[8] = {0x42,0X42,0X42,0X7E,0X40,0X40,0X40,0x40};
void my_delay(long x)
{
    for(volatile long i = 0; i<x; i++);
}

void send_4_A(uint8_t cmd1,uint8_t cmd2,uint8_t cmd3,uint8_t cmd4, 
             uint8_t dat1, uint8_t dat2,uint8_t dat3, uint8_t dat4)
{
  PORTA &= ~(1 << LOAD);
  for (int chip = 0; chip < 4; chip++) {
    uint8_t command, data;

    switch (chip) {
      case 0: command = cmd1; data = dat1; break;
      case 1: command = cmd2; data = dat2; break;
      case 2: command = cmd3; data = dat3; break;
      case 3: command = cmd4; data = dat4; break;
    }

    for (int i = 7; i >= 0; i--) {
      PORTA &= ~(1 << CLOCK);
      if (command & (1 << i)) PORTA |= (1 << DIN);
      else PORTA &= ~(1 << DIN);
      PORTA |= (1 << CLOCK);
    }

    for (int i = 7; i >= 0; i--) {
      PORTA &= ~(1 << CLOCK);
      if (data & (1 << i)) PORTA |= (1 << DIN);
      else PORTA &= ~(1 << DIN);
      PORTA |= (1 << CLOCK);
    }
  }
  PORTA |= (1 << LOAD); 
}

void send_4_B(uint8_t cmd1,uint8_t cmd2,uint8_t cmd3,uint8_t cmd4, 
             uint8_t dat1, uint8_t dat2,uint8_t dat3, uint8_t dat4)
{
  PORTB &= ~(1 << LOAD);
  for (int chip = 0; chip < 4; chip++) {
    uint8_t command, data;

    switch (chip) {
      case 0: command = cmd1; data = dat1; break;
      case 1: command = cmd2; data = dat2; break;
      case 2: command = cmd3; data = dat3; break;
      case 3: command = cmd4; data = dat4; break;
    }

    for (int i = 7; i >= 0; i--) {
      PORTB &= ~(1 << CLOCK);
      if (command & (1 << i)) PORTB |= (1 << DIN);
      else PORTB &= ~(1 << DIN);
      PORTB |= (1 << CLOCK);
    }

    for (int i = 7; i >= 0; i--) {
      PORTB &= ~(1 << CLOCK);
      if (data & (1 << i)) PORTB |= (1 << DIN);
      else PORTB &= ~(1 << DIN);
      PORTB |= (1 << CLOCK);
    }
  }
  PORTB |= (1 << LOAD); 
}

void device_setup() {
  send_4_A(0x0F,0x0F,0x0F,0x0F, 0x00, 0x00,0x00,0x00);  // Display test off
  send_4_A(0x0C,0x0C,0x0C,0x0C, 0x01, 0x01, 0x01, 0x01);  // Shutdown off
  send_4_A(0x0B,0x0B,0x0B,0x0B, 0x07, 0x07,0x07, 0x07);  // Scan limit = 8 digits
  send_4_A(0x0A,0x0A,0x0A,0x0A, 0x08, 0x08, 0x08, 0x08);  // Brightness
  send_4_A(0x09,0x09,0x09,0x09, 0x00, 0x00, 0x00, 0x00);  // No decode

  send_4_B(0x0F,0x0F,0x0F,0x0F, 0x00, 0x00,0x00,0x00);  // Display test off
  send_4_B(0x0C,0x0C,0x0C,0x0C, 0x01, 0x01, 0x01, 0x01);  // Shutdown off
  send_4_B(0x0B,0x0B,0x0B,0x0B, 0x07, 0x07,0x07, 0x07);  // Scan limit = 8 digits
  send_4_B(0x0A,0x0A,0x0A,0x0A, 0x08, 0x08, 0x08, 0x08);  // Brightness
  send_4_B(0x09,0x09,0x09,0x09, 0x00, 0x00, 0x00, 0x00);  // No decode

  for (int i = 1; i <= 8; i++){
    send_4_A(i,i,i,i,0x00,0x00,0x00,0x00);  // Clear all digits
    send_4_B(i,i,i,i,0x00,0x00,0x00,0x00);  // Clear all digits
  }
}


void display() {
  for(int i = 1; i<=8; i++){
    send_4_A(i,i,i,i,display_E[i-1],display_T[i-1],display_A[i-1],display_L[i-1]);
    send_4_B(i,i,i,i,display_1[i-1],display_2[i-1],display_3[i-1],display_4[i-1]);
  }
}
