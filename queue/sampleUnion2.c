/*
 * sampleUnion.c
 *
 *  Created on: 2014/07/08
 *      Author: Administrator
 */


#include <stdio.h>


#define N 3

typedef struct {
	int a;
	char b[4];
}STR;

typedef struct {
	char c[8];
}STR2;

typedef struct _queDATA{
	int d;
	union {
		STR str;
		STR2 str2;
	}U_STR;
}SAMPLE_UNION;

int enque( STR *str );
int enque2( STR2 *str );
int deque( void );

static SAMPLE_UNION sampleUnion[N];
int head;
int tail;

void main(){
	
	STR str;
	STR2 str2;
	int n;
	
	//初期化
	head = 0;
	tail = 0;
	memset(&sampleUnion, 0x00, sizeof(sampleUnion));
	memset(&str, 0x00, sizeof(STR));
	memset(&str2, 0x00, sizeof(STR2));
	
	str.a = 1;
	memcpy(&str.b, "abc", 3);
	enque(&str);
	printf("head=%d, tail=%d\n", head, tail);
	
	memcpy(&str2.c, "abcdefg", 7);
	enque2(&str2);
	printf("head=%d, tail=%d\n", head, tail);

	n = deque();
	printf("head=%d, tail=%d\n", head, tail);
	
	memset(&str, 0x00, sizeof(STR));
	str.a = 3;
	memcpy(&str.b, "def", 3);
	enque(&str);
	printf("head=%d, tail=%d\n", head, tail);

	n = deque();
	printf("head=%d, tail=%d\n", head, tail);

	
	memset(&str, 0x00, sizeof(STR));
	str.a = 4;
	memcpy(&str.b, "ghi", 3);
	enque(&str);
	printf("head=%d, tail=%d\n", head, tail);

	n = deque();
	printf("head=%d, tail=%d\n", head, tail);
	
	memset(&str, 0x00, sizeof(STR));
	str.a = 5;
	memcpy(&str.b, "ghi", 3);
	enque(&str);
	printf("head=%d, tail=%d\n", head, tail);
	
	n = deque();
	printf("head=%d, tail=%d\n", head, tail);
	
	memset(&str, 0x00, sizeof(STR));
	str.a = 6;
	memcpy(&str.b, "ghi", 3);
	enque(&str);
	printf("head=%d, tail=%d\n", head, tail);
	
	n = deque();
	printf("head=%d, tail=%d\n", head, tail);
	
	memset(&str, 0x00, sizeof(STR));
	str.a = 7;
	memcpy(&str.b, "ghi", 3);
	enque(&str);
	printf("head=%d, tail=%d\n", head, tail);
	
	n = deque();
	printf("head=%d, tail=%d\n", head, tail);
	n = deque();
	printf("head=%d, tail=%d\n", head, tail);
	n = deque();
	printf("head=%d, tail=%d\n", head, tail);
	n = deque();
	printf("head=%d, tail=%d\n", head, tail);

	memset(&str, 0x00, sizeof(STR));
	str.a = 7;
	memcpy(&str.b, "ghi", 3);
	enque(&str);
	printf("head=%d, tail=%d\n", head, tail);
	
	n = deque();
	printf("head=%d, tail=%d\n", head, tail);
}

int enque( STR *str ){
	
	int i=0;
	
	if( head % N != (tail + 1) % N ){
		i = tail++ % N;
		sampleUnion[i].d = 1;
		sampleUnion[i].U_STR.str = *str;
		return tail - head;
	} else {
		return 0;
	}
}

int enque2( STR2 *str ){
	
	int i=0;
	
	if( head % N != (tail + 1) % N ){
		i = tail++ % N;
		sampleUnion[i].d = 2;
		sampleUnion[i].U_STR.str2 = *str;
		return tail - head;
	} else {
		return 0;
	}
}


int deque( void ){
	
	int i =0;
	
	if(head != tail){
		i = head++ % N;
		if( sampleUnion[i].d == 1 ){
			printf("1のデータ a=%d, b=%s\n", sampleUnion[i].U_STR.str.a, sampleUnion[i].U_STR.str.b);
		} else if( sampleUnion[i].d == 2 ){
			printf("2のデータ c=%s\n", sampleUnion[i].U_STR.str2.c);
		}
		return 0;
	} else {
		head = 0;
		tail = 0;
		printf("データがありません");
		return -1;
	}
}