main: main.o grille.o piece.o coord.o
	gcc -o capa.exe main.o grille.o piece.o coord.o -Wall -ansi -g;
	#rm *.o;



piece.o: piece.c
	gcc -o piece.o -c piece.c -Wall -ansi -g

grille.o: grille.c
	gcc -o grille.o -c grille.c -Wall -ansi -g

coord.o: coord.c
	gcc -o coord.o -c coord.c -Wall -ansi -g

main.o: main.c struct.h
	gcc -o main.o -c main.c -Wall -ansi -g