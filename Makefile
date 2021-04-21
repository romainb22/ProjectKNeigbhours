TARGETS=main

CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O3 `pkg-config --cflags MLV`
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`



main :main.o
	$(CC) $(CFLAGS) $(LDFLAGS)main.o $(LDLIBS) -o main

main.o :
	$(CC) $(CFLAGS) 


clean :
	rm -rf *.o
