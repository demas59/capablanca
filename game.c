#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

void parcoursCoord(Coord * coords,int nombre_element){
	int i;
	printf("Deplacement possibles:\n");
	for(i = 0; i<nombre_element; i++){
		Coord coord = *(coords + i);
		printf("coord: %c%d\n",'a'+coord->y,coord->x + 1 );
	}
}


void proposerDeplacer(Grille grille,Piece piece){

	switch(piece -> type){
		case 't': mouvTour(grille,piece);
		break;
		case 'p': mouvPion(grille,piece);
		break;
		case 'c': mouvCavalier(grille,piece);
		break;
		case 'f': mouvFou(grille,piece);
		break;
		case 'q': mouvTour(grille,piece);
					mouvFou(grille,piece);		
		break;
		case 'x': mouvFou(grille,piece);
					mouvCavalier(grille,piece);		
		break;
		case 'i': mouvTour(grille,piece);
					mouvCavalier(grille,piece);		
		break;
		case 'k': mouvRoi(grille,piece);	
		break;
	}
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

Piece trouverRoi(Grille grille){
	int equipe = grille -> tour % 2 + 1;
	int adversaire;

	if(equipe == 1){
		adversaire = 2;
	}else{
		adversaire = 1;
	}

	int i,j;
	for(i = 0 ; i < 8 ; i++){
		for(j = 0 ; j < 10 ; j++){
			if(grille -> pions[getIndice(i,j)] -> color == adversaire && grille -> pions[getIndice(i,j)] -> type == 'k'){
				return grille -> pions[getIndice(i,j)];
			}
		}
	}

	return NULL;
}




int echec(Grille grille){
	int equipe = grille -> tour % 2 + 1;
	Piece roi = trouverRoi(grille);

	int i,j;
	for(i = 0 ; i < 8 ; i++){
		for(j = 0 ; j < 10 ; j++){
			if(grille -> pions[getIndice(i,j)] -> color == equipe){
				int k;
				for(k=0 ; k<grille -> pions[getIndice(i,j)] -> deplacement -> nombre_element; k++){
					if(grille -> pions[getIndice(i,j)] -> deplacement -> mouvements[k] -> x == roi -> coord -> x
						&& grille -> pions[getIndice(i,j)] -> deplacement -> mouvements[k] -> y == roi -> coord -> y) {
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
