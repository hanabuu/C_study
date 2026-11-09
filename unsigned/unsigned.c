/*******************************
 ビット演算
 & : ビットごとのAND (a & b) aとbのビット単位のAND
 | : ビットごとのOR  (a | b) aとbのビット単位のOR
 ^ : ビットごとの排他的OR (a ^ b) aとbのビット単位の排他的OR
 << : 左シフト (a << b) aをbビット分左へシフト(2倍)
 >> : 右シフト (a >> b) aをbビット分右へシフト(1/2)
 ~ : ビット単位の反転 (~a) aの各ビットを反転

*********************************/

#include <stdio.h>

void unsignedChar(unsigned char x){
	
	int i;
	
	printf("%4u %02x ", x, x);
	for(i=7; i>=0; i--){
		printf("%d ", (x>>i));
		printf("%d,", (x>>i) & 1); 		//右シフトして'00000001'とAND演算?
										//('00000001'とAND演算で1bit目だけ取り出す)
										//これで2進に変換
	}
	printf("\n");
	return;
}

void main(){
	unsignedChar(0x0F);
	return;
}