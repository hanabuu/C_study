/**********************************/
/*  １０進数→２進数変換（筆算）  */
/**********************************/
#include <stdio.h>
#include <stdlib.h>
void  main( )
{
    char  c[128];
    int   n,m,i;

    printf("\n***１０進数を２進数に変換します***");
    printf("\n１０進数: "); 
	fflush(stdout);					// 標準入力バッファのクリア
    gets(c);						// 標準入力から文字列を入力
    n=atoi(c);						// 整数値に変換

    printf("\n 2)%6d\n",n);

    for( i=0; n>0; i++ )              // n>0 のとき繰り返す
      {
        printf("  -------\n");
        m=n%2;                        // ２で割ったあまり
        n=n/2;                        // ２で割る
        printf(" 2)%6d … %d\n",n,m);
        c[i]=m+'0';                   // 文字１桁格納
      }

    printf("\n答 ");
    for( i--; i>=0; i-- )             // 大きい位から表示
      { printf("%c",c[i]); }
    printf("\n");
}
   