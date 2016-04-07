#include "unp.h"

int main(int argc, char **argv) {
	int listenfd, connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr, srvaddr;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	
	bzero(&srvaddr, sizeof(struct sockaddr));
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	srvaddr.sin_port = htons(SERV_PORT);

	bind(listenfd, (struct sockaddr*) &srvaddr, sizeof(struct sockaddr));

	listen(listenfd, LISTENQ);

	for(;;) {
		clilen = sizeof(cliaddr);
		connfd = accept(listenfd, (struct sockaddr*) &cliaddr, &clilen);

		if (childpid = fork() == 0) {
			close(listenfd);
			//str_echo(connfd);
			exit(0);
		}

		close(connfd);
	}
}
