#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

Grille createGrille()
{
	Grille g=(Grille)malloc(sizeof(struct grille_));
	g->pions=malloc(sizeof(struct piece_)*80);
	return g;
}


/*Créé la grille et place toutes les pièces*/
Grille initialisation(){
	Grille grille = createGrille();
/*	grille->pions = (Piece **)malloc(sizeof(struct piece_)*10*8);*/

	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<8;j++){
			printf("a%d", (i*10)+j);
			grille -> pions[(i*10)+j]=createPiece(0, i, j, 0);
		}
	}
	printf("fin\n");
	return grille;
}


/*Affiche la grille de jeu*/
void affichage(Grille grille){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<8;j++){
			printf("%d - %d\n", grille->pions[(i*10)+j]->coord->x, grille->pions[(i*10)+j]->coord->y);
		}
	}
}