main: main.o grille.o piece.o coord.o game.o deplacement.o
	gcc -o capa.exe main.o grille.o piece.o coord.o game.o deplacement.o -Wall -g;
	#rm *.o;


game.o: game.c
	gcc -o game.o -c game.c -Wall -g

piece.o: piece.c
	gcc -o piece.o -c piece.c -Wall -g

grille.o: grille.c
	gcc -o grille.o -c grille.c -Wall -g

coord.o: coord.c
	gcc -o coord.o -c coord.c -Wall -g

deplacement.o: deplacement.c
	gcc -o deplacement.o -c deplacement.c -Wall -g

main.o: main.c struct.h
	gcc -o main.o -c main.c -Wall -g