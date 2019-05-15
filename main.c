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

	Coord * deplacements;

	// while(echec_et_mat == 0 && grille -> tour<=2){
	while(echec_et_mat == 0){
		int nombre_element = 0;
		int taille_max = 20;
		deplacements = calloc(taille_max,sizeof(Coord));
		

		grille -> tour ++;
		piece = choosePawn(grille);
		proposerDeplacer(grille,piece,&taille_max,&nombre_element,deplacements);

		Coord position_arrivee = choixCoord(deplacements,nombre_element);
		deplacerPiece(grille,piece -> coord,position_arrivee  );
		affichage(grille);
		printf("position_arrivee: %d,%d\n",position_arrivee->x,position_arrivee->y );
	}
}