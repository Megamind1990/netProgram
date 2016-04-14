#include "unp.h"

void sig_chld(int signo)
{
	printf("sig_chld call");
	pid_t pid;
	int stat;
	
	while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0)
		printf("child %d terminated\n", pid);

	return;
}
