
CC=gcc
CFLAGS=-g

BINS=tst

all:	$(BINS)

msg.o:	msg.c msg.h
	$(CC) $(CFLAGS) -c msg.c -o msg.o

tst:	tst.c msg.o
	$(CC) $(CFLAGS) tst.c msg.o -o tst

clean:
	rm -f $(BINS) *.o

