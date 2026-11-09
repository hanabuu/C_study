#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define B char
#define H short
#define W int
#define UB unsigned char
#define UH unsigned short
#define UW unsinged int
#define ER int
#define E_OK 0
#define E_NG -1

#define DEVICE_FW_VERSION_LEN 9

UB subCpuFw[DEVICE_FW_VERSION_LEN];
UB pgHeader[DEVICE_FW_VERSION_LEN];

void init(){
	int i;
	
	memset( subCpuFw, 0x00, DEVICE_FW_VERSION_LEN );
	memset( pgHeader, 0x00, DEVICE_FW_VERSION_LEN );
	
	//memcpy( subCpuFw, "000000000", DEVICE_FW_VERSION_LEN );
	//memcpy( pgHeader, "000000001", DEVICE_FW_VERSION_LEN );
	for(i=0; i<DEVICE_FW_VERSION_LEN;i++){
		subCpuFw[i]=i;
	}
	for(i=0; i<DEVICE_FW_VERSION_LEN;i++){
		pgHeader[i]=i;
	}
	//pgHeader[8] = 1;
}

void main(void){

	B cmpResult;
	
	init();
	
	cmpResult = memcmp( subCpuFw, pgHeader, DEVICE_FW_VERSION_LEN );
	
	printf("result = %d\n", cmpResult);
	
	return;
}
