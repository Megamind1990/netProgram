CC=gcc
daytimecli: daytimecli.o
	gcc daytimecli.o ${LDFLAGS} -o daytimecli

CFLAGS += -I ../../unplib

LDFLAGS += -L ../../unplib
LDFLAGS += -lunp


clean:
	rm -rf *.o daytimecli
