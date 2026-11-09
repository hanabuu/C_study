#include <stdio.h>
#include <stdlib.h>

typedef struct user_msg{
	int mode;
	char data[4];
} USER_MSG;

static USER_MSG *msg;

void main(void){
	
	puts("1\n");

	msg = (USER_MSG *) malloc(1 * sizeof(USER_MSG));
	if (msg == 0x00){
		puts("Memory problem ");
		exit(1);
	}
	
	puts("2\n");
	
	msg->mode = 10;
	puts("3\n");

	memcpy(msg->data, "aaa", 3);
	puts("4\n");
	//msg->data = (VP)datas;
	//free(msg);
	puts("5\n");
	//return;
}