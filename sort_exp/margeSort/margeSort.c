#include<stdio.h>
#include<time.h>		// clock()で使用
#include<stdlib.h>		// rand()で使用

#define NUM 10
#define ASC 0
#define DESC 1

int sort_target[NUM];
int tmp_target[NUM];

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
 * マージソート(昇順)
 * @parm int *dataLeft
 * @parm int *dataRight
 * @return void
 * 
 * - 作業用領域の配列を昇順に並べる
 * 
 * 計算量としては
 *  
 *  
 */
void marge_sort_desc( int left, int right )
{
	int i,k;
	int index, dataLeft, dataRight;

	dataLeft = left;
	dataRight = right;
	
	// tmp_targetの配列を昇順に並べる
	for( index = left; index <= right; index++ )
	{
		if( tmp_target[dataLeft] <= tmp_target[dataRight] )
			sort_target[index] = tmp_target[dataLeft++];
		else
			sort_target[index] = tmp_target[dataRight--];
	}
	
for( i=left; i<=right; i++ )
	printf("%d ", sort_target[i]);
	
printf("\n return \n\n");
}


/*!
 * マージソート(降順)
 * @parm int *dataLeft
 * @parm int *dataRight
 * @return void
 * 
 * - 作業用領域の配列を降順に並べる
 * 
 * 計算量としては
 *  
 *  
 */
void marge_sort_asc( int left, int right )
{
	int i,k;
	int index, dataLeft, dataRight;

	dataLeft = left;
	dataRight = right;
	// tmp_targetの配列を降順に並べる
	for( index = left; index <= right; index++ )
	{
		if( tmp_target[dataLeft] >= tmp_target[dataRight] )
			sort_target[index] = tmp_target[dataLeft++];
		else
			sort_target[index] = tmp_target[dataRight--];
	}
	
for( i=left; i<=right; i++ )
	printf("%d ", sort_target[i]);
	
printf("\n return \n\n");
}

/*!
 * マージソート
 * @parm int *target ターゲット配列
 * @parm int left 配列の先頭(添え字)
 * @parm int right 配列の最後(添え字)
 * @parm int order 降順/昇順
 * @sa ASC
 * @sa DESC
 * @return void
 * 
 * - @par 左側の要素が１つになるまで再帰的にこの関数を繰り返す
 * - @par 右側の要素が１つになるまで再帰的にこの関数を繰り返す
 * - @par 今の範囲を作業用領域にコピーする
 *  - 左側は順にコピーしたあと、右側を逆順にコピーする
 * 
 * 計算量としては
 *  
 *  
 */
void marge_sort( int left, int right, int order )
{
	int i,k;
	int dataLeft, dataRight;
	int divSize;							// 分割したサイズ

	
	if( right - left <= 0 ) {
		return;								// サイズがひとつなら
	}
	divSize = (left + right) / 2;
	
	// それぞれ左側と右側でこの関数を再帰呼び出しする
	// これで要素がひとつになるまで分割
	marge_sort( left, divSize, order );
	marge_sort( divSize+1, right, order );
	
printf("left:%d right:%d\n", left, right);
	
	// ここから下は再帰から帰ってきたときに実行される
	// これで分割後に各要素ごとに処理を行う
	
	/* x[left] から x[divSize] を作業領域にコピー */
	for (dataLeft = left; dataLeft <= divSize; dataLeft++)
		tmp_target[dataLeft] = sort_target[dataLeft];
		
	/* x[divSize + 1] から x[right] は逆順にコピー */
	for (dataLeft = divSize+1, dataRight = right; dataLeft <= right; dataLeft++, dataRight--)
		tmp_target[dataLeft] = sort_target[dataRight];
	
for( i=left; i<=right; i++ )
	printf("%d ", tmp_target[i]);
	
printf("\n");
	
	
	if( ASC == order ){
		marge_sort_asc( left, right );
	} else if( DESC == order ) {
		marge_sort_desc( left, right );
	}
}


main()
{
	int i;
	int order = DESC;
	clock_t start,end;
	
	memset( sort_target, 0x00, NUM );
	memset( tmp_target, 0x00, NUM );
	
	
	SetData();
	for( i=0; i<NUM; i++ )
		printf("i:%d target=%d\n", i, sort_target[i]);
	
	start = clock();
	
	marge_sort( 0, NUM-1, order );

	end = clock();
	
	printf("time=%f\n", (double)(end - start) / CLOCKS_PER_SEC);
	for( i=0; i<NUM; i++ ){
		printf("i:%d %d\n", i, sort_target[i]);
	}
}
