#include "unp.h"

void sig_chld(int);

int main(int argc, char **argv) {
	int listenfd, connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr, srvaddr;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	
	bzero(&srvaddr, sizeof(struct sockaddr));
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	srvaddr.sin_port = htons(SERV_PORT);

	int reuse = 1;
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
	Bind(listenfd, (struct sockaddr*) &srvaddr, sizeof(struct sockaddr));

	Listen(listenfd, LISTENQ);

    Signal(SIGCHLD, sig_chld);
	for(;;) {
		clilen = sizeof(cliaddr);
		if ( （connfd = Accept(listenfd, (struct sockaddr*) &cliaddr, &clilen)） < 0) {
			if (errno == EINTR)
				continue;
			else 
				err_sys("accept error");
		}

		if (childpid = fork() == 0) {
			close(listenfd);
			str_echo(connfd);
			exit(0);
		}

		close(connfd);
	}
}
