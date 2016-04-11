#include "unp.h"

void str_cli(FILE *fp, int sockfd) {
	char sendline[MAXLINE], recvline[MAXLINE];
	int recvlen = 0;

	while (fgets(sendline, MAXLINE, fp) != NULL) {

		int n = writen(sockfd, sendline, strlen(sendline));

		if ( (recvlen = readline(sockfd, recvline, MAXLINE)) == 0) {
			err_quit("str_cli: server terminated ");
		}

		fputs(recvline, stdout);
	}
}
