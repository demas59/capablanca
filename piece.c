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
