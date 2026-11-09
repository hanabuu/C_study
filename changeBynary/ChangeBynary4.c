#include <stdio.h>
#include <stdlib.h>

#define TARGETNUMBER 127
#define TARGETBIT 4
#define TARGETLENGTH 1

int changeBynary( int number, char *bynaryChar ){
	int i;
	// 変換不能数値はエラー
	if(number > 255){
		return -1;
	}
	for( i=7; i>=0; i-- ){
		bynaryChar[i] = ( number >> i ) & 1; //iビット右シフトして1桁目取り出し
	}
	return 0;
}

int changeBynaryGetTarget( unsigned char number, char *bynaryChar, unsigned char Target, unsigned char length){
	int i;

	// 変換不能数値はエラー
	if( number <= 127 && Target > length && Target < 8 && length < 8 ){
		
		for( i=Target; i>Target-length; i-- ){
			sprintf(&bynaryChar[Target-i], "%d", ( number >> i ) & 1);
		}
	} else {
		return -1;
	}
	return 0;
}

int changeDecimal( char *bynaryChar ){
	int i,y;
	int exponentiation; //べき乗用変数
	int decimalNumber = 0; //１０進数
	for( i=0; i<8; i++ ){
		//2のべき乗を計算する
		exponentiation=1;
		for(y=0; y<i; y++){
			exponentiation *= 2;
		}
		//各桁に対応するべき乗をかけて足していく
		decimalNumber += bynaryChar[i] * exponentiation;
	}
	return decimalNumber;
}

void main(){
	char c[128];
	char bynaryChar[8];
	char bynary;
	int i,n, res=0, res2=0;
	int decimalChar = 0;

	//初期化
	n=TARGETNUMBER;
	memset(bynaryChar, 0x00, sizeof(bynaryChar));
	bynary = 0;
	//memset(bynary, 0x00, sizeof(bynary));
	
	// 2進数化
	if( res != changeBynary(n, bynaryChar) ) puts("変換できません"), exit(1);
	// 2進数化
	if( res2 != changeBynaryGetTarget(n, &bynary, TARGETBIT, TARGETLENGTH) ) puts("変換できません"), exit(1);
	
	// 表示
	printf("%d:\t", n);
	
	//表示のときはbynaryChar[0]が1bit目だから後ろに来るように上から表示する
	for( i=7; i>=0; i-- ){
		printf("%d", bynaryChar[i]);
	}
	
	printf("\t");
	
	if(TARGETLENGTH == 1){
		printf("%c", bynary);
	} else {
//		for( i=0; i<=TARGETLENGTH-1; i++ ){
//			printf("%c", bynary[i]);
//		}
	}

	printf("\t");
		
	// 10進数に戻す
	//decimalChar = strtoul(bynary, NULL, 10);
	//printf("%d\n", decimalChar);
}
