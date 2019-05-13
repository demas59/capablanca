#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"


void setColor(int i,int j,Piece * pieces){
	if(i == 0 || i == 1){
				(*(pieces+(i*10+j)))->color=0;
			}else{
				if(i == 6 || i == 7){
					(*(pieces+(i*10+j)))->color=1;
				}else{
					(*(pieces+(i*10+j)))->color=-1;
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
			setColor(i,j,pieces);
			setType(i,j,pieces);
		}
	}
	Grille grille = (Grille) malloc(sizeof(struct grille_));
	grille -> pions = pieces;
	return grille;
}


/*Affiche la grille de jeu*/
void affichage(Grille grille){
	system ("clear");
	printf("\n\t|-1---2---3---4---5---6---7---8---9--10-|\n\t");
	printf("|---------------------------------------|\n\t");
	int i,j;
	Piece * plateau = grille -> pions;
	for(i=0;i<8;i++){
		for(j=0;j<10;j++){
			printf("| %c ",(*(plateau+(i*10+j)))->type);
			if(j == 9){
				printf("|%d\n\t|---------------------------------------|\n\t", i);
			}
		}
	}
	printf("|-1---2---3---4---5---6---7---8---9--10-|\n\t");
}

void mouvement(Grille grille, Piece piece){

}

void Echec(Grille grille){

}

int main(void){
	Grille grille = initialisation();
	affichage(grille);
}