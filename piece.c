#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

Piece createPiece(int color, int x, int y, char type)
{
	Piece p=(Piece)malloc(sizeof(struct piece_));
	p->actif=-1;
	p->coord=createCoord(x, y);
	p->color=color;
	p->type=type;
	return p;
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
			if(plateau[getIndice(x,y)] -> color != equipe){
				Coord coord = malloc(sizeof(Coord));
				coord -> x = x;
				coord -> y = y;
				ajoutCoord(coords, coord,taille_max,nombre_element);
					if(plateau[getIndice(x,y)] -> type != ' '){
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
			if(plateau[getIndice(x,y)] -> color != equipe){
				Coord coord = malloc(sizeof(Coord));
				coord -> x = x;
				coord -> y = y;
				ajoutCoord(coords, coord,taille_max,nombre_element);
					if(plateau[getIndice(x,y)] -> type != ' '){
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
			if(plateau[getIndice(x,y)] -> color != equipe){
				Coord coord = malloc(sizeof(Coord));
				coord -> x = x;
				coord -> y = y;
				ajoutCoord(coords, coord,taille_max,nombre_element);
					if(plateau[getIndice(x,y)] -> type != ' '){
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
			if(plateau[getIndice(x,y)] -> color != equipe){
				Coord coord = malloc(sizeof(Coord));
				coord -> x = x;
				coord -> y = y;
				ajoutCoord(coords, coord,taille_max,nombre_element);
					if(plateau[getIndice(x,y)] -> type != ' '){
						break;
					}
			}else{
				break;
			}
		}
	}
}

void mouvPion(Grille grille,Piece piece,Coord * coords, int * taille_max, int * nombre_element){
	int x;
	int y;
	int equipe = piece -> color;
	Piece * plateau = grille -> pions;

	x = piece -> coord -> x;
	y = piece -> coord -> y;

	int porte = 0;

	if(equipe == 1){

		if(piece -> deplace == 0){
			porte = x+3;
		}else{
			porte = x+2;
		}

		for(++x;x<porte;x++){
			if(plateau[getIndice(x,y)] -> color == 0){
				Coord coord = malloc(sizeof(Coord));
				coord -> x = x;
				coord -> y = y;
				ajoutCoord(coords, coord,taille_max,nombre_element);
			}else{
				break;
			}
		}

		x = piece -> coord -> x;
		y = piece -> coord -> y;
		if((y>0) && (plateau[getIndice(x+1,y-1)] -> color != equipe) && (plateau[getIndice(x+1,y-1)] -> color != 0)){
			Coord coord = malloc(sizeof(Coord));
				coord -> x = x+1;
				coord -> y = y-1;
				ajoutCoord(coords, coord,taille_max,nombre_element);
		}

		x = piece -> coord -> x;
		y = piece -> coord -> y;
		if((y<9) && (plateau[getIndice(x+1,y+1)] -> color != equipe) && (plateau[getIndice(x+1,y+1)] -> color != 0)){
			Coord coord = malloc(sizeof(Coord));
				coord -> x = x+1;
				coord -> y = y+1;
				ajoutCoord(coords, coord,taille_max,nombre_element);
		}
	}else{

		if(piece -> deplace == 0){
			porte = x-3;
		}else{
			porte = x-2;
		}

		for(--x;x>porte;x--){
			if(plateau[getIndice(x,y)] -> color == 0){
				Coord coord = malloc(sizeof(Coord));
				coord -> x = x;
				coord -> y = y;
				ajoutCoord(coords, coord,taille_max,nombre_element);
			}else{
				break;
			}
		}

		x = piece -> coord -> x;
		y = piece -> coord -> y;
		if((y>0) && (plateau[getIndice(x-1,y-1)] -> color != equipe) && (plateau[getIndice(x-1,y-1)] -> color != 0)){
			Coord coord = malloc(sizeof(Coord));
				coord -> x = x-1;
				coord -> y = y-1;
				ajoutCoord(coords, coord,taille_max,nombre_element);
		}

		x = piece -> coord -> x;
		y = piece -> coord -> y;
		if((y<9) && (plateau[getIndice(x-1,y+1)] -> color != equipe) && (plateau[getIndice(x-1,y+1)] -> color != 0)){
			Coord coord = malloc(sizeof(Coord));
				coord -> x = x-1;
				coord -> y = y+1;
				ajoutCoord(coords, coord,taille_max,nombre_element);
		}
	}
}

void mouvCavalier(Grille grille,Piece piece,Coord * coords, int * taille_max, int * nombre_element){
	int x = piece -> coord -> x;
	int y = piece -> coord -> y;
	int equipe = piece -> color;
	Piece * plateau = grille -> pions;

	if(x > 1){
		if(y>0){
			if(plateau[getIndice(x-2,y-1)] -> color != equipe){
				x = piece -> coord -> x;
				y = piece -> coord -> y;

				Coord coord = malloc(sizeof(Coord));
				coord -> x = x - 2;
				coord -> y = y - 1;
				ajoutCoord(coords, coord,taille_max,nombre_element);
			}
		}
		if(y<9){
			if(plateau[getIndice(x-2,y+1)] -> color != equipe){
				x = piece -> coord -> x;
				y = piece -> coord -> y;

				Coord coord = malloc(sizeof(Coord));
				coord -> x = x - 2;
				coord -> y = y + 1;
				ajoutCoord(coords, coord,taille_max,nombre_element);
			}
		}
	}

	if(x < 6){
		if(y>0){
			if(plateau[getIndice(x+2,y-1)] -> color != equipe){
				x = piece -> coord -> x;
				y = piece -> coord -> y;

				Coord coord = malloc(sizeof(Coord));
				coord -> x = x + 2;
				coord -> y = y - 1;
				ajoutCoord(coords, coord,taille_max,nombre_element);
			}
		}
		if(y<9){
			if(plateau[getIndice(x+2,y+1)] -> color != equipe){
				x = piece -> coord -> x;
				y = piece -> coord -> y;

				Coord coord = malloc(sizeof(Coord));
				coord -> x = x + 2;
				coord -> y = y + 1;
				ajoutCoord(coords, coord,taille_max,nombre_element);
			}
		}
	}

	if(y > 1){
		if(x>0){
			if(plateau[getIndice(x-1,y-2)] -> color != equipe){
				x = piece -> coord -> x;
				y = piece -> coord -> y;

				Coord coord = malloc(sizeof(Coord));
				coord -> x = x - 1;
				coord -> y = y - 2;
				ajoutCoord(coords, coord,taille_max,nombre_element);
			}
		}
		if(x<7){
			if(plateau[getIndice(x+1,y-2)] -> color != equipe){
				x = piece -> coord -> x;
				y = piece -> coord -> y;

				Coord coord = malloc(sizeof(Coord));
				coord -> x = x + 1;
				coord -> y = y -2;
				ajoutCoord(coords, coord,taille_max,nombre_element);
			}
		}
	}

	if(y < 9){
		if(x>0){
			if(plateau[getIndice(x-1,y+2)] -> color != equipe){
				x = piece -> coord -> x;
				y = piece -> coord -> y;

				Coord coord = malloc(sizeof(Coord));
				coord -> x = x - 1;
				coord -> y = y + 2;
				ajoutCoord(coords, coord,taille_max,nombre_element);
			}
		}
		if(x<7){
			if(plateau[getIndice(x+1,y+2)] -> color != equipe){
				x = piece -> coord -> x;
				y = piece -> coord -> y;

				Coord coord = malloc(sizeof(Coord));
				coord -> x = x + 1;
				coord -> y = y + 2;
				ajoutCoord(coords, coord,taille_max,nombre_element);
			}
		}
	}
}


void mouvFou(Grille grille,Piece piece,Coord * coords, int * taille_max, int * nombre_element){
	int x = piece -> coord -> x;
	int y = piece -> coord -> y;
	int equipe = piece -> color;
	int adversaire;

	if(equipe == 1){
		adversaire = 2;
	}else{
		adversaire = 1;
	}

	Piece * plateau = grille -> pions;
	while((x != 7) && (y != 9) && (plateau[getIndice(x+1,y+1)]->color != equipe)){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x + 1;
		coord -> y = y + 1;
		ajoutCoord(coords, coord,taille_max,nombre_element);
		if(plateau[getIndice(x,y)]->color == adversaire){
			break;
		}
		x++;
		y++;
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	while((x != 0) && (y != 9) && (plateau[getIndice(x-1,y+1)]->color != equipe)){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x - 1;
		coord -> y = y + 1;
		ajoutCoord(coords, coord,taille_max,nombre_element);
		if(plateau[getIndice(x,y)]->color == adversaire){
			break;
		}
		x--;
		y++;
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	while((x != 0) && (y != 0) && (plateau[getIndice(x-1,y-1)]->color != equipe)){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x - 1;
		coord -> y = y - 1;
		ajoutCoord(coords, coord,taille_max,nombre_element);
		if(plateau[getIndice(x,y)]->color == adversaire){
			break;
		}
		x--;
		y--;
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	while((x != 7) && (y != 0) && (plateau[getIndice(x+1,y-1)]->color != equipe)){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x + 1;
		coord -> y = y - 1;
		ajoutCoord(coords, coord,taille_max,nombre_element);
		if(plateau[getIndice(x,y)]->color == adversaire){
			break;
		}
		x++;
		y--;
	}
}

void mouvRoi(Grille grille,Piece piece,Coord * coords, int * taille_max, int * nombre_element){
	int x = piece -> coord -> x;
	int y = piece -> coord -> y;
	int equipe = piece -> color;
	Piece * plateau = grille -> pions;

	if(x != 0 && plateau[getIndice(x-1,y)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x - 1;
		coord -> y = y;
		ajoutCoord(coords, coord,taille_max,nombre_element);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(x != 7 && plateau[getIndice(x+1,y)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x + 1;
		coord -> y = y;
		ajoutCoord(coords, coord,taille_max,nombre_element);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(y != 0 && plateau[getIndice(x,y-1)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x;
		coord -> y = y - 1;
		ajoutCoord(coords, coord,taille_max,nombre_element);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(y != 9 && plateau[getIndice(x,y+1)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x;
		coord -> y = y + 1;
		ajoutCoord(coords, coord,taille_max,nombre_element);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(y != 0 && x != 0 && plateau[getIndice(x-1,y-1)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x - 1;
		coord -> y = y - 1;
		ajoutCoord(coords, coord,taille_max,nombre_element);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(y != 0 && x != 7 && plateau[getIndice(x+1,y-1)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x + 1;
		coord -> y = y - 1;
		ajoutCoord(coords, coord,taille_max,nombre_element);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(y != 9 && x != 0 && plateau[getIndice(x-1,y+1)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x - 1;
		coord -> y = y + 1;
		ajoutCoord(coords, coord,taille_max,nombre_element);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(y != 9 && x != 7 && plateau[getIndice(x+1,y+1)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x + 1;
		coord -> y = y + 1;
		ajoutCoord(coords, coord,taille_max,nombre_element);
	}
}

void placerPiece(Grille grille,Piece piece){
	grille -> pions[getIndice(piece -> coord -> x,piece-> coord -> y)] = piece;
}

