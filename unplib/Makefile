NPLIB_OBJS = error.o writen.o readn.o readline1.o wrapsock.o signal.o

all: ${NPLIB_OBJS}
	ar rsv libunp.a $?
	
error.o: unp.h

clean:
	rm -rf ${NPLIB_OBJS} *.a
