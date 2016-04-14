#include "unp.h"

int main(int argc, char** argv) {
	int sockfd, connfd, sockfds[10];
	struct sockaddr_in servaddr;

	if (argc != 2) {
		err_quit("usage: tcpcli <IPAddress>");
	}

	int i = 0;
	for (i = 0; i < 10; i++) {

		sockfd = Socket(AF_INET, SOCK_STREAM, 0);
		if (sockfd <= 0) 
			err_quit("socket fail");

		bzero(&servaddr, sizeof(struct sockaddr));

		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(SERV_PORT);
		inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

		Connect(sockfd, (struct sockaddr*) &servaddr, sizeof(struct sockaddr));

		sockfds[i] = sockfd;
	}
	str_cli(stdin, sockfds[0]);

	exit(0);
}

