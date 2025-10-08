char keypad[4][4] = {{0b00000110, 0b01011011, 0b01001111, 0b01110111}, // 1 2 3 A
                     {0b01100110, 0b01101101, 0b01111101, 0b01111100}, //4 5 6 B
                     {0b00000111, 0b01111111, 0b01100111, 0b00111001}, //7 8 9 C
                     {0b00000000, 0b00111111, 0b00000000, 0b01011110}};//0 0 0 D

void setup() {
  // put your setup code here, to run once:
  volatile char *dirF = (char*)0x30, *dirK = (char*)0x107;
  volatile char *dirA = (char*)0x21, *dirB = (char*)0x24;
  *dirA = 0xFF; *dirB = 0xFF;
  *dirF = 0x0F; *dirK = 0x00; 
 
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *outA = (char*)0x22;//controls 7-Segment display
  volatile char *outB = (char*)0x25;//controls digit of 7-Segment display
  volatile char *outF = (char*)0x31;//used to make rows of Keypad HIGH
  volatile char *inK = (char*)0x106;//used to get column value from Keypad
  volatile long i,j;
  while(1){
    for(i = 0; i < 4; i++){
        *outF = (1 << i);   
        char col_val = *inK & 0x0F;
        int col_index = -1;

        for(int k = 0; k < 4; k++){
            if(col_val & (1 << k)){
                col_index = k;
                break;
            }
        }

        if(col_index != -1){
            *outA = keypad[i][col_index];  
            *outB = 0xE0;
            for(j = 0; j < 50000; j++); 
            *outA = 0x00;
        }
    }
  }
}
