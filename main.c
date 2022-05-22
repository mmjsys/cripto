#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// function to cmpute file size
int file_size(char *file[] , int *size)
{
 FILE *fp; // make pointer.
 fp = fopen( *file, "r"); // open file in read mode.
 int perv = ftell(fp); // get pointer location.
 fseek(fp, 0, SEEK_END); // seek to end of file.
 *size = ftell(fp); // get current file pointer.
 fseek(fp, perv, SEEK_SET); // seek back to last location of pointer. 
 return 0;
}
void check_arguments(int argc,void *argv[])
{
  // if argument's smaller than 3 print guid to use and exit 
  if(argc < 3)
  {
    printf("USE [FILE_NAME] [OUT_FILE_NAME] [PASSWORD] ! THE PASSWORD TO BE A NUMBER \n");
    exit(1);
  }
  if(access(argv[1] , R_OK))
  {
   printf("%s: %s: No such file or directory\n" , argv[0] , argv[1]);
   exit(1);
  }
}

int main(int argc , char *argv[])
{
  check_arguments(argc , argv);
  // define var's for handel ...
  int size;
  char *data; // for save data
  file_size(&argv[1], &size); // get file sizeS
  data = (char*)malloc(size * sizeof(char)); // malloc memory for data
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
