CC=gcc

daytimesrv: daytimesrv.o
	gcc daytimesrv.o ${LDFLAGS} -o daytimesrv

CFLAGS += -I ../unplib

LDFLAGS += -L ../unplib
LDFLAGS += -lunp


clean:
	rm -rf daytimesrv.o daytimesrv
