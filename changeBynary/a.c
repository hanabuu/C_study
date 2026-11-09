#include <stdio.h>
#include <stdlib.h>

void main(){
	char a[3];
	int decimalChar =0;

	memset(a, 0x00, sizeof(a));
	memcpy(a, "34356", sizeof(a));

	decimalChar = strtol(a, NULL, 10);
	printf("%d\n", decimalChar);
}