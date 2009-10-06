#ifndef SOCKET_CPP
#define SOCKET_CPP
#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include "robobo.h"
class Socket {
	public:
		Socket(std::string server, unsigned short port);
		~Socket();
		void sendMsg(std::string message);
		std::string receive();
		std::vector<std::string> parseLine(std::string message);
		void closeConnection();
		bool isConnected();
	private:
		int socketfd, status;
		sockaddr_in socketAddr;
		char inputBuffer[2];
		std::string messageString;
		std::vector<std::string> messageParams;
		bool connected, seenCR;
};
#endif
