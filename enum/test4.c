#include <stdio.h>
#include <wchar.h>
#include <locale.h>

//#define COLOR_NUM  (5)  /* 色の総数 */

/* 色の列挙型 */
enum Color_tag {
	RED,
	GREEN,
	BLUE,
	WHITE,
	BLACK,
	
	COLOR_NUM
};

/* 色の日本語表記 */
static const wchar_t* const COLOR_NAME_TABLE[COLOR_NUM] = {
	L"赤",
	L"緑",
	L"青",
	L"白",
	L"黒"
};

int main(void)
{
	enum Color_tag color;  /* 変数宣言の際にも enum が必要 */
	int i;

	setlocale( LC_CTYPE, "" );


	/* 列挙型への代入 */
	color = COLOR_NUM;
	wprintf( L"%d\n", color );
//これはCOLOR_NAME_TABLE[5]の値が無い為、落ちるロ_ρ゛(・・ ) プチンッ
//	wprintf( L"%d: %ls\n", color, COLOR_NAME_TABLE[color] );
	color = 4;
	wprintf( L"%d: %ls\n", color, COLOR_NAME_TABLE[color] );

	/* 直接、列挙定数を使う */
	wprintf( L"%d: %ls\n", WHITE, COLOR_NAME_TABLE[WHITE] );

	/* すべて列挙する。ただし５番目の色数は除く */
	for( i = 0; i < COLOR_NUM-1; ++i ){
		wprintf( L"%d: %ls\n", i, COLOR_NAME_TABLE[i] );
	}

	return 0;
}