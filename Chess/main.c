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
    ecran = SDL_SetVideoMode(680, 560, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chess Projet", NULL);

    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    // Initialisation des positions de d�part de pieces Noires
    Grille plateau = initialisation();
    affichageGraphique(plateau, ecran);

    SDL_Flip(ecran);
//    pause();

//
    selectPiece(plateau);

//

    SDL_FreeSurface(imageDeFond); /* On lib�re la surface */
    SDL_Quit();

    return EXIT_SUCCESS;
}