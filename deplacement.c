#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

Deplacement createDeplacement(){
	Deplacement d = (Deplacement)malloc(sizeof(struct deplacement_));
	d -> deplace = 0;
	d -> taille_max = 20;
	d -> nombre_element = 0;
	d -> mouvements = (Coord *)malloc(sizeof(struct coord_) * 20);
	return d;
}

void clearDeplacement(Grille grille){
	int i,j;
	for(i = 0;i<8;i++){
		for(j = 0; j < 10; j++){
			free(grille -> pions[getIndice(i,j)] -> deplacement);
			grille -> pions[getIndice(i,j)] -> deplacement = createDeplacement();
		}
	}
}

void setDeplacement(Grille grille){
	int i,j;
	for(i = 0;i<8;i++){
		for(j = 0; j < 10; j++){
			proposerDeplacer(grille,grille -> pions[getIndice(i,j)]);
		}
	}
}

Deplacement copyDeplacement(Deplacement origine){
	Deplacement copy = (Deplacement)malloc(sizeof(struct deplacement_));
	copy -> deplace = origine -> deplace;
	copy -> taille_max = origine -> taille_max;
	copy -> nombre_element = origine -> nombre_element;
	copy -> mouvements = (Coord *)malloc(sizeof(struct  coord_) * copy->nombre_element);
	int i;
	for(i = 0; i < copy->nombre_element ; i++){
		copy->mouvements[i] = createCoord(origine -> mouvements[i] -> x, origine -> mouvements[i] -> y);
	}
	return copy;
}