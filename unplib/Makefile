NPLIB_OBJS = error.o

all: ${NPLIB_OBJS}
	ar rsv libunp.a $?
	
error.o: unp.h

clean:
	rm -rf ${NPLIB_OBJS} *.a
