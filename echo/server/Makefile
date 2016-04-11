CC = gcc

echosrv: echosrv.o str_echo.o
	gcc echosrv.o str_echo.o ${LDFLAGS} -o echosrv

CFLAGS += -I ../../unplib
LDFLAGS += -L ../../unplib
LDFLAGS += -lunp

clean:
	rm -rf *.o echosrv

