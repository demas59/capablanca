#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

// Fonction qui donne tout les coordonnées des mouvements possible par une piece
void parcoursCoord(Coord * coords,int nombre_element){
	int i;
	printf("Deplacement possibles:\n");
	for(i = 0; i<nombre_element; i++){
		Coord coord = *(coords + i);
		printf("coord: %c%d\n",'a'+coord->y,coord->x + 1 );
	}
}

// Fonction qui propose un mouvement en fonction du type de la pièce séléctionné
void proposerDeplacer(Grille grille,Piece piece){
	switch(piece -> type){
		case 't': mouvTour(grille,piece);
		break;
		case 'p': mouvPion(grille,piece);
		break;
		case 'c': mouvCavalier(grille,piece);
		break;
		case 'f': mouvFou(grille,piece);
		break;
		case 'q': mouvTour(grille,piece);
					mouvFou(grille,piece);
		break;
		case 'x': mouvFou(grille,piece);
					mouvCavalier(grille,piece);
		break;
		case 'i': mouvTour(grille,piece);
					mouvCavalier(grille,piece);
		break;
		case 'k': mouvRoi(grille,piece);
		break;
	}
}

// Fonction qui permet de choisir une pièce
Piece choosePawn(Grille grille)
{
	char * choix = malloc(sizeof(char)*2);
	printf("Joueur %d, veuillez choisir une piece a deplacer (ex: a2, b3, d6).\n", ((grille->tour)%2)+1);
	scanf("%s", choix);

	int colone=((int)choix[0]-(int)'a');
	int ligne=(int)choix[1]-(int)'1';

	int indice=getIndice(ligne, colone);
	int joueur=(grille->tour)%2+1;

	if(joueur==grille->pions[indice]->color)
	{
		return grille->pions[indice];
	}else
	{
		return NULL;
	}
}

//Fonction qui permet de trouver le roi de l'équipe selectionnée
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

// Fonction qui vérifie si le Roi d'une équipe peut être pris
int roiPeutEtrePris(Piece piece,Coord coordArrive,Grille grille,int equipe){
	Grille copy = copyGrille(grille);
	Piece roi = trouverRoi(copy,equipe);
	clearDeplacement(copy);
	deplacerPiece(copy,piece -> coord,coordArrive);
	setDeplacement(copy);
	if(echec(roi->coord,copy,equipe%2+1)){
		free(copy);
		return 1;
	}
	free(copy);
	return 0;
}


// Fonction qui vérifie si un joueur est en situation d'echec & mat
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
	free(grille_tmp);



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

// Fonction qui vérifie si un Roi est en échec
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
