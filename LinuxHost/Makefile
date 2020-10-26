
CC=gcc
CFLAGS=-fpic -g
BINS = tst2 dump
INC = -I ../Common

all:	$(BINS)

doc:
	doxygen Doxyfile

tst2:	tst2.c
#	gcc -g tst2.c -o tst2 -L/usr/local/lib -lser
	gcc $(CFLAGS) $(INC) tst2.c -o tst2 -L. -lser

dump:	dump.c
	gcc $(CFLAGS) $(INC) dump.c -o dump -L. -lser

clean:
	rm -f *.o *.so $(BINS) cscope.out
	rm -rf Doc
