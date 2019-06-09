#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../struct.h"
#include "graphique.h"

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

int main(int argc, char *argv[])
	{
    SDL_Surface * ecran = NULL, *imageDeFond = NULL;
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;
    imageDeFond = IMG_Load("echiquier.png");

    SDL_Init(SDL_INIT_VIDEO);
    /* Cr�ation de la fenetre de base */
    ecran = SDL_SetVideoMode(1020, 840, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chess Projet", NULL);

    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
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

    /*int i = 0;
    Piece selectionne = NULL;
    while(3>i++){
        affichageGraphique(plateau, ecran);
        selectionne = selectPiece(plateau,selectionne);
        printf("case selection: %d\n",plateau -> pions[getIndice(1,0)] -> select );
    }*/

    while(echec_et_mat == 0){
        plateau -> tour ++;
        joueur = plateau -> tour % 2 + 1;
        int adversaire = joueur % 2 + 1;
        int seraEnEchec = -1;
        Piece selectionne = NULL;

        if(1){//joueur == 1){
            int seraEnEchec = -1;
            if(estEnEchec == 1){
                printf("ATTENTION JOUEUR %d VOTRE ROI EST EN ECHEC\n",joueur);
            }

            do{
                selectionne = selectPiece(plateau,selectionne);
                selectionne = selectPiece(plateau,selectionne);
            }while(selectionne == NULL);
            
        }else{
            echec_et_mat=IA_jouer(plateau);
            myflush ( stdin );
            mypause();
        }
        affichage(plateau);
        clearDeplacement(plateau);
        setDeplacement(plateau);

        Piece roi = trouverRoi(plateau,adversaire);
        estEnEchec = echec(roi -> coord, plateau, joueur);
        echec_et_mat = echecMat(plateau,joueur);
    }

    printf("LE JOUEUR %d A PERDU\n", joueur % 2 + 1);


    SDL_FreeSurface(imageDeFond); /* On lib�re la surface */
    SDL_Quit();

    return EXIT_SUCCESS;
}
