#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

void parcoursCoord(Coord * coords,int nombre_element){
	int i;
	for(i = 0; i<nombre_element; i++){
		Coord coord = *(coords + i);
		printf("coord: %c%d\n",'a'+coord->y,coord->x + 1 );
	}
}

Coord * proposerDeplacer(Grille grille,Piece piece){
	int taille_max = 20;
	int nombre_element = 0;

	Coord * deplacement = malloc(sizeof(Coord) * taille_max);

	switch(piece -> type){
		case 't': mouvTour(grille,piece,deplacement,&taille_max,&nombre_element);
		break;
		case 'p': mouvPion(grille,piece,deplacement,&taille_max,&nombre_element);
		break;
	}

	parcoursCoord(deplacement,nombre_element);
	return deplacement;
}

Piece choosePawn(Grille grille)
{
	char * choix = malloc(sizeof(char)*2);
	printf("Joueur %d, veuillez choisir une piece a deplacer (ex: a2, b3, d6).\n", ((grille->tour)%2)+1);
	scanf("%s", choix);

	int colone=((int)choix[0]-(int)'a');
	int ligne=(int)choix[1]-(int)'1';

	int indice=getIndice(ligne, colone);
	int joueur=(grille->tour)%2+1;

	if(joueur==grille->pions[indice]->color)
	{
		return grille->pions[indice];
	}else
	{
		return NULL;
	}
}
