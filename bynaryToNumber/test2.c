#include <stdio.h>

typedef unsigned char UB;

#define NUM 8u

void main(){
	
	int i;
	UB a[8];
	
	for(i=7u;i>=0;i--){
		a[i] = (NUM >> i) & 1;
		printf("%d", a[i]);
	}

	return;
}