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
	placerPiece(grille,pion);

	placerPiece(grille,pion2);
	affichage(grille);

	while(echec_et_mat == 0 && grille -> tour<=2){
		grille -> tour ++;
		piece = choosePawn(grille);
		proposerDeplacer(grille,piece);
	}
}