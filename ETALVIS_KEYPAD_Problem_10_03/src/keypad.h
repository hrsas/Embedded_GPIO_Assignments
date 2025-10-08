void scan(void);
char readKeypad(void);
char waitForKeypad(void);

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