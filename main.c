#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

int main(void){
	Grille grille = initialisation();
	int echec_et_mat = 0;
	int estEnEchec = 0;
	int joueur;

	Piece piece;
	Piece pion = createPiece(2,2,0,'p');
	// Piece pion2 = createPiece(1,5,0,'p');
	// Piece cavalier = createPiece(1,4,4,'c');
	// Piece fou = createPiece(1,4,5,'f');

	placerPiece(grille,pion);
	// placerPiece(grille,pion2);
	// placerPiece(grille,cavalier);
	// placerPiece(grille,fou);
	affichage(grille);

	initDeplacement(grille);
	clearDeplacement(grille);
	setDeplacement(grille);

	while(echec_et_mat == 0){
		grille -> tour ++;
		joueur = grille -> tour % 2 + 1;
		int adversaire = joueur % 2 + 1;
		int seraEnEchec = -1;

		if(01){//joueur == 1){
			int seraEnEchec = -1;
			if(estEnEchec == 1){
				printf("ATTENTION JOUEUR %d VOTRE ROI EST EN ECHEC\n",joueur);
			}

			piece = choosePawn(grille);
			Coord position_arrivee = malloc(sizeof(struct coord_));

				do{
					position_arrivee = choixCoord(piece->deplacement->mouvements,piece->deplacement->nombre_element);
					seraEnEchec = roiPeutEtrePris(piece,position_arrivee,grille,joueur);
					if(seraEnEchec == 1){
						printf("IMPOSSIBLE CELA VOUS METTEREZ EN ECHEC CHOISISSEZ UNE AUTRE POSITION\n");
					}
				}while(seraEnEchec == 1);


			deplacerPiece(grille,piece -> coord,position_arrivee);
			//free(position_arrivee);
		}else
		{
			echec_et_mat=IA_jouer(grille);
			myflush ( stdin );
			mypause();
		}
		affichage(grille);
		clearDeplacement(grille);
		setDeplacement(grille);

		Piece roi = trouverRoi(grille,adversaire);
		estEnEchec = echec(roi -> coord, grille, joueur);
		echec_et_mat = echecMat(grille);
	}

	printf("LE JOUEUR %d A PERDU\n", joueur % 2 + 1);
	return 1;
}
