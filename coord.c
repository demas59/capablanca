#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"
// Créer une variable coordonnées
Coord createCoord(int x, int y)
{
	Coord c=(Coord)malloc(sizeof(struct coord_));
	c->x=x;
	c->y=y;
	return c;
}

// Renvoi l'indice en fonction d'une position
int getIndice(int i, int j)
{
	return i*10+j;
}

// Ajoute les coordonnées d'un déplacement dans les déplacements possibles pour une pièces
void ajoutCoord(Coord coord,Piece piece){
	if(piece -> deplacement -> nombre_element == piece -> deplacement -> taille_max){
		piece -> deplacement -> taille_max += 10;
		piece -> deplacement -> mouvements = (Coord *)realloc(piece -> deplacement -> mouvements, sizeof(Coord) * piece -> deplacement -> taille_max);
	}
	piece -> deplacement -> mouvements [piece -> deplacement -> nombre_element] = coord;
	piece -> deplacement -> nombre_element++;
}

// Récupère les caractéristiques d'une pièce en fonction de ses coordonnées
Piece getPieceByCoord(Coord coord,Grille plateau){
	return plateau -> pions[getIndice(coord -> x, coord -> y)];
}
