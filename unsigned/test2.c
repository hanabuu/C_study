#include <stdio.h>
#include <stdlib.h>

void main(void){
	unsigned char a = 0x0; /* 00 */
	unsigned char b = 0x1; /* 01 */
	unsigned char c = 0xa; /* 10 */
	unsigned char d = 0xb; /* 11 */
	printf("%d, %d, %d, %d\n", a,b,c,d);
	printf("%d\n", a ^ b); /* 00 xor 01 */
	printf("%d\n", a ^ c); /* 00 xor 10 */
	printf("%d\n", b ^ a); /* 01 xor 00 */
	printf("%d\n", b ^ d); /* 01 xor 11 */
	printf("%d\n", c ^ a); /* 10 xor 00 */
	printf("%d\n", c ^ b); /* 10 xor 01 */
	printf("%d\n", d ^ a); /* 11 xor 00 */
	printf("%d\n", d ^ b); /* 11 xor 01 */
	return;
}