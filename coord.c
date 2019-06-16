#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"


// Fonction qui crée des coordonnées en fonction d'un abscisse et d'un ordonnée
Coord createCoord(int x, int y)
{
	Coord c=(Coord)malloc(sizeof(struct coord_));
	c->x=x;
	c->y=y;
	return c;		// Renvoi une variable coordonnée, qui contier un x et un y
}

// Return l'indice d'un élément dans un tableau en fonction de sa position
int getIndice(int i, int j)
{
	return i*10+j;	// Renvoi l'indice à la position correspondante
}

// Ajoute les coordonnées des déplacements aux mouvements possible par la pièce
void ajoutCoord(Coord coord,Piece piece){
	if(piece -> deplacement -> nombre_element == piece -> deplacement -> taille_max){
		piece -> deplacement -> taille_max += 10;
		piece -> deplacement -> mouvements = (Coord *)realloc(piece -> deplacement -> mouvements, sizeof(Coord) * piece -> deplacement -> taille_max);
	}
	piece -> deplacement -> mouvements [piece -> deplacement -> nombre_element] = coord;
	piece -> deplacement -> nombre_element++;
}

// Renvoi la pièce situé à la coordonnée renseigné
Piece getPieceByCoord(Coord coord,Grille plateau){
	return plateau -> pions[getIndice(coord -> x, coord -> y)];	// Renvoi la pièce correspondante aux propriété des arguments entrés
}
