#include "unp.h"

int main(int argc, char** argv) {
	int sockfd, connfd;
	struct sockaddr_in servaddr;

	if (argc != 2) {
		err_quit("usage: tcpcli <IPAddress>");
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(struct sockaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = SERV_PORT;
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	connect(sockfd, (struct sockaddr*) &servaddr, sizeof(struct sockaddr));

	//src_cli(stdin, sockfd);

	exit(0);
}

