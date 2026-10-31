#include <stdio.h>
#include <string.h>

void test(char *tes){
	printf("ポインタ渡し(b)：%d\n", &tes[0]);
	printf("ポインタ渡し(b)：%d\n", tes);
	memcpy(tes, "abc", 3);
	printf("関数内のb = %s\n", tes);
}

void test2(char tes[4]){
	printf("引数が実引数(c)：%d\n", &tes[0]);
	printf("引数が実引数(c)：%d\n", tes);
	memcpy(tes, "def", 3);				// ①出力される
	//memcpy(&tes, "def", 3);			// ②出力されない
	//memcpy(&tes[0], "def", 3);		// ③①と同じ意味
	printf("関数内のc = %s\n", tes);
	
	//結論：配列で宣言した変数はポインタと同じ感じで扱う
}

void test3(int tes){
	tes = 150;
	printf("関数内のa = %d\n", tes);
}

void test4(int *tes){
	//&tes = 50;					//ポインタの数値どうやってかえる？？
	printf("int test4：%d\n", tes);
}


void main(){
	int a = 12, d = 0;
	char b[4], c[4]; 		//char型配列
	char *p;		//アドレスの先頭アドレスを記憶するポインタ
	
	memset(b, 0x00, sizeof(b));
	memset(c, 0x00, sizeof(c));

	p = b;			//「pはbと同じ」というか「pがbを指してる」

	
	printf("bのアドレス：%d\n", &b[0]);
	test(b);
	printf("mainのb = %s\n", b);
	printf("mainのp = %s\n\n", p);
	
	printf("cのアドレス：%d\n", &c[0]);
	test2(c);
	printf("mainのc = %s\n\n", c);

	printf("mainのa = %d\n", a);
	test3(a);
	printf("mainのa = %d\n", a);
	
	printf("mainのd(アドレス) = %d\n", &d);
	test4(&d);		//先頭アドレス渡す
}