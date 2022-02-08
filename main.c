#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// function to cmpute file size
int file_size(char file_name[30])
{
 FILE *fp; // make pointer.
 fp = fopen(file_name, "r"); // open file in read mode.
 int perv = ftell(fp); // get pointer location.
 fseek(fp, 0, SEEK_END); // seek to end of file.
 int size = ftell(fp); // get current file pointer.
 fseek(fp, perv, SEEK_SET); // seek back to last location of pointer.
 return size;
}
void check_arguments(int argc,char file_name[20])
{
  // if argument's smaller than 3 print guid to use and exit 
  if(argc < 3)
  {
    printf("USE [FILE_NAME] [OUT_FILE_NAME] [PASSWORD] ! THE PASSWORD TO BE A NUMBER \n");
    exit(1);
  }
  if(access(file_name , R_OK))
  {
   printf("can't access to file %s .\n" , file_name);
   exit(1);
  }
}

int main(int argc , char *argv[])
{
  check_arguments(argc , argv[1]);
  // define var's for handel ...
  char *data; // for save data
  int byte_of_file = file_size(argv[1]); // get file sizeS
  data = (char*)malloc(byte_of_file * sizeof(char)); // malloc memory for data
  FILE *fptr; // define file pointer 
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
