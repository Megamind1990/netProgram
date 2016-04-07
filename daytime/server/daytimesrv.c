#include "unp.h"
#include <time.h>

int main(int argc, char **argv) {
	int listenfd, connfd;
	struct sockaddr_in servaddr;
	char buff[MAXLINE + 1];
	time_t ticks;

    if ( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
            err_sys("socket error");

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(13);

	if ( bind(listenfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0)
        err_sys("bind error");

	if ( listen(listenfd, LISTENQ) < 0)
        err_sys("listen error");

	for (;;) {
		if ( (connfd = accept(listenfd, (struct sockaddr *) NULL, NULL)) < 0) 
            err_sys("accept_error");

		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		write(connfd, buff, strlen(buff));

		close(connfd);
	}

} 
