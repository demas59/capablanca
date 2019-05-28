#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

int main(void){
	Grille grille = initialisation();
	int echec_et_mat = 0;
	Piece piece;
	affichage(grille);

	clearDeplacement(grille);
	setDeplacement(grille);
	// while(echec_et_mat == 0 && grille -> tour<=2){
	while(echec_et_mat == 0){
		grille -> tour ++;
		IA_jouer(grille);
		piece = choosePawn(grille);
		

		/*Coord position_arrivee = choixCoord(piece->deplacement->mouvements,piece->deplacement->nombre_element);
		deplacerPiece(grille,piece -> coord,position_arrivee  );
		affichage(grille);
		clearDeplacement(grille);
		setDeplacement(grille);
		echec_et_mat = echecMat(grille,(grille->tour % 2 + 1));*/
	}
}