#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

void ajoutCoord(Coord * coords,Coord coord,int * taille_max,int * nombre_element){
	if(*nombre_element == *taille_max){
		*taille_max += 10;
		realloc(coords, sizeof(Coord) * (*taille_max));
	}
	*(coords + *nombre_element) = coord;
	(*nombre_element)++;
}

void parcoursCoord(Coord * coords,int nombre_element){
	int i;
	for(i = 0; i<nombre_element; i++){
		Coord coord = *(coords + i);
		printf("coord: %c%d\n",'a'+coord->y,coord->x + 1 );
	}
}

void mouvTour(Grille grille,Piece piece,Coord * coords, int * taille_max, int * nombre_element){
	int x;
	int y;
	int equipe = piece -> color;
	Piece * plateau = grille -> pions;

	x = piece -> coord -> x;
	y = piece -> coord -> y;

	for(;x<8;x++){
		if(!(piece->coord->x == x && piece->coord->y == y)){
			if((*(plateau+(x*10+y))) -> color != equipe){
				Coord coord = malloc(sizeof(Coord));
				coord -> x = x;
				coord -> y = y;
				ajoutCoord(coords, coord,taille_max,nombre_element);
					if((*(plateau+(x*10+y))) -> type != ' '){
						break;
					}
			}else{
				break;
			}
		}
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;

	for(;x>=0;x--){
		if(!(piece->coord->x == x && piece->coord->y == y)){
			if((*(plateau+(x*10+y))) -> color != equipe){
				Coord coord = malloc(sizeof(Coord));
				coord -> x = x;
				coord -> y = y;
				ajoutCoord(coords, coord,taille_max,nombre_element);
					if((*(plateau+(x*10+y))) -> type != ' '){
						break;
					}
			}else{
				break;
			}
		}
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;

	for(;y<10;y++){
		if(!(piece->coord->x == x && piece->coord->y == y)){
			if((*(plateau+(x*10+y))) -> color != equipe){
				Coord coord = malloc(sizeof(Coord));
				coord -> x = x;
				coord -> y = y;
				ajoutCoord(coords, coord,taille_max,nombre_element);
					if((*(plateau+(x*10+y))) -> type != ' '){
						break;
					}
			}else{
				break;
			}
		}
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;

	for(;y>=0;y--){
		if(!(piece->coord->x == x && piece->coord->y == y)){
			if((*(plateau+(x*10+y))) -> color != equipe){
				Coord coord = malloc(sizeof(Coord));
				coord -> x = x;
				coord -> y = y;
				ajoutCoord(coords, coord,taille_max,nombre_element);
					if((*(plateau+(x*10+y))) -> type != ' '){
						break;
					}
			}else{
				break;
			}
		}
	}
}

Coord * proposerDeplacer(Grille grille,Piece piece){

	int taille_max = 20;
	int nombre_element = 0;

	Coord * deplacement = malloc(sizeof(Coord) * taille_max);

	switch(piece -> type){
		case 't': mouvTour(grille,piece,deplacement,&taille_max,&nombre_element);
		break;
	}

	parcoursCoord(deplacement,nombre_element);
	return deplacement;
}


int getIndice(int i, int j)
{
	return i*10+j;
}

Coord choosePawn(Grille grille)
{
	char choix[2] = {0};
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
