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

/*Trouve le roi de l'équipe selectionnée*/
Piece trouverRoi(Grille grille,int equipe){

	int i,j;
	for(i = 0 ; i < 8 ; i++){
		for(j = 0 ; j < 10 ; j++){
			if(grille -> pions[getIndice(i,j)] -> color == equipe && grille -> pions[getIndice(i,j)] -> type == 'k'){
				return grille -> pions[getIndice(i,j)];
			}
		}
	}

	return NULL;
}

int roiPeutEtrePris(Piece piece,Coord coordArrive,Grille grille,int equipe){
	Grille copy = copyGrille(grille);
	Piece roi = trouverRoi(copy,equipe);
	printf("coord piece: %d,%d\n",piece->coord->x,piece->coord->y);
	printf("coord arrivee: %d,%d\n",coordArrive->x,coordArrive->y);
	printf("case cible: %c\n",copy->pions[getIndice(coordArrive->x,coordArrive->y)]->type);
	clearDeplacement(copy);
	deplacerPiece(copy,piece -> coord,coordArrive);
	setDeplacement(copy);
	printf("deplacement fait\n");
	if(echec(roi->coord,copy,equipe%2+1)){
		free(copy);
		return 1;
	}
	free(copy);
	return 0;
}

int echecMat(Grille grille, int equipe){
	Piece roi = trouverRoi(grille,equipe%2+1);
	int k;

	int value = echec(roi -> coord,grille,equipe);
	if( value == 0){
		return 0;
	}

	for(k=0 ; k < roi -> deplacement -> nombre_element ; k++){
		Grille copy = copyGrille(grille);
		deplacerPiece(copy,roi -> coord, roi -> deplacement -> mouvements[k]);
		value = echec(roi -> deplacement -> mouvements[k],copy,equipe);
		if(value == 0){
			return 0;
		}
	}

	return 1;
}

int echec(Coord coord,Grille grille,int equipe){
	int i,j;
	for(i = 0 ; i < 8 ; i++){
		for(j = 0 ; j < 10 ; j++){
			Piece pion = grille -> pions[getIndice(i,j)];
			if(pion -> color == equipe){
				int k;
				for(k = 0; k < pion -> deplacement -> nombre_element; k++){
					Coord coordPossible = pion -> deplacement -> mouvements[k];
					if(coordPossible -> x == coord -> x && coordPossible -> y == coord -> y){
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
