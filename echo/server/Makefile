CC = gcc

echosrv: sigchldwait.o echosrv.o str_echo.o
	gcc echosrv.o str_echo.o sigchldwait.o ${LDFLAGS} -o echosrv

CFLAGS += -I ../../unplib
LDFLAGS += -L ../../unplib
LDFLAGS += -lunp

clean:
	rm -rf *.o echosrv

