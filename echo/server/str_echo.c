#include "unp.h"

void str_echo(int sockfd) {
	ssize_t n;
	char buf[MAXLINE];

again:
	while ( (n = read(sockfd, buf, MAXLINE)) > 0) {
		if (buf == NULL) 
			return;
		writen(sockfd, buf, n);
	}

	if (n < 0 && errno == EINTR) {
		printf("str_echo EINTER");
		goto again;
	} else if ( n < 0) {
		err_sys("str_echo: read error");
	}

	printf("return to main\n");
}
