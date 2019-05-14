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

void setColor(int i,int j,Piece * pieces){
	if(i == 0 || i == 1){
				(*(pieces+(i*10+j)))->color=1;
			}else{
				if(i == 6 || i == 7){
					(*(pieces+(i*10+j)))->color=2;
				}else{
					(*(pieces+(i*10+j)))->color=0;
				}
	}
}

void setType(int i,int j, Piece * pieces){
	if((j == 0 || j == 9) && (i == 0 || i == 7)){
		(*(pieces+(i*10+j))) -> type = 't';
	}
	if((j == 1 || j == 8) && (i == 0 || i == 7)){
		(*(pieces+(i*10+j))) -> type = 'c';
	}
	if((j == 2) && (i == 0 || i == 7)){
		(*(pieces+(i*10+j))) -> type = 'x';
	}
	if((j == 3 || j == 6) && (i == 0 || i == 7)){
		(*(pieces+(i*10+j))) -> type = 'f';
	}
	if((j == 4) && (i == 0 || i == 7)){
		(*(pieces+(i*10+j))) -> type = 'q';
	}
	if((j == 5) && (i == 0 || i == 7)){
		(*(pieces+(i*10+j))) -> type = 'k';
	}
	if((j == 7) && (i == 0 || i == 7)){
		(*(pieces+(i*10+j))) -> type = 'i';
	}
	if(i == 1 || i == 6){
		(*(pieces+(i*10+j))) -> type = 'p';
	}
}


/*Créé la grille et place toutes les pièces*/
Grille initialisation(){
	Piece * pieces = malloc(sizeof(struct piece_)*10*8);
	int i,j;

	for(i=0;i<8;i++){
		for(j=0;j<10;j++){
			(*(pieces+(i*10+j))) = createPiece(0,i,j,' ');
			setColor(i,j,pieces);
			setType(i,j,pieces);
		}
	}
	Grille grille = (Grille) malloc(sizeof(struct grille_));
	grille -> pions = pieces;
	grille -> mort = malloc(sizeof(struct piece_)*10*8);
	grille -> tour = 1;
	return grille;
}


/*Affiche la grille de jeu*/
void affichage(Grille grille){
	system ("clear");
	printf("\n\t|-a---b---c---d---e---f---g---h---i---j-|\n\t");
	printf("|---------------------------------------|\n\t");
	int i,j;
	Piece * plateau = grille -> pions;
	for(i=0;i<8;i++){
		for(j=0;j<10;j++){
			printf("| %c ",(*(plateau+(i*10+j)))->type);
			if(j == 9){
				printf("|%d\n\t|---------------------------------------|\n\t", i+1);
			}
		}
	}
	printf("|-a---b---c---d---e---f---g---h---i---j-|\n\t");
}