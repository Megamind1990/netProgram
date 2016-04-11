#include "unp.h"

int Socket(int family, int type, int protocol) {
	int n;

	if ( (n = socket(family, type, protocol)) < 0) 
		err_sys("socket error");
	return n;
}


int Bind(int fd, const struct sockaddr* sa, socklen_t salen) {
	int n;

	if ( (n = bind(fd, sa, salen)) < 0)
		err_sys("bind error");
	return n;
}


int Listen(int fd, int backlog) {
	int n;
	char* ptr;

	if ( (ptr = getenv("LISTENQ")) != NULL) 
		backlog = atoi(ptr);

	if ( (n = listen(fd, backlog)) < 0)
		err_sys("listen error");

	return n;
}


int Connect(int fd, const struct sockaddr* sa, socklen_t salen) {
	int n;

	if ( (n = connect(fd, sa, salen)) < 0) 
		err_sys("connet error");

	return n;
}

int Accept(int fd, struct sockaddr* cliaddr, socklen_t *addrlen) {
	int n;

	if ( (n = accept(fd, cliaddr, addrlen)) < 0) 
		err_sys("accept error");

	return n;
}
