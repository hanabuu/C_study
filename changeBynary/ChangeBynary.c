#include <stdio.h>
#include <stdlib.h>

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
	int i,n, res=0;
	int decimalChar = 0;

	//ファイル作成用
	FILE *out;
	out = fopen("kekka.txt","w");
	 //初期化
	memset(bynaryChar, 0x00, sizeof(bynaryChar));

	 //標準入力
	//printf("\n***１０進数を２進数に変換します***");
    //printf("\n１０進数: ");
	//fflush(stdout); // 標準入力バッファのクリア
    //gets(c); // 標準入力から文字列を入力
    //n=atoi(c); // 整数値に変換
	
	//全部表示する
	for( n=0; n<256; n++ ){
		// 2進数化
		res = changeBynary(n, bynaryChar);
		if( res != 0 ) puts("変換できません"), exit(1);
		 // 表示
		//printf("２進数: ");
		fprintf(out, "２進数: ");
		//表示のときはbynaryChar[0]が1bit目だから後ろに来るように上から表示する
		for( i=7; i>=0; i-- ){
			//printf("%d", bynaryChar[i]);
			fprintf(out, "%d", bynaryChar[i]);
		}
		//printf("\n");
		// 10進数に戻す
		decimalChar = changeDecimal( bynaryChar );
		//printf(" １０進数: %d", decimalChar);
		fprintf(out, " １０進数: %d\n", decimalChar);
	}
}
