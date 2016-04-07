CC = gcc

echosrv: echosrv.o
	gcc echosrv.o ${LDLAGS} -o echosrv

CFLAGS += -I ../../unplib
LDFLAGS += -L ../../unplib
LDFLAGS += -lunp

clean:
	rm -rf *.o echosrv

