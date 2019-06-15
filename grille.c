#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "piece.h"
#include "grille.h"

Grille createGrille()
{
	Grille g=(Grille)malloc(sizeof(struct grille_));
	g->pions=malloc(sizeof(struct piece_)*80);
	g->mort=malloc(sizeof(struct piece_)*10*4);
	g->nbMort = 0;
	return g;
}

void setColor(int i,int j,Piece * pieces){
	/*if(i==0 && (j==0 || j==9 || j==4 || j==5))
	{
		pieces[getIndice(i,j)]->color=1;
	}else if(i==7 && (j==0 || j==9 || j==4 || j==5))
	{
		pieces[getIndice(i,j)]->color=2;
	}else
	{
		pieces[getIndice(i,j)]->color=0;
	}*/
	if(pieces[getIndice(i,j)]->type!=' ')
	{
		if(i == 0 || i == 1){
			pieces[getIndice(i,j)]->color=1;
		}else if( i == 7 || i == 6){
			pieces[getIndice(i,j)]->color=2;
		}else{
			pieces[getIndice(i,j)]->color=0;
		}
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
			setType(i,j,pieces);
			setColor(i,j,pieces);
		}
	}
	Grille grille = (Grille) malloc(sizeof(struct grille_));
	grille -> pions = pieces;
	grille -> mort = malloc(sizeof(struct piece_)*10*4);
	grille -> nbMort = 0;
	grille -> tour = 1;
	return grille;
}

void deplacerPiece(Grille grille,Coord coordDepart, Coord coordFin ){
	Piece fin = grille -> pions[getIndice(coordFin  -> x,coordFin  -> y)];
	if(fin -> color != 0){
		grille -> mort[grille -> nbMort++] = fin;
	}
	Piece depart = grille -> pions[getIndice(coordDepart -> x,coordDepart -> y)];
	depart -> deplacement -> deplace ++;
	depart -> coord = coordFin;
	grille -> pions[getIndice(coordDepart -> x,coordDepart -> y)] = createPiece(0,coordDepart -> x,coordDepart -> y,' ');
	grille -> pions[getIndice(coordFin  -> x,coordFin -> y)] = depart;


	if(depart -> type == 'k' && depart -> deplacement -> deplace==1){
		if(coordDepart -> y == coordFin -> y+2)
		{
			deplacerPiece(grille, createCoord(coordDepart -> x, 0), createCoord(coordDepart -> x, coordFin -> y+1));
		}else if(coordDepart -> y == coordFin -> y-2)
		{
			deplacerPiece(grille, createCoord(coordDepart -> x, 9), createCoord(coordDepart -> x, coordFin -> y-1));
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

void freeGrille(Grille grille){
	int i;
	for(i=0;i<80;i++){
		freePiece(grille->pions[i]);
	}
	free(grille -> mort);
	free(grille);
}
