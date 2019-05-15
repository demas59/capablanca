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

void ajoutCoord(Coord * coords,Coord coord,int * taille_max,int * nombre_element){
	if(*nombre_element == *taille_max){
		*taille_max += 10;
		realloc(coords, sizeof(Coord) * (*taille_max));
	}
	*(coords + *nombre_element) = coord;
	(*nombre_element)++;
}