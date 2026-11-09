#include <stdio.h>

int defe;
void def(void);

int main(void) {
	
	int a = 0;
	defe = 0;
	
	//def();
	
#ifdef defe == 0
	a = 1;
#endif
	
	printf("%d", a);
	
}

void def(void){
	#define _def
}
