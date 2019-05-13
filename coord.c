#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

Coord createCoord(int x, int y)
{
	Coord c=(Coord)malloc(sizeof(struct coord_));
	c->x=x;
	c->y=y;
	return c;
}
