/*
 ============================================================================
 Name        : pfunc.c
 Author      : pfunc
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int test1( void ){
	printf("‚ ");
	return 1;
}

int test2( void ){
	printf("‚¢");
	return 1;
}

int test3( void ){
	printf("‚¤");
	return 1;
}

int test4( void ){
	printf("‚¦");
	return 1;
}

int test5( void ){
	printf("‚¨");
	return 0;
}

int main(void) {

	int ret = 1 , i = 0;
	int (*func[])() = {test1,test2,test3,test4,test5};

	while( ret ) ret = (*func[i++])();

	return EXIT_SUCCESS;
}

