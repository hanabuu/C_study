#include<stdio.h>
#include<time.h>		// clock()で使用
#include<stdlib.h>		// rand()で使用

#define NUM 10
#define ASC 0
#define DESC 1

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
 * 基準値取得
 * @parm *target
 * @parm left
 * @parm right
 * @parm method
 * 
 * 
 */
int getBaseValue( int *target, int left, int right, int method )
{
	return target[ (left+right)/2 ];
}


/*!
 * クイックソート(昇順)
 * @parm int *target
 * @parm int *left
 * @parm int *right
 * @return void
 * 
 * - 作業用領域の配列を昇順に並べる
 * 
 * 計算量としては
 *  
 *  
 */
void quick_sort_desc( int *target, int left, int right )
{
	int i;
	int counterLeft,counterRight;
	int baseValue;
	
	counterLeft = left;
	counterRight = right;
	
	// 基準値を決定する
	baseValue = getBaseValue( target, left, right, 0 );
	//printf("left: %d right: %d baseValue: %d\n", left, right, baseValue);
	
	while(1)
	{
		// 基準値より大きい値が見つかるまでloopLeftを増加させる
		while( target[counterLeft] < baseValue )
			counterLeft++;
		
		// 基準値より小さい値が見つかるまでloopRightを減少させる
		while( baseValue < target[counterRight] )
			counterRight--;
		
		// 左カウンタが右カウンタより大きければループを抜ける
		if( counterLeft >= counterRight )
			break;
		
		// 見つかった基準値より大きい/小さい値を交換する
		swap( &target[counterLeft], &target[counterRight] );
		// 次のデータへ
		counterLeft++;
		counterRight--;
for( i=left; i<=right; i++ )
	printf("%d ", target[i]);
		
printf("\n");
	}
	
for( i=left; i<=right; i++ )
	printf("%d ", target[i]);
	
printf("\n");
	
	if( left < counterLeft )
		quick_sort_desc( target, left, counterLeft-1 );
	
	if( counterRight+1 < right )
		quick_sort_desc( target, counterRight+1, right );
	
}


main()
{
	int i;
	int order = DESC;
	
	clock_t start,end;
	
	memset( sort_target, 0x00, NUM );
	
	
	SetData();

for( i=0; i<NUM; i++ )
	printf("%d ", sort_target[i]);
	
	printf("\n");
	start = clock();
	
	quick_sort_desc( sort_target, 0, NUM-1 );

	end = clock();
	
printf("time=%f\n", (double)(end - start) / CLOCKS_PER_SEC);

for( i=0; i<NUM; i++ )
	printf("%d ", sort_target[i]);
	
}
