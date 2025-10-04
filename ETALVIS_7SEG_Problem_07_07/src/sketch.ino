char arr[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101,0b01111101,0b00000111, 0b01111111, 0b01100111};
void setup() {
  // put your setup code here, to run once:
  volatile char *DDR;
  DDR = 0x21; //A
  *DDR = 0xFF;
  DDR = 0x24; //B
  *DDR = 0xFF;
  DDR = 0x30; //F
  *DDR = 0xFF;
  DDR = 0x107; //K
  *DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly: 
  volatile char *data;
    for(int i = 0; i<10; i++){
      for(int j = 0; j<10; j++){
        for(int k = 0; k<10; k++){
          for(int l = 0; l<10; l++){
            data = 0x22;
            *data = arr[l];
            for(volatile long m = 0; m<50000; m++);
            data = 0x25;
            *data = arr[k];
            data = 0x31;
            *data = arr[j];
            data = 0x108;
            *data = arr[i];
            for(volatile long m = 0; m<1000; m++);
          }
        }
      }
    }
}
