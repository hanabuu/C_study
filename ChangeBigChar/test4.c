#include <stdio.h>
#include <stdlib.h>

#define B char
#define H short
#define W int
#define UB unsigned char
#define UH unsigned short
#define UW unsinged int
#define ER int
#define E_OK 0
#define E_NG -1

#define _DEF 0x20

/*====================================================================
@method   UB ToDec(const UB *str, UB length)
@param    変換文字列		[in]変換対象の文字列配列
@param    長さ				[in]取得する長さ
@return   変換後数値
@retval   TODO:戻り値の個別設定は、各自対応
@brief
====================================================================*/
ER ToDecimal(const UB *str, UB length, UB *decimal)
{
	UB i = 0u;									// カウンタ＆配列添え字
	UB j = 0u;
	UB k = 0u;
	UB n;										// 一時保存用
	UB x;										// 10進数値
	UB c;										// 大文字から小文字へ変換したものを保存
	UB d[2];
	
	for(i=0; i<length; i=i+2){
		x = 0u;
		memset(d, 0x00, sizeof(d));
		memcpy(d,&str[i],2);
		for(j=0;j<2;j++){
			if( '0' <= d[j] && d[j] <= '9' ){
				n = d[j] - '0';					/* 数値に変換 */
			}else if( 'a' <= (d[j]+_DEF) && (d[j]+_DEF) <= 'f' ){
				c = d[j]+_DEF;
				n = c - 'a' + 10;					/* 数値に変換 */
			}else {
				printf("無効な文字です\n");
				return -1;
			}
			
			x = x * 16 + n;
			//printf("x=%d, n=%d\n", x, n);
		}
		decimal[i/2] = x;
	}
	
	return 0;
}

void main(void){
	UB i,j;
	UB a[20] = "1000000000A000000001";
	UB b[10];
	ER c;
	
	memset(b, 0x00, sizeof(b) );
	
	c = ToDecimal(a, 20, b);
	
	
	for(j=0;j<10;j++){
		printf("%d\n", b[j]);
	}

	return;
}
