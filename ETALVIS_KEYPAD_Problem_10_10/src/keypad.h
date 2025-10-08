void scan(void);
char readKeypad(void);
char waitForKeypad(void);
long long performDivision(void);
void display(long long result);

char keypad[4][4] = {{'1', '2', '3', 'A'}, // 1 2 3 A
                     {'4', '5', '6', 'B'}, //4 5 6 B
                     {'7', '8', '9', 'C'}, //7 8 9 C
                     {'0', '0', '0', 'C'}};//0 0 0 D

char arr[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101,0b01111101,0b00000111, 0b01111111, 0b01100111};
     
char readKeypad() {
    volatile char *outF = (char*)0x31; // rows
    volatile char *inK  = (char*)0x106; // cols

    for (int i = 0; i < 4; i++) {
        *outF = (1 << i);       
        char col_val = *inK & 0x0F;

        for (int k = 0; k < 4; k++) {
            if (col_val & (1 << k)) {
                
                while (*inK & (1 << k));
                return keypad[i][k];  
            }
        }
    }
    return 0; 
}

char waitForKeypad() {
  char key = 0;
  do {
    key = readKeypad();
  } while (key == 0);
  return key;
}

char getBinary(int x){
  return arr[x];
}

long long performDivision(){
  char dig[8];
  dig[0] = waitForKeypad();
  dig[1] = waitForKeypad();
  dig[2] = waitForKeypad();
  dig[3] = waitForKeypad();
  dig[4] = waitForKeypad();
  dig[5] = waitForKeypad();
  dig[6] = waitForKeypad();
  dig[7] = waitForKeypad();

  long long num1 = (dig[0]-'0')*1000 + (dig[1]-'0')*100 + (dig[2]-'0')*10 + (dig[3]-'0');
  long long num2 = (dig[4]-'0')*1000 + (dig[5]-'0')*100 + (dig[6]-'0')*10 + (dig[7] - '0');
  return num1%num2;
}

void display(long long result){
  volatile char *outA = (char*)0x22;//controls 7-Segment display
  volatile char *outB = (char*)0x25;//controls digit of 7-Segment display
  volatile long i,j;
    int res[4];
    res[0] = result%10;
    result /=10;
    res[1] = result%10;
    result /= 10;
    res[2] = result%10;
    result /= 10;
    res[3] = result;

    for(j = 0; j<500; j++){
      *outA = getBinary(res[0]); 
      *outB = 0xE0;
      for(i = 0; i<1000; i++);
      *outB = 0xF0; 
      for(i = 0; i<100; i++);

      *outA = getBinary(res[1]);
      *outB = 0xD0;
      for(i = 0; i<1000; i++);
      *outB = 0xF0; 
      for(i = 0; i<100; i++);

      *outA = getBinary(res[2]);
      *outB = 0xB0;
      for(i = 0; i<1000; i++);
      *outB = 0xF0; 
      for(i = 0; i<100; i++);

      *outA = getBinary(res[3]);
      *outB = 0x70;
      for(i = 0; i<1000; i++);
      *outB = 0xF0; 
      for(i = 0; i<100; i++);
      *outA = 0;
    }
}
