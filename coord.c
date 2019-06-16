#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

Coord createCoord(int x, int y)
{
	Coord c=(Coord)malloc(sizeof(struct coord_));
	c->x=x;
	c->y=y;
	return c;
}

int getIndice(int i, int j)
{
	return i*10+j;
}

void ajoutCoord(Coord coord,Piece piece){
	if(piece -> deplacement -> nombre_element == piece -> deplacement -> taille_max){
		piece -> deplacement -> taille_max += 10;
		piece -> deplacement -> mouvements = (Coord *)realloc(piece -> deplacement -> mouvements, sizeof(Coord) * piece -> deplacement -> taille_max);
	}
	piece -> deplacement -> mouvements [piece -> deplacement -> nombre_element] = coord;
	piece -> deplacement -> nombre_element++;
}

Piece getPieceByCoord(Coord coord,Grille plateau){
	return plateau -> pions[getIndice(coord -> x, coord -> y)];
}
