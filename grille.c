#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

Grille createGrille()
{
	Grille g=(Grille)malloc(sizeof(struct grille_));
	g->pions=malloc(sizeof(struct piece_)*80);
	g->mort=malloc(sizeof(struct piece_)*10*4);
	return g;
}

void setColor(int i,int j,Piece * pieces){
	if(i == 0 || i == 1){

		pieces[getIndice(i,j)]->color=1;

	}else if( i == 7 || i == 6){

		pieces[getIndice(i,j)]->color=2;

	}else{

		pieces[getIndice(i,j)]->color=0;

	}
}

void setType(int i,int j, Piece * pieces){
	if((j == 0 || j == 9) && (i == 0 || i == 7)){
		pieces[getIndice(i,j)] -> type = 't';
	}
	if((j == 1 || j == 8) && (i == 0 || i == 7)){
		pieces[getIndice(i,j)] -> type = 'c';
	}
	if((j == 2) && (i == 0 || i == 7)){
		pieces[getIndice(i,j)] -> type = 'x';
	}
	if((j == 3 || j == 6) && (i == 0 || i == 7)){
		pieces[getIndice(i,j)] -> type = 'f';
	}
	if((j == 4) && (i == 0 || i == 7)){
		pieces[getIndice(i,j)] -> type = 'q';
	}
	if((j == 5) && (i == 0 || i == 7)){
		pieces[getIndice(i,j)] -> type = 'k';
	}
	if((j == 7) && (i == 0 || i == 7)){
		pieces[getIndice(i,j)] -> type = 'i';
	}
	if(i == 1 || i == 6){
		pieces[getIndice(i,j)] -> type = 'p';
	}
}


/*Créé la grille et place toutes les pièces*/
Grille initialisation(){
	Piece * pieces = malloc(sizeof(struct piece_)*10*8);
	int i,j;

	for(i=0;i<8;i++){
		for(j=0;j<10;j++){
			pieces[getIndice(i,j)] = createPiece(0,i,j,' ');
			setColor(i,j,pieces);
			setType(i,j,pieces);
		}
	}
	Grille grille = (Grille) malloc(sizeof(struct grille_));
	grille -> pions = pieces;
	grille -> mort = malloc(sizeof(struct piece_)*10*4);
	grille -> nbMort = 0;
	grille -> tour = 1;
	return grille;
}


/*Affiche la grille de jeu*/
void affichage(Grille grille){
	// system("clear");
	printf("\n\t|-a---b---c---d---e---f---g---h---i---j-|\n\t");
	printf("|---------------------------------------|\n\t");
	int i,j;
	Piece * plateau = grille -> pions;
	
	for(i=0;i<8;i++){
		for(j=0;j<10;j++){
			printf("|");
			if(plateau[getIndice(i,j)]->color == 1){
				//printf("\x1B[31m");
			}
			if(plateau[getIndice(i,j)]->color == 2){
				//printf("\x1B[34m");
			}
			printf(" %c ",plateau[getIndice(i,j)]->type);
			//printf("\x1B[0m");
			if(j == 9){
				printf("|%d\n\t|---------------------------------------|\n\t", i+1);
			}
		}
	}
	printf("|-a---b---c---d---e---f---g---h---i---j-|\n");
}

Coord choixCoord(Coord * coords, int nombre_element){
	parcoursCoord(coords,nombre_element);
	char * choix = malloc(sizeof(char) * 2);

	printf("Choisissez les coordonnées:\n");
	scanf("%s",choix);

	int colone=((int)choix[0]-(int)'a');
	int ligne=(int)choix[1]-(int)'1';

	int i;
	for(i=0;i<nombre_element;i++){
		if(coords[i]->x == ligne && coords[i]->y == colone){
			return coords[i];
		}
	}

	return NULL;
}

void promotion(Piece piece){
	char promo;
	printf("Choisissez en quoi promouvoir votre pion reine(q),fou(f),tour(t),cavalier(c):\n");
	scanf("%c",&promo);
	piece -> type = promo;
}

void deplacerPiece(Grille grille,Coord coordDepart, Coord coordFin ){
	Piece fin = grille -> pions[getIndice(coordFin  -> x,coordFin  -> y)];
	if(fin -> color != 0){
		grille -> mort[grille -> nbMort++] = fin;
	}
	Piece depart = grille -> pions[getIndice(coordDepart -> x,coordDepart -> y)];
	depart -> deplacement -> deplace = 1;
	depart -> coord = coordFin;

	grille -> pions[getIndice(coordDepart -> x,coordDepart -> y)] = createPiece(0,coordDepart -> x,coordDepart -> y,' ');
	grille -> pions[getIndice(coordFin  -> x,coordFin -> y)] = depart;

	if(depart -> type == 'p'){
		if(depart -> color == 1 && depart -> coord -> x == 7){
			promotion(depart);
		}
		if(depart -> color == 2 && depart -> coord -> x == 0){
			promotion(depart);
		}
	}
}

Grille copyGrille(Grille origine){
	Grille copy = createGrille();
	int i;
	for(i = 0; i< 80;i++){
		copy -> pions[i] = copyPiece(origine -> pions[i]);
	}
	return copy;
}