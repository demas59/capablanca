#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

// Fonction qui créer une piece
Piece createPiece(int color, int x, int y, char type)
{
	Piece p=(Piece)malloc(sizeof(struct piece_));
	p->coord=createCoord(x, y);
	p->color=color;
	p->type=type;
	p->deplacement = createDeplacement();
	p->select = 0;
	return p;	// Renvoi la pièce créer
}

// Fonction qui gère le déplacement de la tour
/*
	Tant que les mouvements disponibles de la tour ne sont pas occultés par une piece,
	La tour peut se déplacer librement à l'horizontal et à la vertical
*/
void mouvTour(Grille grille,Piece piece){
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
				ajoutCoord(coord,piece);
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
				ajoutCoord(coord,piece);
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
				ajoutCoord(coord,piece);
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
				ajoutCoord(coord,piece);
					if(plateau[getIndice(x,y)] -> type != ' '){
						break;
					}
			}else{
				break;
			}
		}
	}
}


// Fonction qui gère le déplacement du pion
/*
	Tant que les mouvements disponibles de la tour ne sont pas occultés par une piece,
	Le pion peut se déplacer librement d'une case en avant, ou de 2 si il s'agit de son premier
*/
void mouvPion(Grille grille,Piece piece){
	int x;
	int y;
	int equipe = piece -> color;
	Piece * plateau = grille -> pions;

	x = piece -> coord -> x;
	y = piece -> coord -> y;

	int porte = 0;

	if(equipe == 1){

		if(piece -> deplacement -> deplace == 0){
			porte = 2;
		}else if(x<7){
			porte = 1;
		}

		int i;
		for(i=1; i <= porte; i++){
			if(plateau[getIndice(x+i,y)] -> color == 0){
				Coord coord = malloc(sizeof(Coord));
				coord -> x = x+i;
				coord -> y = y;
				ajoutCoord(coord,piece);
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
				ajoutCoord(coord,piece);
		}

		x = piece -> coord -> x;
		y = piece -> coord -> y;
		if((y<9) && (plateau[getIndice(x+1,y+1)] -> color != equipe) && (plateau[getIndice(x+1,y+1)] -> color != 0)){
			Coord coord = malloc(sizeof(Coord));
				coord -> x = x+1;
				coord -> y = y+1;
				ajoutCoord(coord,piece);
		}
	}else{

		if(piece -> deplacement -> deplace == 0){
			porte = 2;
		}else if(x>0){
			porte = 1;
		}

		int i;
		for(i=1; i <= porte; i++){
			if(plateau[getIndice(x-i,y)] -> color == 0){
				Coord coord = malloc(sizeof(Coord));
				coord -> x = x-i;
				coord -> y = y;
				ajoutCoord(coord,piece);
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
				ajoutCoord(coord,piece);
		}

		x = piece -> coord -> x;
		y = piece -> coord -> y;
		if((y<9) && (plateau[getIndice(x-1,y+1)] -> color != equipe) && (plateau[getIndice(x-1,y+1)] -> color != 0)){
			Coord coord = malloc(sizeof(Coord));
				coord -> x = x-1;
				coord -> y = y+1;
				ajoutCoord(coord,piece);
		}
	}
}


// Fonction qui gère le déplacement de la tour
/*
	Tant que les mouvements disponibles de la tour ne sont pas occultés par une piece,
	Le cavalier peut se déplacer en "L"
*/
void mouvCavalier(Grille grille,Piece piece){
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
				ajoutCoord(coord,piece);
			}
		}
		if(y<9){
			if(plateau[getIndice(x-2,y+1)] -> color != equipe){
				x = piece -> coord -> x;
				y = piece -> coord -> y;

				Coord coord = malloc(sizeof(Coord));
				coord -> x = x - 2;
				coord -> y = y + 1;
				ajoutCoord(coord,piece);
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
				ajoutCoord(coord,piece);
			}
		}
		if(y<9){
			if(plateau[getIndice(x+2,y+1)] -> color != equipe){
				x = piece -> coord -> x;
				y = piece -> coord -> y;

				Coord coord = malloc(sizeof(Coord));
				coord -> x = x + 2;
				coord -> y = y + 1;
				ajoutCoord(coord,piece);
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
				ajoutCoord(coord,piece);
			}
		}
		if(x<7){
			if(plateau[getIndice(x+1,y-2)] -> color != equipe){
				x = piece -> coord -> x;
				y = piece -> coord -> y;

				Coord coord = malloc(sizeof(Coord));
				coord -> x = x + 1;
				coord -> y = y -2;
				ajoutCoord(coord,piece);
			}
		}
	}

	if(y < 8){
		if(x>0){
			if(plateau[getIndice(x-1,y+2)] -> color != equipe){
				x = piece -> coord -> x;
				y = piece -> coord -> y;

				Coord coord = malloc(sizeof(Coord));
				coord -> x = x - 1;
				coord -> y = y + 2;
				ajoutCoord(coord,piece);
			}
		}
		if(x<7){
			if(plateau[getIndice(x+1,y+2)] -> color != equipe){
				x = piece -> coord -> x;
				y = piece -> coord -> y;

				Coord coord = malloc(sizeof(Coord));
				coord -> x = x + 1;
				coord -> y = y + 2;
				ajoutCoord(coord,piece);
			}
		}
	}
}

// Fonction qui gère le déplacement de la tour
/*
	Tant que les mouvements disponibles de la tour ne sont pas occultés par une piece,
	Le fou peut se déplacement librement en diagonal
*/
void mouvFou(Grille grille,Piece piece){
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
		ajoutCoord(coord,piece);
		if(plateau[getIndice(x+1,y+1)]->color == adversaire){
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
		ajoutCoord(coord,piece);
		if(plateau[getIndice(x-1,y+1)]->color == adversaire){
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
		ajoutCoord(coord,piece);
		if(plateau[getIndice(x-1,y-1)]->color == adversaire){
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
		ajoutCoord(coord,piece);
		if(plateau[getIndice(x+1,y-1)]->color == adversaire){
			break;
		}
		x++;
		y--;
	}
}

// Fonction qui gère le déplacement de la tour
/*
	Tant que les mouvements disponibles de la tour ne sont pas occultés par une piece,
	Le roi peut se déplacer d'une case unique, partout
*/
void mouvRoi(Grille grille,Piece piece){
	int x = piece -> coord -> x;
	int y = piece -> coord -> y;
	int equipe = piece -> color;
	Piece * plateau = grille -> pions;


	if(x != 0 && plateau[getIndice(x-1,y)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x - 1;
		coord -> y = y;
		ajoutCoord(coord,piece);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(x != 7 && plateau[getIndice(x+1,y)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x + 1;
		coord -> y = y;
		ajoutCoord(coord,piece);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(y != 0 && plateau[getIndice(x,y-1)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x;
		coord -> y = y - 1;
		ajoutCoord(coord,piece);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(y != 9 && plateau[getIndice(x,y+1)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x;
		coord -> y = y + 1;
		ajoutCoord(coord,piece);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(y != 0 && x != 0 && plateau[getIndice(x-1,y-1)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x - 1;
		coord -> y = y - 1;
		ajoutCoord(coord,piece);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(y != 0 && x != 7 && plateau[getIndice(x+1,y-1)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x + 1;
		coord -> y = y - 1;
		ajoutCoord(coord,piece);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(y != 9 && x != 0 && plateau[getIndice(x-1,y+1)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x - 1;
		coord -> y = y + 1;
		ajoutCoord(coord,piece);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(y != 9 && x != 7 && plateau[getIndice(x+1,y+1)]->color != equipe){
		Coord coord = malloc(sizeof(Coord));
		coord -> x = x + 1;
		coord -> y = y + 1;
		ajoutCoord(coord,piece);
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(piece -> deplacement -> deplace==0){
		int i=1;
		while((y+i) < 10 && grille->pions[getIndice(x,y+i)]->color==0)
		{
			i++;
		}

		if(y+i<10 && grille->pions[getIndice(x,y+i)]->type=='t' && grille->pions[getIndice(x,y+i)]->deplacement->deplace==0)
		{
			Coord coord = malloc(sizeof(Coord));
			coord -> x = x;
			coord -> y = y + 2;
			ajoutCoord(coord,piece);
		}
	}

	x = piece -> coord -> x;
	y = piece -> coord -> y;
	if(piece -> deplacement -> deplace==0){
		int i=-1;
		while((y+i) >= 0 && grille->pions[getIndice(x,y+i)]->color==0)
		{
			i--;
		}

		if(y+i>=0 && grille->pions[getIndice(x,y+i)]->type=='t' && grille->pions[getIndice(x,y+i)]->deplacement->deplace==0)
		{
			Coord coord = malloc(sizeof(Coord));
			coord -> x = x;
			coord -> y = y - 2;
			ajoutCoord(coord,piece);
		}
	}

}

// Permet de placer une pièce sur une grille
void placerPiece(Grille grille,Piece piece){
	grille -> pions[getIndice(piece -> coord -> x,piece-> coord -> y)] = piece;
}


// Copie une pièce
Piece copyPiece(Piece origine){
	Piece copy = createPiece(origine -> color,origine -> coord -> x,origine -> coord -> y, origine -> type);
	copy -> deplacement = copyDeplacement(origine -> deplacement);
	return copy;
}

// Permet de libérer une piece, en mémoire
void freePiece(Piece piece){
	freeDeplacement(piece->deplacement);
	free(piece -> coord);
	free(piece);
}
