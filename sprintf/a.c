#include <stdio.h>
#include <stdlib.h>

#define LENGTH 4

#define UB unsigned char
#define ER int
#define E_OK 0
#define E_NG -1

typedef struct {
	UB aa[2];
	UB bb[2];
}T_A;

typedef struct {
	UB cc[2];
}T_B;

typedef struct {
	T_A a;
	T_B b;
}T_ALL;



void main(){
	T_ALL tAll;

	memset(tAll.a.aa, 0x00, sizeof(tAll.a.aa));
}