#include <stdio.h>

#define abc 'sdaf'

// •\
void main(void){
	
	int i;
	
	for(i=0; i<sizeof(abc);i++){
		printf("%c\n", abc);
	}
}