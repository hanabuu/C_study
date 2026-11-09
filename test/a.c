#include <stdio.h>
#include <stdlib.h>

#define AAA "TR\x03R"

// •\

void main(){
	char a[4];
	memset( a, 0x00, sizeof(a) );
	
	memcpy( a, AAA, 4 );
	
	printf("%s", a);
}