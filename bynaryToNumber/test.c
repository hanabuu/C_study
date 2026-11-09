#include <stdio.h>

typedef unsigned char UB;

void main(){
	
	int i;
	UB a[8];
	UB b = 0;

	a[0] = 0;
	a[1] = 0;
	a[2] = 0;
	a[3] = 0;
	a[4] = 0;
	a[5] = 1;
	a[6] = 1;
	a[7] = 0;
	
	for(i=0u;i<8;i++){
		b += a[i] << i;
	}

	printf("b:%d", b );
	
	return;
}