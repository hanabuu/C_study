/*
 * sampleUnion.c
 *
 *  Created on: 2014/07/08
 *      Author: Administrator
 */


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

typedef struct {
	char d[1];
	union {
		STR str;
		STR2 str2;
	}U_STR;
}SAMPLE_UNION;

void main(){

	SAMPLE_UNION sampleUnion;

	//初期化
	//memset(sample, 0x00, sizeof(sample));

	//値を入れる(実験①)
	memcpy(sampleUnion.d, "a", 1);
	memcpy(sampleUnion.U_STR.str2.c, "defghij", 8);

	//表示
	printf("sampleUnion = %s\n", sampleUnion.U_STR.str2.c);
	//strに値入れたあとstr2に値を入れることでstrの値が変わる

	// 結論として共用体にはなんの値がいま入っているのかを意識する必要がある
}
