#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <unistd.h>
#include "../struct.h"
#include "graphique.h"

int main(int argc, char *argv[])
	{
    SDL_Surface * ecran = NULL;
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;

    SDL_Init(SDL_INIT_VIDEO);
    /* Cr�ation de la fenetre de base */
    ecran = SDL_SetVideoMode(LARGEUR, LONGUEUR, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chess Projet", NULL);

    // Initialisation des positions de d�part de pieces Noires
    Grille plateau = initialisation();
    initDeplacement(plateau);
  	clearDeplacement(plateau);
  	setDeplacement(plateau);
    Grille grille = initialisation();
    int echec_et_mat = 0;
    int estEnEchec = 0;
    int joueur;
    affichageGraphique(plateau, ecran);

    int quitter = 1;
    int nbCalc=0;
    while(echec_et_mat == 0 && quitter == 1){
        plateau -> tour ++;
        joueur = plateau -> tour % 2 + 1;
        int adversaire = joueur % 2 + 1;
        int seraEnEchec = -1;
        Piece selectionne = NULL;

        if(1){//joueur == 1){
            if(estEnEchec == 1){
                printf("ATTENTION JOUEUR %d VOTRE ROI EST EN ECHEC\n",joueur);
            }

            do{
                selectionne = selectPiece(plateau,selectionne,&quitter);
                affichageGraphique(plateau, ecran);
                if(quitter == 1){
                  selectionne = selectPiece(plateau,selectionne,&quitter);
                  affichageGraphique(plateau, ecran);
                }
            }while(selectionne == NULL);


        }else{
            echec_et_mat=IA_jouer(plateau);
            sleep(0.5);
        }
        affichageGraphique(plateau, ecran);
        clearDeplacement(plateau);
        setDeplacement(plateau);

        Piece roi = trouverRoi(plateau,adversaire);
        estEnEchec = echec(roi -> coord, plateau, joueur);
        //echec_et_mat = echecMat(grille);

    }

    printf("LE JOUEUR %d A PERDU\n", joueur);
    sleep(60);
    SDL_FreeSurface(ecran); /* On lib�re la surface */
    SDL_Quit();

    return EXIT_SUCCESS;
}
