void my_delay(volatile long x);
void display(void);

uint8_t W[8] = {0xBE, 0xBE, 0xBE, 0xB6, 0xB6, 0xB6, 0xB6, 0x80}; //W
uint8_t E[8] = {0xFF, 0x83, 0xBF, 0xBF, 0x83, 0xBF, 0xBF, 0x83}; //E
uint8_t L[8] = {0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0x81}; //L
uint8_t C[8] = {0x00, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x00}; //C
uint8_t O[8] = {0xE3, 0xDD, 0xBE, 0xBE, 0xBE, 0xBE, 0xDD, 0xE3}; //O
uint8_t M[8] =  {0xBE, 0x9C, 0xAA, 0xB6, 0xBE, 0xBE, 0xBE, 0xBE}; //M

/*array of uint8_t pointers to display words*/
uint8_t *welcome[7] = {W,E,L,C,O,M,E};

char rows[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

void my_delay(volatile long x) {
    for(volatile int i = 0; i < x; i++); 
}

void display(){
  volatile char *outF = (char*)0x31;
  volatile char *outK = (char*)0x108;
  *outF = 0x00;
  *outK = 0xFF;
  uint8_t shifted_data,mask;
  for(volatile long i = 0; i < 7; i++) {
    for(volatile long j = 0; j < 8; j++) {
      for(volatile long repeat = 0; repeat < 100; repeat++) {
        for(volatile long k = 0; k < 8; k++) {
          *outF = 0x00;
          shifted_data = welcome[i][k] >> j;
          mask = ~(0xFF >> j);      
          *outK = (shifted_data) | mask;
          *outF = rows[k];
          my_delay(100);              
        }
      }
    }
  }
}