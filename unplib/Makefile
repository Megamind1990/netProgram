NPLIB_OBJS = error.o

all: ${NPLIB_OBJS}
	ar rv libunp.a $?
	
error.o: basic.h

clean:
	rm -rf ${NPLIB_OBJS} *.a
