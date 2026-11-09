/*
 * main.c
 *
 *  Created on: 2018/10/25
 *      Author: alsok
 */


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
	UB tmp1;
	UB tmp2;


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

//		// ビット入れ替え
//		tmp2 =  ((decimal[i/2] >> 7) & 1) * 1 |					// 8bit目を5bit目に
//				((decimal[i/2] >> 6) & 1) * 2 |					// 7bit目を6bit目に
//				((decimal[i/2] >> 5) & 1) * 4 |					// 6bit目を7bit目に
//				((decimal[i/2] >> 4) & 1) * 8;					// 5bit目を8bit目に
//		tmp1 =  ((decimal[i/2] >> 3) & 1) * 1 |					// 4bit目を1bit目に
//				((decimal[i/2] >> 2) & 1) * 2 |					// 3bit目を2bit目に
//				((decimal[i/2] >> 1) & 1) * 4 |					// 2bit目を3bit目に
//				((decimal[i/2] >> 0) & 1) * 8;					// 1bit目を4bit目に
//		decimal[i/2] = (tmp1 << 4) | tmp2;						// 上位ビットと下位ビットを入れ替え(1-4bit目と5-8bit目を入れ替え)
	}

	return 0;
}

ER changeOrder(const UB *str, UB length, UB *decimal)
{
	UB i = 0u;									// カウンタ＆配列添え字
	UB tmp[20];         // 一時保存用

	memset(tmp, 0x00,20);

	// ２バイトずつ取り出して一時保存用変数に入れてやる
	// この時２バイトずつ逆に入れてやる
	for( i=0;i<length;i++ ){
		memcpy( &tmp[length-i-2], &str[i], 2 );
	}
	// 設定情報を戻す
	memcpy( decimal, tmp, 20 );

	return 0;
}

int main(void){
//	UB a[20] = "10A5FF0088A000000001";
	UB a[20] = "01000000A08800FFA510";
	UB b[10];
	UB d[20];
	ER c;

	memset( b, 0x00, sizeof(b) );
	memset( d, 0x00, sizeof(d) );

	c = changeOrder(a, 20, d);
	c = ToDecimal(d, 20, b);


	printf("%d %d %d %d %d %d %d %d %d %d \n", b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7], b[8], b[9]);

	return 0;
}
