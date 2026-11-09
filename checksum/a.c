#include <stdio.h>
#include <stdlib.h>

#define INT_TO_HEX "0123456789ABCDEF"
#define AAA "1234567890"

void main(){
	unsigned char target[10];
	unsigned char i;
	unsigned char sum;
	unsigned char checksum[2];
	
	memset(target, 0x00, sizeof(target));
	memcpy(target, AAA, sizeof(target));
	
	// 計算（下位１バイト以外はオーバーフローして勝手に消える）
	sum = 0;
	for(i = 0;i < 10;i++)
	{
	    sum += target[i];
	}
	
	printf("%x\n",sum);
	
	// ASCIIへ
	checksum[1] = INT_TO_HEX[(sum & 0x0F)];
	checksum[0] = INT_TO_HEX[((sum >> 4) & 0x0F)];
	
	printf("%x %x", checksum[0], checksum[1]);
	
}
