#include <stdio.h>
#include <stdlib.h>

#define TARGETNUMBER 10
#define TARGETBIT 5
#define TARGETLENGTH 2

#define UB unsigned char
#define ER int
#define E_OK 0
#define E_NG -1


/*====================================================================
@method   ER getStatusFromBynary( UB number, UB *bynaryChar, UB Target, UB length )
@param
@return
@retval   TODO:戻り値の個別設定は、各自対応
@brief
====================================================================*/
ER getStatusFromBynary( UB number, UB *bynaryChar, UB Target, UB length )
{
	ER ercd;																		// 結果格納用
	UB i;																			// カウンタ
	int j;
	
	/* 自動変数の初期化 */
	ercd = E_OK;

	for(j=7; j>=0; j--){
		printf("%d", (number >> j) & 1);
	}

	printf("\n");

	if( number <= 127 																// 変換不能数値
		|| Target < 8 || Target >= 0 												// 0-7bit
		|| length < 8 || length > 0 ){												// 長さ1-7bitまで

		for( i=Target; i>Target-length; i-- ){
			if(Target-i < 0){
				break;
			}
			sprintf(&bynaryChar[Target-i], "%d", ( number >> i ) & 1);				//iビット右シフトして1桁目取り出し
			printf("添え字=%d, i=%d, char=%s\n", Target-i, i, &bynaryChar[Target-i]);
		}

	} else {
		ercd = E_NG;
	}
	return ercd;
}


void main(){
	char bynary[TARGETLENGTH];
	int i;
	int res2=0;

	//初期化
	//bynary = 0;
	memset(bynary, 0x00, sizeof(bynary));

	// 表示
	printf("%d:\t", TARGETNUMBER);

	// 2進数化
	if( res2 != getStatusFromBynary(TARGETNUMBER, bynary, TARGETBIT, TARGETLENGTH) ) puts("変換できません"), exit(1);
	
	printf("\n");

/*
	for(i=0; i<=TARGETLENGTH-1; i++){
		printf("%c", bynary[i]);
	}
*/
	if( memcmp(&bynary[TARGETBIT], "01", 2) ){
		printf("OK");
	}else{
		printf("NG");
	}
	
	printf("\n");
}