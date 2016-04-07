#ifndef _BASIC_H_
#define _BASIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAXLINE 4096
#define LISTENQ 1024
#define SERV_PORT 9877

void err_sys(const char* fmt, ...);
void err_quit(const char* fmt, ...);


#endif
