#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

int main(void){
	Grille grille = initialisation();
	affichage(grille);
	int echec_et_mat = 0;
	proposerDeplacer(grille,* grille -> pions);
}