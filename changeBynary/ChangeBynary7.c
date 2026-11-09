#include <stdio.h>
#include <stdlib.h>

#define TARGETNUMBER 1
#define TARGETBIT 2
#define TARGETLENGTH 4

#define UB unsigned char
#define ER int
#define E_OK 0
#define E_NG -1

void main(){

	printf("%d", (TARGETNUMBER >> 0) & 1);
	
}