# Make file for PA2
# Stephanie Racca

CFLAGS = -g

life: game.o board.o life.o
	gcc $(CFLAGS) -Wall life.o game.o board.o -o life

game.o: game.h game.c
	gcc $(CFLAGS) -Wall -c game.c

board.o: board.h board.c
	gcc $(CFLAGS) -Wall -c board.c

life.o: board.h  game.h life.c
	gcc $(CFLAGS) -Wall -c life.c

clean:
	rm -f life.o game.o board.o life

all: life