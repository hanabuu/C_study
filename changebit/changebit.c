
#include <stdio.h>

typedef char UB;


void unsignedChar( unsigned char x, UB *bit )
//void unsignedChar( unsigned char x )
{
	
	int i;
	//UB bit[7];
	
	memset(bit, 0x00, sizeof(bit));
	
	printf("%4u %02x ", x, x);
	for(i=7; i>=0; i--){
	printf("%d", (x>>i) & 1);
		bit[7%i] = (x>>i) & 1;
	}
	printf("\n");
	//printf("%s\n", bit);
	return;
}

void main(){
	
	UB bit[7];
	
	memset(bit, 0x00, sizeof(bit));
	
	unsignedChar(15, bit);
	//unsignedChar(15);
	
	return;
}