TARGETS=main

CC = gcc
CFLAGS = -W -Wall `pkg-config --cflags MLV`
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`



main :point.o main.o
	$(CC) $(CFLAGS) $(LDFLAGS)point.o load.o main.o $(LDLIBS) -o main

main.o : point.c main.c
	$(CC) $(CFLAGS) -c main.c point.c

load.o : load.c load.c
	$(CC) $(CFLAGS) -c load.c -o load.o

point.o : point.c point.h
	$(CC) $(CFLAGS) -c point.c -o point.o



clean :
	rm -rf *.o main
