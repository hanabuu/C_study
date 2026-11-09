#include <stdio.h>
#include <stdlib.h>

//#define STATUSNUM 4
//#define TUTINUM 3

enum Status {
	s_Seizyo,
	s_Izyo,
	s_Dansen,
	s_DansenIzyo,
	
	STATUSNUM
} status;

enum Tuti {
	t_Seizyo,
	t_Izyo,
	t_Dansen,
	
	TUTINUM
} tuti;

//static int const CHANGESTATUSTABLE[STATUSNUM][TUTINUM] = {
const CHANGESTATUSTABLE[STATUSNUM][TUTINUM] = {
	0,1,2,
	0,1,3,
	0,1,2,
	0,1,3
};

void main(void){

	//enum Status status;
	//enum Tuti tuti;
	
	status = s_Seizyo;
	tuti = t_Seizyo;
	printf("%d\n", CHANGESTATUSTABLE[status][tuti]);
	
	status = s_Seizyo;
	tuti = t_Izyo;
	printf("%d\n", CHANGESTATUSTABLE[status][tuti]);
	
	status = s_Seizyo;
	tuti = t_Dansen;
	printf("%d\n", CHANGESTATUSTABLE[status][tuti]);
	
	
	status = s_Izyo;
	tuti = t_Seizyo;
	printf("%d\n", CHANGESTATUSTABLE[status][tuti]);
	
	status = s_Izyo;
	tuti = t_Izyo;
	printf("%d\n", CHANGESTATUSTABLE[status][tuti]);
	
	status = s_Izyo;
	tuti = t_Dansen;
	printf("%d\n", CHANGESTATUSTABLE[status][tuti]);


	status = s_Dansen;
	tuti = t_Seizyo;
	printf("%d\n", CHANGESTATUSTABLE[status][tuti]);
	
	status = s_Dansen;
	tuti = t_Izyo;
	printf("%d\n", CHANGESTATUSTABLE[status][tuti]);
	
	status = s_Dansen;
	tuti = t_Dansen;
	printf("%d\n", CHANGESTATUSTABLE[status][tuti]);
	
	
	status = s_DansenIzyo;
	tuti = t_Seizyo;
	printf("%d\n", CHANGESTATUSTABLE[status][tuti]);
	
	status = s_DansenIzyo;
	tuti = t_Izyo;
	printf("%d\n", CHANGESTATUSTABLE[status][tuti]);
	
	status = s_DansenIzyo;
	tuti = t_Dansen;
	printf("%d\n", CHANGESTATUSTABLE[status][tuti]);
	
	return;
}