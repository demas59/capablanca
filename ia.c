#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

/*
à chaque tour:
aller chercher toutes les pieces adverses et recupérer les mouvements possibles. (pour que ce soit stocké d'une manière qui mette moins longtemps à récup)
pareil pour mes pieces

pour chacun des mouvements de mes pions, attribuer une note, stocker dans un tableau les notes associées aux mvt

points:
pion: 1
cavalier: 3
fou: 3
tour: 5
imperatrice: 7
princesse: 7
dame: 9
roi: 10

si possible de tuer piece: pts += piece -> value
si new position dans mouv adversaire: pts -= piece -> value

si de base dans mouv adv: pts += piece -> value
si new position dans mouv adversaire: pts -= piece -> value

si mouv fait rien: +1

*/
typedef struct Move_ 
{
	int indiceA;
	int indiceB;
	int value_piece;
	int points;
} * Move;

void ajout_move(Move * moves, int * nbr_elements, int * taille_max, Move m);
int get_importance_piece(Piece p);
Move create_move(int ia, int ib, int value_piece, int points);
void calc_moves(Grille g, int indice, int joueur, Move * moves, int * nbMoves, int * taille_max);
int calc_max_victim(Grille grille, int joueur_actu);


int IA_jouer(Grille grille)
{
	Move * moves=(Move *)malloc(sizeof(struct Move_)*10);
	int nbMoves=0;
	int taille_max=0;

	int joueur_actu=grille->tour % 2 + 1;
	int max_victime=calc_max_victim(grille, joueur_actu);


	if(max_victime==10)//echec(grille))
	{
		printf('ECHEC!!!!!!');
		//jouerRoi
	}else
	{
		int i;
		for(i=0; i<80; i++)
		{
			if(grille->pions[i]->color==joueur_actu)
			{
				calc_moves(grille, i, joueur_actu, moves, &nbMoves, &taille_max);
			}
		}
		Grille tmp=
	}
	int i;
	for(i=0; i<nbMoves; i++)
	{
		printf("%d - %d (%d): %d\n", moves[i]->indiceA, moves[i]->indiceB, moves[i]->value_piece, moves[i]->points);
	}
	free(moves);
	return 1;
}

int calc_max_victim(Grille grille, int joueur_actu)
{
	int adversaire= joueur_actu % 2 + 1;
	int max=0;
	int i=0;
	for(i=0; i<80; i++)
	{
		if(grille->pions[i]->color==adversaire)
		{
			int cpt;
			for(cpt=0; cpt<grille->pions[i]->deplacement->nombre_element; cpt++)
			{
				int indice=getIndice(grille->pions[i]->deplacement->mouvements[cpt]->x,grille->pions[i]->deplacement->mouvements[cpt]->y);
				if(grille->pions[indice]->color==joueur_actu && get_importance_piece(grille->pions[indice])>max)
				{
					max=get_importance_piece(grille->pions[indice]);
				}
			}
		}
	}
	return max;
}

void calc_moves(Grille g, int indice, int joueur, Move * moves, int * nbMoves, int * taille_max)
{
	int cpt, ib;
	int pts=0;
	int ia=indice;
	int value_piece=get_importance_piece(g->pions[indice]);
	for(cpt=0; cpt<(g->pions[indice]->deplacement->nombre_element); cpt++)
	{
		ib=getIndice(g->pions[indice]->deplacement->mouvements[cpt]->x,g->pions[indice]->deplacement->mouvements[cpt]->y);
		if(g->pions[ib]->color != 0 && g->pions[ib]->color!=joueur)
		{
			pts=get_importance_piece(g->pions[ib]);
		}else if(g->pions[ib]->color == 0)
		{
			pts=1;
		}

		ajout_move(moves, nbMoves, taille_max, create_move(ia, ib, value_piece, pts));
	}
}

Move create_move(int ia, int ib, int value_piece, int points)
{
	Move m = (Move)malloc(sizeof(struct Move_));
	m->indiceA=ia;
	m->indiceB=ib;
	m->value_piece=value_piece;
	m->points=points;
	return m;
}

int get_importance_piece(Piece p)
{
	char c=p -> type;
	//printf("%c", c);
	switch (c)
	{
		case 'p': return 1;//pion
		case 'c': return 3;//cavalier
		case 'f': return 3;//fou
		case 't': return 5;//tour
		case 'i': return 7;//impératrice
		case 'x': return 7;//princesse
		case 'q': return 9;//reine
		case 'k': return 10;//roi
	}
	return 0;
}

void ajout_move(Move * moves, int * nbr_elements, int * taille_max, Move m)
{
	if(*nbr_elements==*taille_max && *nbr_elements!=0)
	{
		moves=(Move *)realloc(moves, (*taille_max)+10);
		*taille_max=(*taille_max)+10;
	}
	moves[*nbr_elements]=m;
	(*nbr_elements)++;
}







