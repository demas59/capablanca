main: main.o grille.o piece.o coord.o
	gcc -o capa.exe main.o grille.o piece.o coord.o -Walls -g;
	#rm *.o;



piece.o: piece.c
	gcc -o piece.o -c piece.c -Walls -g

grille.o: grille.c
	gcc -o grille.o -c grille.c -Walls -g

coord.o: coord.c
	gcc -o coord.o -c coord.c -Walls -g

main.o: main.c struct.h
	gcc -o main.o -c main.c -Walls -g