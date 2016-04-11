CC=gcc

echocli: echocli.o str_cli.o
	gcc str_cli.o echocli.o ${LDFLAGS} -o echocli

CFLAGS += -I ../../unplib
LDFLAGS += -L ../../unplib
LDFLAGS += -lunp

clean:
	rm -rf *.o echocli

