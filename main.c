#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_SIZE (1024*1024)
int main(int argc , char *argv[]) {
  if(argc < 3) {
    printf("USE [FILE_NAME] [OUT_FILE_NAME] [PASSWORD] ! THE PASSWORD TO BE A NUMBER");
    exit(1);
  }
  FILE *fptr;
  char data[MAX_FILE_SIZE];
  fptr = fopen(argv[1] , "rb");
  int i = 0 ;
  while (!feof(fptr)) 
  {
    data[i++] = fgetc(fptr);
  }
  fclose(fptr);
  fptr = fopen(argv[2] , "wb");
  for (int j=0 ; j<i-1 ; j++) {
      fputc((data[j] ^ atoi(argv[3])) , fptr);
  }
  fclose(fptr);
  
}