CC=gcc
CFLAGS=-W --ansi --std=c99 --pedantic
LDFLAGS=`sdl-config --cflags --libs` -lSDL_image
EXEC=main

all: $(EXEC)

main: main.o ../coord.o ../deplacement.o ../game.o ../grille.o ../piece.o graphique.o
	$(CC) -o main main.o ../coord.o ../deplacement.o ../game.o ../grille.o ../piece.o graphique.o $(CFLAGS)  $(LDFLAGS)

coord : ../coord.c
	$(CC) -o ../coord.o -c ../coord.c $(CFLAGS) $(LDFLAGS)

deplacement : ../deplacement.c
	$(CC) -o ../deplacement.o -c ../deplacement.c $(CFLAGS) $(LDFLAGS)

game : ../game.c
	$(CC) -o ../game.o -c ../game.c $(CLFAGS) $(LDFLAGS)

grille : ../grille.c
	$(CC) -o ../grille.o -c ../grille.c $(CLFAGS) $(LDFLAGS)

piece : ../piece.c
	$(CC) -o ../piece.o -c ../piece.c $(CFLAGS) $(LDFLAGS)

graphique : graphique.c
	$(CC) -o graphique.o -c graphique.c $(CFLAGS) $(LDFLAGS)

chess : main.c
	$(CC) -o main.o -c main.c $(CFLAGS) $(LDFLAGS)

#main.o: Chess/main.c  struct.h
#	$(CC) -o main.o -c Chess/main.c $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf *.o main
