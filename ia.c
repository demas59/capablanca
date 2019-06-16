#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "struct.h"


/*
à chaque tour:
aller chercher toutes mes pieces et recupérer les mouvements possibles. (pour que ce soit stocké d'une manière qui mette moins longtemps à récup)

pour chacun des mouvements de mes pions, attribuer une note, stocker dans un tableau les notes associées aux mouvements

points:
pion: 1
cavalier: 3
fou: 3
tour: 5
imperatrice: 7
princesse: 7
dame: 9
roi: 10

si possible de tuer piece: pts += piece adversaire -> value
si la nouvelle position de la pièce la rend vulnérable au prochain tour: pts -= piece jouée -> value
si roi vulnérable en faisant le coup: pts -= 100

Pour chaque mouv: avant mouv calcul de la plus grosse piece alliée vulnérable, même chose une fois mouvement effectué
pts += piece avant - piece apres

si mouv fait rien en particulier: 0

*/


void ajout_move(Move * moves, int * nbr_elements, int * taille_max, Move m);
int get_importance_piece(Piece p);
Move create_move(int ia, int ib, int value_piece, int points);
int calc_max_victim(Grille grille, int joueur_actu);


int IA_jouer(Grille grille)
{
	// printf("AI thinking...\n");

	int taille_max=200;
	Move * moves=(Move *)malloc(sizeof(struct Move_)*taille_max);
	int nbMoves=0;

	int joueur_actu=grille->tour % 2 + 1;
	int max_victime=calc_max_victim(grille, joueur_actu);
	// printf("max en danger: %d\n", max_victime);

	int i;
	int tmp_max_victim=0;
	for(i=0; i<80; i++)
	{
		if(grille->pions[i]->color==joueur_actu)
		{
			calc_moves(grille, i, joueur_actu, moves, &nbMoves, &taille_max);
		}
	}



	Grille grille_tmp=copyGrille(grille);
	Piece p;
	for(i=0; i<nbMoves; i++)
	{

		p=grille_tmp->pions[moves[i]->indiceB];
		deplacerPiece(grille_tmp, coord_from_indice(moves[i]->indiceA), coord_from_indice(moves[i]->indiceB));
		clearDeplacement(grille_tmp);
		setDeplacement(grille_tmp);
		tmp_max_victim=calc_max_victim(grille_tmp, joueur_actu);




		deplacerPiece(grille_tmp, coord_from_indice(moves[i]->indiceB), coord_from_indice(moves[i]->indiceA));
		grille_tmp->pions[moves[i]->indiceB]=p;

		if(tmp_max_victim==10)
		{
			moves[i]->points = -100;
		}else
		{
			moves[i]->points += max_victime - tmp_max_victim;
		}

	}
	freeGrille(grille_tmp);



 	Move move_elu=NULL;

	int noteActu=-50;
	for(i=0; i<nbMoves; i++)
	{
		if(moves[i]->points > noteActu && moves[i]->points>-50)
		{
			noteActu=moves[i]->points;
			move_elu=moves[i];
		}else if(moves[i]->points==noteActu)
		{
			int	d= (int)rand()/(RAND_MAX+1.0)*2;
			if(d)
			{
				move_elu=moves[i];
			}
		}
	}

	if(move_elu==NULL)
	{
		return 1;
	}
	deplacerPiece(grille, coord_from_indice(move_elu->indiceA), coord_from_indice(move_elu->indiceB));
	free(moves);
	return 0;
}

/*
renvoie un objet coordonnee avec x et y a partir de l'indice de la case dans grille
*/
Coord coord_from_indice(int indice)
{
	int x=(int)indice/10;
	int y=indice%10;
	return createCoord(x, y);
}


/*
Calcule la valeur de a plus grosse piece que le joueur actuel peut se faire tuer avec cette grille
*/
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

				//printf("indicea: %d, indiceB: %d\n", i, indice);

				if(grille->pions[indice]->color==joueur_actu && get_importance_piece(grille->pions[indice])>max)
				{
					max=get_importance_piece(grille->pions[indice]);
				}
			}
		}
	}
	return max;
}

/*
calcul et stocke dans un tableau de Move tous les mouvements possible en les initialisant
*/
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
			pts=0;
		}
		if(value_piece==10 && (ia==ib-2 || ia==ib+2))
		{

		}else
		{
			ajout_move(moves, nbMoves, taille_max, create_move(ia, ib, value_piece, pts));
		}
	}
}

/*
constructeur de Move
*/
Move create_move(int ia, int ib, int value_piece, int points)
{
	Move m = (Move)malloc(sizeof(struct Move_));
	m->indiceA=ia;
	m->indiceB=ib;
	m->value_piece=value_piece;
	m->points=points;
	return m;
}


/*
renvoie la valeur d'une piece suivant le modèle décrit en haut de la page
*/
int get_importance_piece(Piece p)
{
	char c=p -> type;
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
	Move * tmp;
	if(*nbr_elements+2==*taille_max && *nbr_elements!=0)
	{
		*taille_max=(*taille_max)+200;

		size_t size = (*taille_max) * sizeof(struct Move_);

		tmp=(Move *)realloc(moves, size);

		if (tmp == NULL){
			printf("Error memory ia.c\n");
		}
		else {
			moves =tmp;
		}
	}
	moves[*nbr_elements]=m;
	(*nbr_elements)++;
}

/*
permet avec mypause de faire une fonction que attend une action de l'user pour continuer le programme
*/
void myflush ( FILE *in )
{
  int ch;

  do
    ch = fgetc ( in );
  while ( ch != EOF && ch != '\n' );

  clearerr ( in );
}

void mypause ( void )
{
  printf ( "Press [Enter] to continue . . ." );
  fflush ( stdout );
  getchar();
}
