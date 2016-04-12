#include "unp.h"

int main(int argc, char** argv) {
	int sockfd, connfd;
	struct sockaddr_in servaddr;

	if (argc != 2) {
		err_quit("usage: tcpcli <IPAddress>");
	}

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd <= 0) 
		err_quit("socket fail");

	bzero(&servaddr, sizeof(struct sockaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	Connect(sockfd, (struct sockaddr*) &servaddr, sizeof(struct sockaddr));
	str_cli(stdin, sockfd);

	exit(0);
}

