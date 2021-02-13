/********************************/
/* Program Name:                */
/* Author:                      */
/* Date:                        */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define max_int (255)
#define byte (char)

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;   
  char checksum; 
  char complement;
  int quotient;
  int remainder;
 
  

  /* the following is the prototype for the read system call */
  /* int read(int fildes, void *buf, size_t nbyte);  */
	int header[10];
	int ret; 
	for (int i = 0; i < count; i++) {
	ret = read(0, (void *) &header, 10);
	sum = ret + sum;
	}
	
	
	sum = sum - header[5];
	checksum = header[5];

	quotient = sum/(max_int+1);
	remainder = sum%(max_int+1);
	sum = quotient + remainder;
	complement = max_int-sum;
	
	

	
  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}

		
		
		
		
