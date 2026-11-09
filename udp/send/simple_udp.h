/*
 * simple_udp.h
 *
 *  Created on: 2025/04/08
 *      Author: DEV-25P257
 */

# include <sys/types.h>
# include <winsock2.h>
# include <unistd.h>
# include <string.h>

#ifndef SIMPLE_UDP_H_
#define SIMPLE_UDP_H_


class simple_udp {
	int sock;
	struct sockaddr_in addr;
	WSADATA wsaData;
public:
	simple_udp(std::string address, int port){
		WSAStartup(MAKEWORD(2,0), &wsaData);
		sock = socket(AF_INET, SOCK_DGRAM, 0);
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr(address.c_str());
		addr.sin_port = htons(port);
	}
	void udp_send(std::string word){
		sendto(sock, word.c_str(), word.length(), 0, (struct sockaddr *)&addr, sizeof(addr));
	}

	void udp_bind(){
		bind(sock, (const struct sockaddr *)&addr, sizeof(addr));

	}
	std::string udp_recv(){
		#define BUFFER_MAX 400
		char buf[BUFFER_MAX];
		memset(buf, 0, sizeof(buf));
		recv(sock, buf, sizeof(buf), 0);
		return std::string(buf);
	}
	void udp_recv(char *buf, int size){
		memset(buf, 0, size);
		recv(sock, buf, size, 0);
	}

	~simple_udp(){
		close(sock);
	}
};


#endif /* SIMPLE_UDP_H_ */
