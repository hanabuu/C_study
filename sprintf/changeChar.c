#include <stdio.h>
#include <stdlib.h>

#define LENGTH 4

void main(){
	int B = 10;
	char bynary[LENGTH];

	sprintf(bynary, "%04d", B);

	printf("%s\n", bynary);
}