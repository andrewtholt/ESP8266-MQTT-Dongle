
CC=gcc
CFLAGS=-g

BINS=main

all:	$(BINS)

msg.o:	msg.c msg.h
	$(CC) $(CFLAGS) -c msg.c -o msg.o

main:	main.c msg.o
	$(CC) $(CFLAGS) main.c msg.o -o main

clean:
	rm -f $(BINS) *.o

