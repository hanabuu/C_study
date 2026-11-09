#include <stdio.h>

void change( char *str ){
	
	int i;
	char b[5];
	char c[10];
	
	memset( b, 0x00, sizeof(b) );
	memset( c, 0x00, sizeof(c) );
	
	memcpy(c, str, sizeof(str));
	
	for(i=0;i<10;i++){
		if(0x00 == c[i]){
			break;
		}
		b[i] = c[i] - '0';
		//b[i] = atoi( (char)str[i] );
		printf("%d\n", b[i]);
	}
	
}

int main( int argc, char *argv[] ) {
	
	int i;
	
	printf("%d\n",argc);
	
	printf(" start str:%s\n", argv[1]);
	
	change(argv[1]);
	
	printf(" end");
}
