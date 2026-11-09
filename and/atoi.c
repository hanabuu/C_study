#include <stdio.h>

typedef unsigned char UB;
typedef unsigned int UW;
typedef int ER;

void main(){
	
	UB a = 251u;
	UB b = 0u;
	
	printf("ans:%d", b&a );
	printf("ans:%d", a&b );
	
	return;
}