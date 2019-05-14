#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"



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


	if(joueur==indice)
	{
		return createCoord(ligne, colone);
	}else
	{
		return NULL;
	}
}
