#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"


Piece newPion(char type,int equipe){
	Piece pion = (Piece)malloc(sizeof(struct piece_));
	pion->type = type;
	pion->color = equipe;
	if(equipe != 0){
		pion->actif = 1;
	}else{
		pion->actif = -1;
	}
	return pion;
}

/*Créé la grille et place toutes les pièces*/
Grille initialisation(){
	Piece * pieces = malloc(sizeof(struct piece_)*10*8);
	int i,j;

	for(i=0;i<8;i++){
		for(j=0;j<10;j++){
			(*(pieces+(i*10+j))) = newPion('0', 0);
		}
	}
	Grille grille = (Grille) malloc(sizeof(struct grille_));
	grille -> pions = pieces;
	return grille;
}

/*Affiche la grille de jeu*/
void affichage(Grille grille){
	int i,j;
	Piece * plateau = grille -> pions;
	for(i=0;i<8;i++){
		for(j=0;j<10;j++){
			printf("%c",(*(plateau+(i*10+j)))->type);
		}
		printf("\n");
	}
}

void mouvement(Grille grille, Piece piece){

}

void Echec(Grille grille){

}

int main(){
	Grille grille = initialisation();
	affichage(grille);
}