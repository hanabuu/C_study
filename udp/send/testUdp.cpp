//============================================================================
// Name        : testUdp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "simple_udp.h"
using namespace std;

simple_udp udp0("127.0.0.1",4001);

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	udp0.udp_send("hello!");
	return 0;
}
