CC = gcc

echocli: echocli.o
	gcc echocli.o ${LDLAGS} -o echocli

CFLAGS += -I ../../unplib
LDFLAGS += -L ../../unplib
LDFLAGS += -lunp

clean:
	rm -rf *.o echocli

