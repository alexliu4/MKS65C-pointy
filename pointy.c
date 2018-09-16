#include <stdio.h>

//initializing variables
unsigned int x = 4958243805;
char * c = &x;


//helper function to modify bytes
int modifier(int byte, int boolean){
  if (boolean){
    return byte++;
  }
  else {
    return byte + 15;
  }
}

//printing
int main(){
  //hex of int x
  printf("\nhex of int: %x\n", x );
  printf("address of variable: %x\n", &x );
      //printf("address of variable: %x\n", *&x );
  printf("int: %d\n \n", x);
  //size of x in bytes
  printf("size of x: %d bytes\n \n", sizeof(x));

  //printing individual bytes
  for (size_t i = 0; i < sizeof(x); ++i){
    //char is one byte long so it can be used to check the bytes of the int individually
    unsigned char byte = *((unsigned char *)&x + i);
    //in hex
    printf("Byte %d in hex = %hhx\n", i, (unsigned)byte );
    //in int
    printf("Byte %d in int = %u\n \n", i, (unsigned)byte);
  }


  //changing bytes by 1
  for (size_t i = 0; i < sizeof(x); ++i){
    unsigned char byte = *((unsigned char *)&x + i);
    *((unsigned char *)&x + i) = modifier(byte, 0);
  }
  //in hex
  printf("hex of new int= %hhx\n", x );
  //in decimal
  printf("int: %d\n", x);
  printf("address of variable: %x\n\n", &x );


  //changing bytes by 16
  for (size_t i = 0; i < sizeof(x); ++i){
    unsigned char byte = *((unsigned char *)&x + i);
    *((unsigned char *)&x + i) = modifier(byte, 0);
  }
  //in hex
  printf("hex of new int= %hhx\n", x );
  //in decimal
  printf("int: %d\n", x);
  printf("address of variable: %x\n", &x );
  return 0;


  return 0;
}
