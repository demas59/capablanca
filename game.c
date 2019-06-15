#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "grille.h"
#include "deplacement.h"
#include "piece.h"
#include "game.h"


/*Trouve le roi de l'équipe selectionnée*/
Piece trouverRoi(Grille grille,int equipe){
	int i,j;
	for(i = 0 ; i < 8 ; i++){
		for(j = 0 ; j < 10 ; j++){
			if(grille -> pions[getIndice(i,j)] -> color == equipe && grille -> pions[getIndice(i,j)] -> type == 'k'){
				return grille -> pions[getIndice(i,j)];
			}
		}
	}

	return NULL;
}

/*Détermine si le roi d'une des équipe peut être pris par un adversaire*/
int roiPeutEtrePris(Piece piece,Coord coordArrive,Grille grille,int equipe){
	Grille copy = copyGrille(grille);
	Piece roi = trouverRoi(copy,equipe);
	clearDeplacement(copy);
	deplacerPiece(copy,piece -> coord,coordArrive);
	setDeplacement(copy);
	if(echec(roi->coord,copy,equipe%2+1)){
		freeGrille(copy);
		return 1;
	}
	freeGrille(copy);
	return 0;
}

/*Fonction permettant de déterminer si un joueur est mit échec et mat*/
int echecMat(Grille grille){
	int taille_max=200;
	Move * moves=(Move *)malloc(sizeof(struct Move_)*taille_max);
	int nbMoves=0;

	int joueur_actu=(grille->tour+1) % 2 + 1;

	int i;
	for(i=0; i<80; i++)
	{
		if(grille->pions[i]->color==joueur_actu)
		{
			calc_moves(grille, i, joueur_actu, moves, &nbMoves, &taille_max);
		}
	}

	Grille grille_tmp=copyGrille(grille);
	Piece p;
	int tmp_max_victim=0;
	for(i=0; i<nbMoves; i++)
	{
		if(moves[i]->value_piece==10 && (moves[i]->indiceA==moves[i]->indiceB+2 || moves[i]->indiceA==moves[i]->indiceB-2))
		{
			moves[i]->points = -100;
		}else
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
			}
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
		}
	}

	if(move_elu==NULL)
	{
		printf("ECHEC ET MAT\n");
		return 1;
	}

	free(moves);

	return 0;
}

/*Détermine si la piece d'un joueur peut être pris*/
int echec(Coord coord,Grille grille,int equipe){
	int i,j;
	for(i = 0 ; i < 8 ; i++){
		for(j = 0 ; j < 10 ; j++){
			Piece pion = grille -> pions[getIndice(i,j)];
			if(pion -> color == equipe){
				int k;
				for(k = 0; k < pion -> deplacement -> nombre_element; k++){
					Coord coordPossible = pion -> deplacement -> mouvements[k];
					if(coordPossible -> x == coord -> x && coordPossible -> y == coord -> y){
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
