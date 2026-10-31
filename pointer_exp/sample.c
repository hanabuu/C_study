#include "stdio.h"
#include <string.h>

void sub(char *pp);
void sub1(char *bb);
void sub2(char bbb[4]);

void main(){
	
	char a = 123;			// 1byteのデータ
	char b[4] = "ABC"; 		//char型配列
	char *p;				//アドレスの先頭アドレスを記憶するポインタ
	int i;
/*
	printf("まずは配列とアドレス--------------------------------------\n");
	printf("数値 = %c\n", a);											//123の文字コード?
	printf("aの先頭アドレス = %d\n", &a);								//aの先頭アドレス
	printf("bの中身 = %s, b[0]のアドレス = %d\n", b, &b);				//bの先頭アドレス
	printf("b[0]の中身 = %c, b[0]のアドレス = %d\n", b[0], &b[0]);		//b[0]のアドレス
	printf("b[1]の中身 = %c, b[1]のアドレス = %d\n", b[1], &b[1]);		//b[0]のアドレス
	printf("b[2]の中身 = %c, b[2]のアドレス = %d\n", b[2], &b[2]);		//b[0]のアドレス
	printf("b[3]の中身 = %c, b[3]のアドレス = %d\n", b[3], &b[3]);		//b[0]のアドレス
*/
	for( i = 0; b[i] != '\0'; i++ ) {
		putchar(b[i]);
	}
	
	printf("\nポインタについて--------------------------------------\n");
	printf("char *p;\n");
	printf("p = b;\n");
	p = b;																//bの先頭アドレスを代入
																		//「ポインタpはbを指す」という
	printf("pの最初の文字(*p) = %c, pの次の文字(*(p+1)) = %c\n",*p, *(p+1));
																		//*pで先頭アドレスの中身
																		//*(p+1)で次のアドレスの中身
	printf("pの先頭アドレス(p) = %d, pの次のアドレス(&p[1]) = %d\n", p, &p[1]);
																		//pがポインタの先頭アドレス(%dで取る)
																		//&p[1]で次のアドレス(%dで取る)
	printf("pの中身(p)(％s取得) = %s, pの先頭アドレス(p)(％dで取得) = %d\n\n",p ,p);
																		//ポインタの全部の中身を取るときは「p」(%sで取る)
	
	printf("関数渡し--------------------------------------------\n");
	printf("関数sub(p)\n");
	sub(p);																//関数で渡す時に引数がポインタならそのまま渡す
	printf("関数sub1(b)\n");
	sub1(b);															//引数がポインタでもchar型のものを渡せる
	printf("関数sub2(b)\n");
	sub2(b);															//引数が配列でもchar型のものを渡せる
																		//sub1とsub2の引数は同じものとなる

}

void sub(char *pp){
	printf("-------void sub(char *pp)-------\n");
	printf("ppの最初の文字(*pp) = %c, ppの次の文字(*(pp+1)) = %c\n",*pp, *(pp+1));
	printf("ppの先頭アドレス(pp) = %d, ppの次のアドレス(&pp[1]) = %d\n", pp, &pp[1]);
	printf("ppの中身(pp)(％s取得) = %s, ppの先頭アドレス(pp)(％dで取得) = %d\n",pp ,pp);
	printf("                  結局関数で渡してもポインタ宣言と同じ扱いだね☆\n\n");
	printf("ここから値を変更していく\n");
	printf("memcpy(&pp[1], \"DF\", 2);\n");
	memcpy(&pp[1], "DF", 2);
	printf("ppの2番目の先頭アドレス(&pp[1]) = %d\n", &pp[1]);
	printf("ppの中身(pp) = %s\n",pp);
	printf("memcpy(pp, \"GHE\", 3);\n");
	memcpy(pp, "GHE", 3);
	printf("ppの中身%s\n\n",pp);
}

void sub1(char *bb){
	printf("-------void sub1(char *bb)-------\n");
	printf("bbの最初の文字(*bb) = %c, bbの先頭アドレス(bb) = %d\n",*bb, bb);
}

void sub2(char bbb[4]){
	printf("-------void sub2(char bbb)-------\n");
	printf("bbbの中身 = %s, bbb[0]のアドレス = %d\n", bbb, &bbb);
}