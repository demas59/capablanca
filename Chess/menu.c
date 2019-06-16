#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "../struct.h"
#include "graphique.h"

SDL_Surface * afficheTourJoueur(Grille plateau, SDL_Surface * ecran){
  SDL_Surface * texte = NULL;
  TTF_Font *policeTitre = NULL; // Déclaration de la police de notre titre
  TTF_Font *policeMenu = NULL;  // Déclaration de la police de nos menus
  SDL_Color textColor;  // Déclaration de la couleur de nos polices
  SDL_Rect textePos;

  /* Chargement de la police */
  policeTitre = TTF_OpenFont("angelina.TTF", 100); // Définition de la police du Titre
  policeMenu = TTF_OpenFont("angelina.TTF", 80);  // Définition de la police de nos menus

  if(plateau -> tour % 2 +1 == 1){
    textColor.r = 255;
    textColor.g = 255;
    textColor.b = 255;

      texte = TTF_RenderText_Blended(policeTitre, "C'est a votre tour de jouer!", textColor);
  }else{
    textColor.r = 0;
    textColor.g = 0;
    textColor.b = 0;
      texte = TTF_RenderText_Blended(policeTitre, "C'est a votre tour de jouer!", textColor);
  }


  // Position du texte du Titre
  textePos.x = X_MARGIN+100;
  textePos.y = 5;

  SDL_BlitSurface(texte, NULL, ecran, &textePos); /* Blit du texte */

  SDL_Flip(ecran);
}

void joueurVsJoueur(SDL_Surface * ecran){
    SDL_Surface * fond,* tourJoueur = NULL;
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

        tourJoueur = afficheTourJoueur(plateau,ecran);

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


        SDL_FreeSurface(tourJoueur);

        affichageGraphique(plateau, ecran);
        clearDeplacement(plateau);
        setDeplacement(plateau);
    }

    printf("LE JOUEUR %d A PERDU\n", joueur);
    SDL_FreeSurface(fond); /* On lib�re la surface */
}

void joueurVsIA(SDL_Surface * ecran){
    SDL_Surface * fond,* tourJoueur = NULL;
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

        tourJoueur = afficheTourJoueur(plateau,ecran);
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

        SDL_FreeSurface(tourJoueur);
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
        sleep(0.5);

        affichageGraphique(plateau, ecran);
        clearDeplacement(plateau);
        setDeplacement(plateau);
    }

    printf("L'IA %d A PERDU\n", joueur);
    sleep(60);
    SDL_FreeSurface(fond); /* On lib�re la surface */
}
