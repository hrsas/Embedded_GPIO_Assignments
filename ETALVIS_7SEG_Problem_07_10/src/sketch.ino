char arr[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101,0b01111101,0b00000111, 0b01111111, 0b01100111};
char dec[10] = {0b10111111, 0b10000110, 0b11011011, 0b11001111, 0b11100110, 0b11101101,0b11111101,0b10000111, 0b11111111, 0b11100111};
void setup() {
  // put your setup code here, to run once:
  volatile char *DDR = (char*)0x21;
  *DDR = 0xFF;
  DDR = 0x24;
  *DDR = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly: 
  volatile char *data = (char*)0x22, *common = (char*)0x25;

  for(int i = 0; i<10; i++){
    for(int j = 0; j<10; j++){
      for(int k = 0; k<10; k++){
        for(int l = 0; l<10; l++){
            *data = arr[l];
            *common = 0x0E;
            for(volatile long i = 0; i<10000; i++);
            *common = 0x0F;
            for(int i = 0; i <1000; i++);

            *data = arr[k];
            *common = 0x0D;
            for(volatile long i = 0; i<10000; i++);
            *common = 0x0F;
            for(int i = 0; i <1000; i++);

            *data = arr[j];
            *common = 0x0B;
            for(volatile long i = 0; i<10000; i++);
            *common = 0x0F;
            for(int i = 0; i <1000; i++);

            *data = dec[i];
            *common = 0x07;
            for(volatile long i = 0; i<10000; i++);
            *common = 0x0F;
            for(int i = 0; i <1000; i++);
        } 
      } 
    }
  }
  
  for(int i = 0; i<10; i++){
    for(int j = 0; j<10; j++){
      for(int k = 0; k<10; k++){
        for(int l = 0; l<10; l++){
            *data = arr[l];
            *common = 0x0E;
            for(volatile long i = 0; i<10000; i++);
            *common = 0x0F;
            for(int i = 0; i <1000; i++);

            *data = arr[k];
            *common = 0x0D;
            for(volatile long i = 0; i<10000; i++);
            *common = 0x0F;
            for(int i = 0; i <1000; i++);

            *data = dec[j];
            *common = 0x0B;
            for(volatile long i = 0; i<10000; i++);
            *common = 0x0F;
            for(int i = 0; i <1000; i++);

            *data = arr[i+1];
            *common = 0x07;
            for(volatile long i = 0; i<10000; i++);
            *common = 0x0F;
            for(int i = 0; i <1000; i++);
        } 
      } 
    }
  }

  for(int i = 0; i<10; i++){
    for(int j = 0; j<10; j++){
      for(int k = 0; k<10; k++){
        for(int l = 0; l<10; l++){
            *data = arr[l];
            *common = 0x0E;
            for(volatile long i = 0; i<10000; i++);
            *common = 0x0F;
            for(int i = 0; i <1000; i++);

            *data = dec[k];
            *common = 0x0D;
            for(volatile long i = 0; i<10000; i++);
            *common = 0x0F;
            for(int i = 0; i <1000; i++);

            *data = arr[j];
            *common = 0x0B;
            for(volatile long i = 0; i<10000; i++);
            *common = 0x0F;
            for(int i = 0; i <1000; i++);

            *data = arr[i+1];
            *common = 0x07;
            for(volatile long i = 0; i<10000; i++);
            *common = 0x0F;
            for(int i = 0; i <1000; i++);
        } 
      } 
    }
  }
}
