
CC=gcc
CFLAGS=-g

BINS=tst

all:	$(BINS)

msg.o:	msg.c msg.h
	$(CC) $(CFLAGS) -c msg.c -o msg.o

tst:	tst.c ../Common/msg.o
	make -C ../Common
	$(CC) $(CFLAGS) tst.c ../Common/msg.o -I ../Common -o tst

clean:
	make -C ../Common clean
	rm -f $(BINS) *.o

