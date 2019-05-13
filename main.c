#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

/*Créé la grille et place toutes les pièces*/
Grille initialisation(){
	Grille grille = malloc(sizeof(struct grille_));
	grille->pions = (Piece **)malloc(sizeof(struct piece_)*10*8);

	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<8;j++){
			Coord coord = malloc(sizeof(struct coord_));
			coord->x = i;
			coord->y = j;
			grille->pions[i][j]->coord = coord;
		// 	grille->pions[i][j]->actif = -1;
		// 	grille->pions[i][j]->type = 'a';
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
		}
	}
}

void mouvement(Grille grille, Piece piece){

}

void Echec(Grille grille){

}

int main(){
	Grille grille = initialisation();
	/*affichage(grille);*/
}