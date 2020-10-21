
CC=gcc
CFLAGS=-fpic
BINS = tst2

all:	$(BINS)

doc:
	doxygen Doxyfile

tst2:	tst2.c
#	gcc -g tst2.c -o tst2 -L/usr/local/lib -lser
	gcc -g tst2.c -o tst2 -L. -lser

clean:
	rm -f *.o *.so $(BINS) cscope.out
	rm -rf Doc
