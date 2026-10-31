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
 * @parm int *target 対象の配列
 * @parm int left    とりあえずの親の場所
 * @parm int tmpChild 子の目印( 親が(tmpChild+1)/2よりも大きければ子を持っていないことに )
 * 
 * @note 範囲の中で親が最大になるようにする関数
 * 
 *  ▼ 子を持っている限りループ
 *   親(left)と子(left:parent*2+1, right:left+1)の大きいほうを比較
 *   [子が大きい場合]
 *    - 親と子を入れ替え
 *   [親が大きい場合]
 *    - 抜ける
 *  ▲
 */
void h_down( int *target, int left, int tmpChild ){
	int child;
	int parent = left;			// とりあえずの親を保存
	int temp = target[left];	// 根とみなす
	int cl, cr;
	
	printf("left:%d %d tmpChild:%d %d\n", left, target[left], tmpChild, target[tmpChild]);
	
	while(parent < (tmpChild + 1) / 2){
		cl = parent * 2 + 1;	// 左の子
		cr = cl + 1;			// 右の子
		printf("cl:%d %d cr:%d %d\n", cl, target[cl], cr, target[cr]);

		/* 大きい方の子を選択する */
		if((cr <= tmpChild) && (target[cr] > target[cl])){
			child = cr;
		}else{
			child = cl;
		}
		printf("child:%d %d\n", child, target[child]);

		if(temp >= target[child]){
			// 親が大きい場合は抜ける
			break;
		} else {
			// 子の方が大きい場合には交換する
			target[parent] = target[child];
			parent = child;
		}
	}
	target[parent] = temp;
}

/*!
 * ヒープソート(昇順)
 * 
 * 計算量としては
 *  
 *  
 */
void heap_sort_desc( int size, int *target )
{
	int i,j;
	int tmp = 0;					// 格納用
	
	// ヒープ作成
	// これで配列の中の最大が根になる
	for( i=(size-1)/2; i>=0; i-- ){
		h_down( target, i, size - 1);
	}
	for( j=0; j<size; j++ ){
		printf("j:%d %d\n", j, target[j]);
	}
	printf("\n");
	/* ソート */
	for (i = size - 1; i > 0; i--) {
		// 半順序木の根と末尾の要素を交換する
		swap(&target[0], &target[i]);
		
		// 根を外したデータ列で、半順序木を構成する
		h_down(target, 0, i - 1);
		for( j=0; j<size; j++ ){
			printf("j:%d %d\n", j, target[j]);
		}
		printf("\n");
	}
}


main()
{
	int i;
	clock_t start,end;
	
	memset( sort_target, 0x00, NUM );
	
	SetData();
	for( i=0; i<NUM; i++ ){
		printf("i:%d target=%d\n", i, sort_target[i]);
	}
	
	start = clock();
	
	//printf("size=%d\n", sizeof(sort_target)/4);
	
	heap_sort_desc( sizeof(sort_target)/4, sort_target );
/*	
	heap_sort_asc( NUM, sort_target );
*/
	for( i=0; i<NUM; i++ ){
		printf("i:%d %d\n", i, sort_target[i]);
	}

	end = clock();
	
	printf("time=%f", (double)(end - start) / CLOCKS_PER_SEC);
	
}
