#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "../struct.h"
#include "graphique.h"


int pause();

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *rectangle1 = NULL, *rectangle2 = NULL, *rectangle3 = NULL, *texte = NULL, *pvp = NULL, *pva = NULL, *ava = NULL; // Déclaration de toutes les surfaces utilisées
    SDL_Rect position1, position2, position3, textePos, pvpPos, pvaPos, avaPos; // Déclaration des positions des surfacs utilisées
    TTF_Font *policeTitre = NULL; // Déclaration de la police de notre titre 
    TTF_Font *policeMenu = NULL;  // Déclaration de la police de nos menus
    SDL_Color textColor;  // Déclaration de la couleur de nos polices
    textColor.r = 255;
    textColor.g = 255;
    textColor.b = 255;

    SDL_Init(SDL_INIT_VIDEO); // Initialisation du graphique
    TTF_Init(); // Initialisation de la prise en compte du texte


    /* Chargement de la police */
    policeTitre = TTF_OpenFont("angelina.TTF", 100); // Définition de la police du Titre
    policeMenu = TTF_OpenFont("angelina.TTF", 80);  // Définition de la police de nos menus

    /* Écriture du texte dans la SDL_Surface texte en mode Blended */
    texte = TTF_RenderText_Blended(policeTitre, "Capablanca !", textColor);

    pvp = TTF_RenderText_Blended(policeMenu, "Joueur vs Joueur !", textColor);
    pva = TTF_RenderText_Blended(policeMenu, "Joueur vs IA !", textColor);
    ava = TTF_RenderText_Blended(policeMenu, "IA vs IA !", textColor);

    /* Chargement de notre Surface principale de travail, la fenetre*/

    ecran = SDL_SetVideoMode(LARGEUR, LONGUEUR, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);

    SDL_Surface * fond = NULL;
    fond = IMG_Load("Image/fond.jpg");
    SDL_Rect zero;
    zero.x = 0;
    zero.y = 0;
    SDL_BlitSurface(fond,NULL,ecran,&zero);

    // Allocation de la surface
    rectangle1 = SDL_CreateRGBSurface(SDL_HWSURFACE, 800, 150, 32, 0, 0, 0, 0);
    rectangle2 = SDL_CreateRGBSurface(SDL_HWSURFACE, 800, 150, 32, 0, 0, 0, 0);
    rectangle3 = SDL_CreateRGBSurface(SDL_HWSURFACE, 800, 150, 32, 0, 0, 0, 0);

    //Titre de notre fenetre
    SDL_WM_SetCaption("Menu !", NULL);

    // Couleur du fond
    //SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

    // Position du menu 1
    position1.x = LARGEUR/4;
    position1.y = 200;

    // Position du menu 2
    position2.x = LARGEUR/4;
    position2.y = 400;

    // Position du menu 3
    position3.x = LARGEUR/4;
    position3.y = 600;

    // Position du texte du menu 1
    pvpPos.x = LARGEUR/3;
    pvpPos.y = 225;

    // Poistion du texte du menu 2
    pvaPos.x = LARGEUR/3+50;
    pvaPos.y = 425;

    // Position du texte du menu 3
    avaPos.x = LARGEUR/3+100;
    avaPos.y = 625;

    // Position du texte du Titre
    textePos.x = LARGEUR/3+50;
    textePos.y = 40;



    // Remplissage des menus avec du gris
    SDL_FillRect(rectangle1, NULL, SDL_MapRGB(ecran->format, 100, 100, 100));
    SDL_FillRect(rectangle2, NULL, SDL_MapRGB(ecran->format, 120, 120, 120));
    SDL_FillRect(rectangle3, NULL, SDL_MapRGB(ecran->format, 140, 140, 140));

    SDL_BlitSurface(rectangle1, NULL, ecran, &position1); // Collage de la surface sur l'écran
    SDL_BlitSurface(rectangle2, NULL, ecran, &position2); // Collage de la surface sur l'écran
    SDL_BlitSurface(rectangle3, NULL, ecran, &position3); // Collage de la surface sur l'écran
    SDL_BlitSurface(texte, NULL, ecran, &textePos); /* Blit du texte */
    SDL_BlitSurface(pvp, NULL, ecran, &pvpPos); /* Blit du texte */
    SDL_BlitSurface(pva, NULL, ecran, &pvaPos); /* Blit du texte */
    SDL_BlitSurface(ava, NULL, ecran, &avaPos); /* Blit du texte */

    SDL_Flip(ecran); // Mise à jour de l'écran
    int type_game;
    // Fonction Pause, voir plus bas
    type_game = pause();

    switch(type_game){
        case 1:
            joueurVsJoueur(ecran);
        break;
        case 2:
            joueurVsIA(ecran);
        break;
        case 3:
            iaVsIa(ecran);
        break;
    }



    // Fermeture de l'application texte de SDL
    TTF_CloseFont(policeTitre);
    TTF_CloseFont(policeMenu);
    TTF_Quit();

    SDL_FreeSurface(texte);
    SDL_FreeSurface(ava);
    SDL_FreeSurface(pva);
    SDL_FreeSurface(pvp);
    SDL_FreeSurface(rectangle1); // Libération de la surface
    SDL_FreeSurface(rectangle2);
    SDL_FreeSurface(rectangle3);

    // Fermeture de l'appplication SDL
    SDL_Quit();

    return EXIT_SUCCESS;
}


int pause(){
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
        case SDL_QUIT:
        continuer = 0;  // Un clique sur la croix fermera le programme
        break;

        case SDL_MOUSEBUTTONUP:
        if (event.button.button == SDL_BUTTON_LEFT) // Si un clic gauche est detecté alors :
          if((event.button.x >= LARGEUR/4 && event.button.x <= LARGEUR/4+810) && (event.button.y >= 200 && event.button.y <= 350)){
            printf("Bon clic menu 1\n");
            printf("x : %d y : %d \n", event.button.x, event.button.y); // Renvoi 1 si le clique se situe sur le menu 1
            return 1;
          }
          else if((event.button.x >= LARGEUR/4 && event.button.x <= LARGEUR/4+810) && (event.button.y >= 400 && event.button.y <= 550)){
            printf("Bon clic menu 2\n");
            printf("x : %d y : %d \n", event.button.x, event.button.y); // Renvoi 2 si le clique se situe sur le menu 2
            return 2;
          }
          else if((event.button.x >= LARGEUR/4 && event.button.x <= LARGEUR/4+810) && (event.button.y >= 600 && event.button.y <= 750)){
            printf("Bon clic menu 3\n");
            printf("x : %d y : %d \n", event.button.x, event.button.y); // Renvoi 3 si le clique se situe sur le menu 3
            return 3;
          }
        break;
      }
    }
  }
