
#include <stdio.h>

typedef unsigned char UB;

#define BIT_ARRAY 8

void main(){
	UB i;
	UB bit;
	UB ctlDataCategory1[8];
	
	i=0;
	bit = 0;
	memset(ctlDataCategory1, 0x00, 8);
	
	ctlDataCategory1[0] = 0;
	ctlDataCategory1[1] = 0;
	ctlDataCategory1[2] = 0;
	ctlDataCategory1[3] = 0;
	ctlDataCategory1[4] = 0;
	ctlDataCategory1[5] = 0;
	ctlDataCategory1[6] = 0;
	ctlDataCategory1[7] = 1;
	
	for(i=0;i<BIT_ARRAY;i++){
		bit += ctlDataCategory1[i] << i;
	}
	
	printf("%d\n", bit);
	
	return;
}