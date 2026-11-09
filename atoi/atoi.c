#include <stdio.h>

typedef unsigned char UB;
typedef unsigned int UW;
typedef int ER;

ER atoiForSci( UB *str, UB size, UB *num ){
	UB i;
	UW tmp = 0;
	ER res = 0;
	
	for(i=0;i<size;i++){
		if( str[i] < '0' || str[i] > '9' ){
			res = -1;
			break;
		}
		tmp += str[i] - '0';
		tmp *= 10;
	}
	*num = (UB)(tmp / 10);
	return res;
}


void main(){
	UB number = 0;
	
	atoiForSci("101",3,&number);
	printf("%d\n", number);

	atoiForSci("031",3,&number);
	printf("%d\n", number);

	atoiForSci("255",3,&number);
	printf("%d\n", number);
	
	atoiForSci("257",3,&number);
	printf("%d\n", number);

	atoiForSci("a",1,&number);
	printf("%d\n", number);
	return;
}