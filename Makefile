TARGETS=main

CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O3 `pkg-config --cflags MLV`
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`



main :point.o main.o
	$(CC) $(CFLAGS) $(LDFLAGS)point.o main.o $(LDLIBS) -o main

main.o : point.c main.c
	$(CC) $(CFLAGS) -c main.c point.c

point.o : point.c point.h
	$(CC) $(CFLAGS) -c point.c -o point.o



clean :
	rm -rf *.o
