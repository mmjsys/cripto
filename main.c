#include <stdio.h>
#include <stdlib.h>
// function to cmpute file size
int file_size(char file_name[30])
{
 FILE *fp;
 fp = fopen(file_name, "r");
 int perv = ftell(fp); // get pointer location.
 fseek(fp, 0, SEEK_END); // seek to end of file.
 int size = ftell(fp); // get current file pointer.
 fseek(fp, perv, SEEK_SET); // seek back to last location of pointer.
 return size;
}

void check_arguments(int argc)
{
  // if argument's smaller than 3 print guid to use and exit 
  if(argc < 3)
  {
    printf("USE [FILE_NAME] [OUT_FILE_NAME] [PASSWORD] ! THE PASSWORD TO BE A NUMBER \n");
    exit(1);
  }
}

int main(int argc , char *argv[])
{
  check_arguments(argc);
  // define var's for handel ...
  FILE *fptr; // define file pointer 
  char *data; // for save data
  int byte_of_file = file_size(argv[1]); // get file size
  printf("%d" , byte_of_file); // print file size for debug
  data = (char*)malloc(byte_of_file * sizeof(char)); // malloc memory for data
  printf("file opened ");  
  fptr = fopen(argv[1] , "rb"); // open file for read binery  

  int i = 0 ; // index for remember data index
  while (!feof(fptr)) // if end of continu  
  {
    data[i++] = fgetc(fptr); // write char in data with i index
  }
  fclose(fptr); // close source file
  fptr = fopen(argv[2] , "wb"); // open enc file for write binary
  for (int j=0 ; j<i-1 ; j++) { // for j in data index 
      fputc((data[j] ^ atoi(argv[3])) , fptr); // write enc char in file
  }
  fclose(fptr); // aim file close 
  
}
