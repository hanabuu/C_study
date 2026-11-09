#include <stdio.h>
#include <string.h>

typedef int                 COMMON_ST;
typedef signed char         B;
typedef signed short        H;
typedef signed long         W;
typedef unsigned char       UB;
typedef unsigned short      UH;
typedef unsigned long       UW;
typedef char                VB;
typedef short               VH;
typedef long                VW;
typedef void                *VP;
typedef void                (*FP)(void);

#define COMMON_LOG_MAXDATA 1000U

typedef struct{
	//! データ長
	UH data_len;
	//! 送信位置
	UH sendPosition;
	//! 挿入位置
	UH setPosition;
	//! バッファ
	UB sendData[COMMON_LOG_MAXDATA];
}T_TX_BUFFER_SERIAL;

static T_TX_BUFFER_SERIAL tTxBufferSerial;

void storageBuffer(UH sendNum, UB* sendData){
	
	if( COMMON_LOG_MAXDATA > (tTxBufferSerial.data_len + sendNum) ){
		memcpy( &tTxBufferSerial.sendData[tTxBufferSerial.data_len], sendData, sendNum );
		tTxBufferSerial.data_len += sendNum;
	} else {
		// バッファあふれ
		// あふれた電文は捨てる
		;
	}
}

void printBuffer(){
	UH cnt;

	for( cnt = 0; cnt > tTxBufferSerial.data_len; cnt++ ){
		printf("%d", tTxBufferSerial.sendData[cnt]);
	}
}

void main(){
	
	storageBuffer(50, (UB*)"abcdefg\n");
	
	storageBuffer(50, (UB*)"hijklmn\n");
	
}