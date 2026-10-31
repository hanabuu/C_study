#include<stdio.h>
#include<time.h>		// clock()で使用
#include<stdlib.h>		// rand()で使用

#define NUM 10

int sort_target[NUM];

/*!
 * 乱数発生関数
 * 0-99の乱数をNUM個数分作成し,sort_targetに格納する
 */
void SetData( void )
{
	int i;
	
	for (i = 0; i < NUM; i++)
	sort_target[i] = rand(  ) % 100;
}

/*!
 * 入れ替え関数
 * @parm int *a 入れ替える数値１
 * @parm int *b 入れ替える数値２
 * @note 一時格納に片方を格納してから、入れ替える
 */
void swap(int *a, int *b){
	int c;
	
	c = *a;
	*a = *b;
	*b = c;
}

/*!
 * バブルソート(昇順)
 * 先頭から順に隣の数値と比較していき並び替える
 * 計算量としては
 *  iのループが N回 × jのループが N-1回
 *   N×(N-1) でO(N^2)オーダー
 */
void bubble_sort_asc( int num, int *target )
{
	int i,j;
	
	for( i=0; i<num; i++ ){
		for( j=0; j<num-1; j++ ){
			if( target[j] > target[j+1] ){
				swap( &target[j+1], &target[j] );
			}
		}
	}
}

/*!
* バブルソート(降順)
 * 先頭から順に隣の数値と比較していき並び替える
 * 計算量としては
 *  iのループが N回 × jのループが N-1回
 *   N×(N-1) でO(N^2)オーダー
 */
void bubble_sort_desc( int num, int *target )
{
	int i,j;
	int tmp = 0;					// 格納用
	
	for( i=0; i<num; i++ ){
		for( j=0; j<num-1; j++ ){
			if( target[j] < target[j+1] ){
				swap( &target[j+1], &target[j] );
			}
		}
	}
}

main()
{
	int i;
	clock_t start,end;
	
	memset( sort_target, 0x00, NUM );
	
	SetData();
//	for( i=0; i<NUM; i++ ){
//		printf("i:%d target=%d\n", i, sort_target[i]);
//	}
	
	start = clock();

	bubble_sort_asc( NUM, sort_target );
/*
	bubble_sort_desc( NUM, sort_target );
*/

	end = clock();
	
	printf("time=%f", (double)(end - start) / CLOCKS_PER_SEC);
//	for( i=0; i<NUM; i++ ){
//		printf("i:%d %d\n", i, sort_target[i]);
//	}
}
