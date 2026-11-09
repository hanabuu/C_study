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

int changeBynaryGetTarget( unsigned char number, char *bynaryChar, unsigned char Target, unsigned char length){
	int i;
	//unsigned char tmp;
	// 変換不能数値はエラー
	if( number <= 256 && Target > length && Target < 8 && length < 8 ){
		for( i=Target; i>Target-length; i-- ){
			//printf("%d\n", Target - i);
			sprintf(&bynaryChar[Target-i], "%d", ( number >> i ) & 1);
			//bynaryChar[Target-i] = (char)( number >> i ) & 1; //iビット右シフトして1桁目取り出し
		}
		//printf("%d, %c%c\n", number, bynaryChar[0], bynaryChar[1]);
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
	char bynary[3];
	int i,n, res=0, res2=0;
	int decimalChar = 0;

	//ファイル作成用
	FILE *out;
	out = fopen("kekka3.txt","w");
	 //初期化
	memset(bynaryChar, 0x00, sizeof(bynaryChar));
	memset(bynary, 0x00, sizeof(bynary));
	
	fprintf(out, "num\t76543210\t**\tcut\n");
	
	//全部表示する
	for( n=0; n<256; n++ ){
		// 2進数化
		res = changeBynary(n, bynaryChar);
		if( res != 0 ) puts("変換できません"), exit(1);
		// 2進数化
		res = changeBynaryGetTarget(n, bynary, 3, 2);
		if( res2 != 0 ) puts("変換できません"), exit(1);
		
		// 表示
		fprintf(out, "%d:\t", n);
		//表示のときはbynaryChar[0]が1bit目だから後ろに来るように上から表示する
		for( i=7; i>=0; i-- ){
			fprintf(out, "%d", bynaryChar[i]);
		}
		
		fprintf(out, "\t");
		
		for( i=0; i<=1; i++ ){
			fprintf(out, "%c", bynary[i]);
		}

		fprintf(out, "\t");
		
		// 10進数に戻す
		decimalChar = strtoul(bynary, NULL, 10);
		fprintf(out, "%d\n", decimalChar);
	}
}
