/*********************************************************************
@file　sample.c <モジュール名>
@brief　ソースファイルのテンプレートを示す <概要>
@design　<設計書番号>
@project　S-xxx <プロジェクト名>
@version　v1.00 <モジュールバージョン>
@note　<注意点等あれば記載>
@date　2014/1/1 <作成日>
@hist　v0.02(func1関数を追加) <変更履歴>
@hist　v0.01(新規作成)
*********************************************************************/

/* ヘッダファイルのインクルード */
#include <stdio.h>
#include "moduleName.h"
#include "sample.h" // 対となるヘッダファイルの宣言

/* マクロ定義 */
#define CONST_NUM 123

/* 列挙子定義 */
enum exampleEnum{
    ONE,
    TWO
};

/* 構造体定義 */
struct exampleStruct{
    UH iNunber;
    DL dNumber;
}

/* 定数定義 */
const UH ConstantNumber = 1234;

/* グローバル変数の定義 */
UH moduleName_variableName = 123;

/* 静的変数の定義 */
FL variableName = 1.234;

/* 内部関数のプロトタイプ宣言 */
static UH funtionName();


/* 外部関数の定義 */
/*====================================================================
@method　ER func1(UB arg, UB *argc) <関数名>
@param　UB arg[in] 属性内容 <引数1>
@param　UB *argc[out] 表示内容 <引数2>
@return　ER 関数の実行結果 <戻り値>
@retval　0 正常終了 <戻り値の説明>
@retval　-1 異常終了
@retval　上記以外 システムエラー
@brief　属性に応じて表示内容を決める <処理内容>
@note　<注意点等あれば記載>
@date　2014/1/1 <作成日>
====================================================================*/
void moduleName_functionName()
{
    //処理
}


/* 内部関数の定義 */
/*--------------------------------------------------------------------
@method　UB func2(UB arg, UB *argc) <関数名>
@param　UB arg[in] 属性内容 <引数1>
@param　UB *argc[out] 表示内容 <引数2>
@return　UB コマンド <戻り値>
@brief　属性に応じて表示内容を決め、発生するコマンドを戻す <処理内容>
@note　<注意点等あれば記載>
@date　2014/1/1 <作成日>
--------------------------------------------------------------------*/
static UH funtionName(UH examVal1, UH examVal2)
{
    //処理
}
