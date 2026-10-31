#include <stdio.h>

typedef struct {
	int a;
	char b[4];
}STR;

void test(STR *tes){
	tes->a = 123;
	memcpy(tes->b, "abc", 3);
}

void test2(STR *tes){
	tes->a = 456;
	memcpy(tes->b, "def", 3);
}

void main(){
	STR str;
	STR *str2;
	
	//初期化
	str.a = 0;
	memset(str.b, 0x00, sizeof(str.b));

	str2 = &str;
	
	printf("これからやります\n");
	
	//値を入れる
	test(&str);
	printf("a = %d, b = %s\n", str.a, str.b);
	
	test2(str2);
	printf("a = %d, b = %s\n", str2->a, str2->b);
	printf("a = %d, b = %s\n", str.a, str.b);
}