#include <stdio.h>
#include <stdlib.h>

#define TARGETNUMBER 17
#define TARGETBIT 0
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
	UB i,j=0;																		// カウンタ
	
	/* 自動変数の初期化 */
	ercd = E_OK;

	if( number <= 127 																// 変換不能数値
		&& Target < 8 && Target >= 0 												// 0-7bit
		&& length <= 8 && length > 0													// 長さ1-7bitまで
		&& Target+length <= 8 ){													// 7bitより先

		for( i=Target+length-1; i>=Target; i-- ){
			if(j>=length){
				break;
			}
			sprintf(&bynaryChar[j], "%d", ( number >> i ) & 1);
			//printf("添え字=%d, i=%d, char=%s, 長さ=%d\n", j, i, &bynaryChar[j], length);
			j++;
		}

	} else {
		ercd = E_NG;
	}

	return ercd;
}
//---------------------------------------------------------------------------------------------------------

void main(){
	char bynary[TARGETLENGTH+1];
	int i,j;
	int res2=0;

	//初期化
	//bynary = 0;
	memset(bynary, 0x00, sizeof(bynary));

	// 表示
	printf("%d:\t", TARGETNUMBER);
	for(j=7; j>=0; j--){
		printf("%d", (TARGETNUMBER >> j) & 1);
	}
	
	printf("\n");

	// 2進数化
	if( res2 != getStatusFromBynary(TARGETNUMBER, bynary, TARGETBIT, TARGETLENGTH) ) puts("変換できません"), exit(1);
	
	printf("\n");

	printf("%s\n", bynary);
	
	
	if( !memcmp(bynary, "01", TARGETLENGTH) ){
		printf("OK\n");
	}else{
		printf("NG\n");
	}

}