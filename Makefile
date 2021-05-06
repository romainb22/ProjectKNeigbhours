TARGETS=main

CC = gcc
CFLAGS = -W -g -Wall `pkg-config --cflags MLV`
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`



main :pile.o liste.o load.o affichage.o point.o main.o save.o neighbours.o
	$(CC) $(CFLAGS) $(LDFLAGS) pile.o liste.o load.o affichage.o point.o save.o main.o neighbours.o $(LDLIBS) -o main

main.o : pile.c load.c liste.c affichage.c point.c main.c save.c neighbours.c
	$(CC) $(CFLAGS) -c main.c pile.c load.c liste.c affichage.c point.c neighbours.c

load.o : load.c load.h
	$(CC) $(CFLAGS) -c load.c -o load.o

save.o : save.c save.h
	$(CC) $(CFLAGS) -c save.c -o save.o

liste.o : liste.c liste.h
	$(CC) $(CFLAGS) -c liste.c -o liste.o

affichage.o : affichage.c affichage.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c affichage.c -o $(LDFLIBS) affichage.o

pile.o : pile.c pile.h
	$(CC) $(CFLAGS) -c pile.c -o pile.o

point.o : point.c point.h
	$(CC) $(CFLAGS) -c point.c -o point.o

neigbhours.o : neighbours.c neighbours.h
	$(CC) $(CFLAGS) -c neighbours.c -o neighbours.o


clean :
	rm -rf *.o main *.out
