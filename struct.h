#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct coord_ {
	int x;
	int y;
} * Coord;

typedef struct piece_ {
	int color;
	Coord coord;
	int actif;
	int type;
} * Piece;

typedef struct grille_ {
	Piece pions[10][8];
	Piece mort[40];
} * Grille;

