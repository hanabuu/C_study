//============================================================================
// Name        : testUdpRecv.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "simple_udp.h"
using namespace std;

simple_udp udp0("0.0.0.0",47808);

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	udp0.udp_bind();
	while (1){
		#define BUFFER_MAX 400
		char buf[BUFFER_MAX];
		memset(buf, 0, sizeof(buf));
//		std::string rdata=udp0.udp_recv();
		int len = udp0.udp_recv(buf, BUFFER_MAX);
		printf("受信長:%d\n", len);
		printf("%d %d %d %d %d %d %d %d %d %d\n", buf[0],buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7],buf[8],buf[9]);

//		printf("recv:%s\n", rdata.c_str());
	 }
	return 0;
}
