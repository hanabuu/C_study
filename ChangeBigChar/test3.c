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
UB ToDec(const UB *str, UB length)
{
	UB i = 0;									// カウンタ＆配列添え字
	UB n;										// 一時保存用
	UB x = 0;									// 10進数値
	UB c;										// 大文字から小文字へ変換したものを保存
	
	
	for(i=0;i<length;i++){
		if( '0' <= str[i] && str[i] <= '9' ){
			n = str[i] - '0';					/* 数値に変換 */
		}else if( 'a' <= (str[i]+_DEF) && (str[i]+_DEF) <= 'f' ){
			c = str[i]+_DEF;
			n = c - 'a' + 10;					/* 数値に変換 */
		}else {
			printf("無効な文字列です\n");
			return 0;
		}
		
		x = x * 16 + n;
	}
	return (x);
}

void main(void){
	UB i,j;
	UB a[20] = "1000000000A000000001";
	UB b[10];
	UB c;
	UB d[2];
	
	memset(b, 0x00, sizeof(b));
	
	for(i=0; i<20; i=i+2){
		memset(d, 0x00, sizeof(d));
		memcpy(d,&a[i],2);
		c = ToDec(d, 2);
		b[i/2] = c;
	}
	
	for(j=0;j<10;j++){
		printf("%d\n", b[j]);
	}

	return;
}
