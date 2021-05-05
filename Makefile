TARGETS=main

CC = gcc
CFLAGS = -W -g -Wall `pkg-config --cflags MLV`
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`



main :pile.o liste.o load.o affichage.o point.o main.o
	$(CC) $(CFLAGS) $(LDFLAGS) pile.o liste.o load.o affichage.o point.o main.o $(LDLIBS) -o main

main.o : pile.c load.c liste.c affichage.c point.c main.c
	$(CC) $(CFLAGS) -c main.c pile.c load.c liste.c affichage.c point.c

load.o : load.c load.h
	$(CC) $(CFLAGS) -c load.c -o load.o

liste.o : liste.c liste.h
	$(CC) $(CFLAGS) -c liste.c -o liste.o

affichage.o : affichage.c affichage.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c affichage.c -o $(LDFLIBS) affichage.o

pile.o : pile.c pile.h
	$(CC) $(CFLAGS) -c pile.c -o pile.o

point.o : point.c point.h
	$(CC) $(CFLAGS) -c point.c -o point.o


clean :
	rm -rf *.o main *.out
