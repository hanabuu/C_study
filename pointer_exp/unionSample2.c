#include <stdio.h>

typedef struct {
	int a;
	char b[4];
}STR;

typedef struct {
	char c[8];
}STR2;

union sample{
	STR str;
	STR2 str2;
};

void main(){
	union sample sam;
	union sample sam2;
	
	//初期化
	//memset(sample, 0x00, sizeof(sample));

	//値を入れる(実験①)
	sam.str.a = 4;
	memcpy(sam.str.b, "abc", 4);
	memcpy(sam.str2.c, "defghij", 8);

	//表示
	printf("a = %d, b = %s\n", sam.str.a, sam.str.b);	//strに値入れたあとstr2に値を入れることでstrの値が変わる
	printf("b = %s\n", sam.str2.c);
	
	printf("アドレス：%d\n", &sam);
	printf("アドレス：%d, a = %d, b = %d\n", &sam.str, &sam.str.a, &sam.str.b);
	printf("アドレス：%d, c = %d\n", &sam.str2, &sam.str2.c);
	
	//値を入れる(実験②)
	sam2.str.a = 4;
	memcpy(sam2.str.b, "abc", 4);
	printf("a = %d, b = %s\n", sam2.str.a, sam2.str.b);	//strに値入れる前に表示する

	memcpy(sam2.str2.c, "defghij", 8);
	printf("b = %s\n", sam2.str2.c);
	
	// 結論として共用体にはなんの値がいま入っているのかを意識する必要がある
}