#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "struct.h"
#include "graphique.h"

void joueurVsJoueur(SDL_Surface * ecran){
    SDL_Surface * fond = NULL;
    fond = IMG_Load("Image/fond.jpg");
    SDL_Rect zero;

    zero.x = 0;
    zero.y = 0;
    SDL_BlitSurface(fond,NULL,ecran,&zero);

    // Initialisation des positions de d�part de pieces Noires
    Grille plateau = initialisation();
    initDeplacement(plateau);
    clearDeplacement(plateau);
    setDeplacement(plateau);
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

        Piece roi = trouverRoi(plateau,adversaire);
        estEnEchec = echec(roi -> coord, plateau, joueur);
        echec_et_mat = echecMat(plateau);

        affichageGraphique(plateau, ecran);
        clearDeplacement(plateau);
        setDeplacement(plateau);
    }

    printf("LE JOUEUR %d A PERDU\n", joueur);
    SDL_FreeSurface(fond); /* On lib�re la surface */
}

void joueurVsIA(SDL_Surface * ecran){
    SDL_Surface * fond = NULL;
    fond = IMG_Load("Image/fond.jpg");
    SDL_Rect zero;

    zero.x = 0;
    zero.y = 0;
    SDL_BlitSurface(fond,NULL,ecran,&zero);

    // Initialisation des positions de d�part de pieces Noires
    Grille plateau = initialisation();
    initDeplacement(plateau);
    clearDeplacement(plateau);
    setDeplacement(plateau);
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

        if(joueur % 2 == 1){//joueur == 1){
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
                Piece roi = trouverRoi(plateau,adversaire);
                estEnEchec = echec(roi -> coord, plateau, joueur);
                echec_et_mat = echecMat(plateau);

        }else{
            echec_et_mat=IA_jouer(plateau);
            sleep(1);
        }

        affichageGraphique(plateau, ecran);
        clearDeplacement(plateau);
        setDeplacement(plateau);
    }

    printf("LE JOUEUR %d A PERDU\n", joueur);
    sleep(60);
    SDL_FreeSurface(fond); /* On lib�re la surface */
}

void iaVsIa(SDL_Surface * ecran){
    SDL_Surface * fond = NULL;
    fond = IMG_Load("Image/fond.jpg");
    SDL_Rect zero;

    zero.x = 0;
    zero.y = 0;
    SDL_BlitSurface(fond,NULL,ecran,&zero);

    // Initialisation des positions de d�part de pieces Noires
    Grille plateau = initialisation();
    initDeplacement(plateau);
    clearDeplacement(plateau);
    setDeplacement(plateau);
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

        echec_et_mat=IA_jouer(plateau);
        sleep(1);

        affichageGraphique(plateau, ecran);
        clearDeplacement(plateau);
        setDeplacement(plateau);
    }

    printf("L'IA %d A PERDU\n", joueur);
    sleep(60);
    SDL_FreeSurface(fond); /* On lib�re la surface */
}