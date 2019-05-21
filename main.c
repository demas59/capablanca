#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

int main(void){
	Grille grille = initialisation();
	int echec_et_mat = 0;
	Piece piece;

	Piece pion = createPiece(2,2,0,'p');
	Piece pion2 = createPiece(1,5,0,'p');
	Piece cavalier = createPiece(1,4,4,'c');
	Piece fou = createPiece(1,4,5,'f');

	// placerPiece(grille,pion);
	// placerPiece(grille,pion2);
	// placerPiece(grille,cavalier);
	// placerPiece(grille,fou);
	affichage(grille);

	clearDeplacement(grille);
	setDeplacement(grille);
	// while(echec_et_mat == 0 && grille -> tour<=2){
	while(echec_et_mat == 0){
		grille -> tour ++;
		piece = choosePawn(grille);
		

		Coord position_arrivee = choixCoord(piece->deplacement->mouvements,piece->deplacement->nombre_element);
		deplacerPiece(grille,piece -> coord,position_arrivee  );
		affichage(grille);
		clearDeplacement(grille);
		setDeplacement(grille);
		echec_et_mat = echecMat(grille,(grille->tour % 2 + 1));
	}
}