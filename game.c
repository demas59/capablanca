#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

void ajoutCoord(Coord * coords,Coord coord){

}

void mouvTour(Grille grille,Piece piece,Coord * coords){
	int x = piece -> coord -> x;
	int y = piece -> coord -> y;
	int equipe = piece -> color;
	Piece * plateau = grille -> pions;

	for(;x<8;x++){
		if(!(piece->coord->x == x && piece->coord->y == y)){
			if((*(plateau+(x*10+y))) -> color != equipe){
					printf("deplacement possible: %d,%d\n",x,y);
			}
			break;
		}
	}

	for(;x>0;x--){
		printf("type: %c\n",(*(plateau+(x*10+y))) -> type   );
		printf("color: %d\n",(*(plateau+(x*10+y))) -> color );
		if(!(piece->coord->x == x && piece->coord->y == y)){
			if((*(plateau+(x*10+y))) -> color != equipe){
					printf("deplacement possible: %d,%d\n",x,y);
			}
			break;
		}
	}

	for(;y<10;y++){
		if(!(piece->coord->x == x && piece->coord->y == y)){
			if((*(plateau+(x*10+y))) -> color != equipe){
					printf("deplacement possible: %d,%d\n",x,y);
			}
			break;
		}
	}

	for(;y>0;y--){
		if(!(piece->coord->x == x && piece->coord->y == y)){
			if((*(plateau+(x*10+y))) -> color != equipe){
					printf("deplacement possible: %d,%d\n",x,y);
			}
			break;
		}
	}

}

Coord * proposerDeplacer(Grille grille,Piece piece){

	Coord * deplacement = malloc(sizeof(Coord) * 20);

	switch(piece -> type){
		case 't': mouvTour(grille,piece,deplacement);
		break;
	}

	return deplacement;
}