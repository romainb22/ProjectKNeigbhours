TARGETS=main

CC = gcc
CFLAGS = -W -Wall `pkg-config --cflags MLV`
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`



main :point.o main.o
	$(CC) $(CFLAGS) $(LDFLAGS) point.o tableau.o load.o main.o $(LDLIBS) -o main

main.o : point.c load.c tableau.o main.c
	$(CC) $(CFLAGS) -c main.c point.c load.c

load.o : load.c load.h
	$(CC) $(CFLAGS) -c load.c -o load.o

tableau.o : tableau.c tableau.h
	$(CC) $(CFLAGS) -c tableau.c -o tableau.o


point.o : point.c point.h
	$(CC) $(CFLAGS) -c point.c -o point.o



clean :
	rm -rf *.o main
