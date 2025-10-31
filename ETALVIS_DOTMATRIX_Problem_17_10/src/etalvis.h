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
#define LOAD_1 4
#define CLOCK_1 5
#define DIN_1 6 

uint8_t M1[8]  = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
uint8_t M2[8]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8_t M3[8]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8_t M4[8]  = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
uint8_t M5[8]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8_t M6[8]  = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
uint8_t M7[8]  = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
uint8_t M8[8]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8_t M9[8]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8_t M10[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
uint8_t M11[8] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
uint8_t M12[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8_t M13[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
uint8_t M14[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8_t M15[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8_t M16[8] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};

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

void send_4_C(uint8_t cmd1,uint8_t cmd2,uint8_t cmd3,uint8_t cmd4, 
             uint8_t dat1, uint8_t dat2,uint8_t dat3, uint8_t dat4)
{
  PORTA &= ~(1 << LOAD_1);
  for (int chip = 0; chip < 4; chip++) {
    uint8_t command, data;

    switch (chip) {
      case 0: command = cmd1; data = dat1; break;
      case 1: command = cmd2; data = dat2; break;
      case 2: command = cmd3; data = dat3; break;
      case 3: command = cmd4; data = dat4; break;
    }

    for (int i = 7; i >= 0; i--) {
      PORTA &= ~(1 << CLOCK_1);
      if (command & (1 << i)) PORTA |= (1 << DIN_1);
      else PORTA &= ~(1 << DIN_1);
      PORTA |= (1 << CLOCK_1);
    }

    for (int i = 7; i >= 0; i--) {
      PORTA &= ~(1 << CLOCK_1);
      if (data & (1 << i)) PORTA |= (1 << DIN_1);
      else PORTA &= ~(1 << DIN_1);
      PORTA |= (1 << CLOCK_1);
    }
  }
  PORTA |= (1 << LOAD_1); 
}

void send_4_D(uint8_t cmd1,uint8_t cmd2,uint8_t cmd3,uint8_t cmd4, 
             uint8_t dat1, uint8_t dat2,uint8_t dat3, uint8_t dat4)
{
  PORTB &= ~(1 << LOAD_1);
  for (int chip = 0; chip < 4; chip++) {
    uint8_t command, data;

    switch (chip) {
      case 0: command = cmd1; data = dat1; break;
      case 1: command = cmd2; data = dat2; break;
      case 2: command = cmd3; data = dat3; break;
      case 3: command = cmd4; data = dat4; break;
    }

    for (int i = 7; i >= 0; i--) {
      PORTB &= ~(1 << CLOCK_1);
      if (command & (1 << i)) PORTB |= (1 << DIN_1);
      else PORTB &= ~(1 << DIN_1);
      PORTB |= (1 << CLOCK_1);
    }

    for (int i = 7; i >= 0; i--) {
      PORTB &= ~(1 << CLOCK_1);
      if (data & (1 << i)) PORTB |= (1 << DIN_1);
      else PORTB &= ~(1 << DIN_1);
      PORTB |= (1 << CLOCK_1);
    }
  }
  PORTB |= (1 << LOAD_1); 
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

  send_4_C(0x0F,0x0F,0x0F,0x0F, 0x00, 0x00,0x00,0x00);  // Display test off
  send_4_C(0x0C,0x0C,0x0C,0x0C, 0x01, 0x01, 0x01, 0x01);  // Shutdown off
  send_4_C(0x0B,0x0B,0x0B,0x0B, 0x07, 0x07,0x07, 0x07);  // Scan limit = 8 digits
  send_4_C(0x0A,0x0A,0x0A,0x0A, 0x08, 0x08, 0x08, 0x08);  // Brightness
  send_4_C(0x09,0x09,0x09,0x09, 0x00, 0x00, 0x00, 0x00);  // No decode

  send_4_D(0x0F,0x0F,0x0F,0x0F, 0x00, 0x00,0x00,0x00);  // Display test off
  send_4_D(0x0C,0x0C,0x0C,0x0C, 0x01, 0x01, 0x01, 0x01);  // Shutdown off
  send_4_D(0x0B,0x0B,0x0B,0x0B, 0x07, 0x07,0x07, 0x07);  // Scan limit = 8 digits
  send_4_D(0x0A,0x0A,0x0A,0x0A, 0x08, 0x08, 0x08, 0x08);  // Brightness
  send_4_D(0x09,0x09,0x09,0x09, 0x00, 0x00, 0x00, 0x00);  // No decode

  for (int i = 1; i <= 8; i++){
    send_4_A(i,i,i,i,0x00,0x00,0x00,0x00);  // Clear all digits
    send_4_B(i,i,i,i,0x00,0x00,0x00,0x00);  // Clear all digits
    send_4_C(i,i,i,i,0x00,0x00,0x00,0x00);  // Clear all digits
    send_4_D(i,i,i,i,0x00,0x00,0x00,0x00);  // Clear all digits
  }
}


void display() {
  for(int i = 1; i<=8; i++){
    send_4_A(i,i,i,i,M4[i-1],M3[i-1],M2[i-1],M1[i-1]);
    my_delay(50000);
    send_4_B(i,i,i,i,0,0,0,0);
    send_4_C(i,i,i,i,0,0,0,0);
    send_4_D(i,i,i,i,0,0,0,0);
  }
  for(int i = 1; i<=8; i++){
    send_4_A(i,i,i,i,M4[i-1],M3[i-1],M2[i-1],M1[i-1]);
    send_4_B(i,i,i,i,M8[i-1],M7[i-1],M6[i-1],M5[i-1]);
    my_delay(50000);
    send_4_C(i,i,i,i,0,0,0,0);
    send_4_D(i,i,i,i,0,0,0,0);
  }
  for(int i = 1; i<=8; i++){
    send_4_A(i,i,i,i,M4[i-1],M3[i-1],M2[i-1],M1[i-1]);
    send_4_B(i,i,i,i,M8[i-1],M7[i-1],M6[i-1],M5[i-1]);
    send_4_C(i,i,i,i,M12[i-1],M11[i-1],M10[i-1],M9[i-1]);
    my_delay(50000);
    send_4_D(i,i,i,i,0,0,0,0);
  }
  for(int i = 1; i<=8; i++){
    send_4_A(i,i,i,i,M4[i-1],M3[i-1],M2[i-1],M1[i-1]);
    send_4_B(i,i,i,i,M8[i-1],M7[i-1],M6[i-1],M5[i-1]);
    send_4_C(i,i,i,i,M12[i-1],M11[i-1],M10[i-1],M9[i-1]);
    send_4_D(i,i,i,i,M16[i-1],M15[i-1],M14[i-1],M13[i-1]);
    my_delay(50000);
  }
  my_delay(50000);
  for (int i = 1; i <= 8; i++){
    send_4_A(i,i,i,i,0x00,0x00,0x00,0x00); 
    send_4_B(i,i,i,i,0x00,0x00,0x00,0x00);  
    send_4_C(i,i,i,i,0x00,0x00,0x00,0x00);  
    send_4_D(i,i,i,i,0x00,0x00,0x00,0x00);  
  }
}
