#include <stdio.h>

union ipv4 { //←IPアドレスの共用体ipv4を定義
	unsigned char c[4];
	unsigned short s[2];
	unsigned int i;
};

int main()
{
	union ipv4 addr;
	int i;

	addr.c[0]=192; //←IPアドレス「192.168.1.23」をセット
	addr.c[1]=168;
	addr.c[2]=1;
	addr.c[3]=23;
	for(i=0; i<3; i++){ //←IPアドレス(192.168.1.）までを表示
		printf("%d.", addr.c[i]);
	}
	printf("%d\n", addr.c[i]); //←残りの（23）を表示

	printf("%04X:%04X\n",addr.s[0],addr.s[1] );
	//printf("%04X:%04X\n", htons(addr.s[0]), htons(addr.s[1]));

	printf("%X\n", addr.i );
	//printf("%X\n", htonl(addr.i));
}