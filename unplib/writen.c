#include "unp.h"

ssize_t writen(int fd, const void* vptr, size_t n) {
	size_t nleft;
	size_t nwritten;

	const char* ptr;
	nleft = n;
	ptr = vptr;
	while (nleft > 0) {
		if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
			if (errno == EINTR) {
				nwritten = 0;
			} else {
				return -1;
			}
		} else  {
			return -1;
		}

		nleft -= nwritten;
		ptr += nwritten;
	}

	return (n-nleft);
}


int Writen(int fd, const void* vptr, size_t n) {
	int n = 0;

	if (n )

}