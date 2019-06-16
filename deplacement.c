#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"


// Créer une variable déplacement
Deplacement createDeplacement(){
	Deplacement d = (Deplacement)malloc(sizeof(struct deplacement_));
	d -> deplace = 0;
	d -> taille_max = 50;
	d -> nombre_element = 0;
	d -> mouvements = (Coord *)malloc(sizeof(struct coord_) * (d -> taille_max));
	return d; // Renvoila variable déplacement
}

// Créer une variable déplacement pour tout les pions d'une grille.
void initDeplacement(Grille grille)
{
	int i,j;
	for(i = 0;i<8;i++){
		for(j = 0; j < 10; j++){
			grille -> pions[getIndice(i,j)] -> deplacement = createDeplacement();	// Parcour le tableau "grille" et créer un "déplacement" pour chaque piece
		}
	}
}

// Supprime une variable déplacement
void viderDeplacement(Deplacement d){
	int i;
	for(i=0;i< d->nombre_element;i++){
		free(d->mouvements[i]);
	}
}

// Vide une variable déplacement
void clearDeplacement(Grille grille){
	int i,j;
	for(i = 0;i<8;i++){
		for(j = 0; j < 10; j++){
			viderDeplacement(grille -> pions[getIndice(i,j)] -> deplacement);
			grille -> pions[getIndice(i,j)] -> deplacement -> nombre_element=0;
			/*free(grille -> pions[getIndice(i,j)] -> deplacement);
			grille -> pions[getIndice(i,j)] -> deplacement = createDeplacement();*/
		}
	}
}

// Pour chaque piece de la grille, met à jour ses déplacements disponible
void setDeplacement(Grille grille){
	int i,j;
	for(i = 0;i<8;i++){
		for(j = 0; j < 10; j++){
			if(grille -> pions[getIndice(i,j)] -> type == 'p'){
				promotion(grille -> pions[getIndice(i,j)]);
			}
			proposerDeplacer(grille,grille -> pions[getIndice(i,j)]);
		}
	}
}

// Copie une variable déplacement dans une autre
Deplacement copyDeplacement(Deplacement origine){
	Deplacement copy = (Deplacement)malloc(sizeof(struct deplacement_));
	copy -> deplace = origine -> deplace;
	copy -> taille_max = origine -> taille_max;
	copy -> nombre_element = origine -> nombre_element;
	copy -> mouvements = (Coord *)malloc(sizeof(struct  coord_) * (copy -> taille_max));
	int i;
	for(i = 0; i < copy -> nombre_element ; i++){
		copy->mouvements[i] = createCoord(origine -> mouvements[i] -> x, origine -> mouvements[i] -> y);
	}
	return copy;
}

// Free une variable déplacement
void freeDeplacement(Deplacement d){
	int i;
	for(i=0;i<d->nombre_element;i++){
		free(d->mouvements[i]);
	}
	free(d);
}
