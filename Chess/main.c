#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../struct.h"

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

int checkVoid(Coord coordClick, Grille g){
            if (g -> pions[getIndice(coordClick -> x, coordClick -> y)] -> color == 0){
                return 0;
            }
            else{
                return 1;
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
    affichage(plateau, ecran);

    SDL_Flip(ecran);
//    pause();

//
SDL_Event event;
Coord coordClick;
int continuer = 1;
while(continuer){
    SDL_WaitEvent(&event);
    switch(event.type)
{
    case SDL_QUIT:
        continuer = 0;
        break;
    case SDL_MOUSEBUTTONUP:
        if (event.button.button == SDL_BUTTON_LEFT){ /* Si on fait un clique gauche, on lance l'instruction*/
            coordClick = createCoord(event.button.x/CASE_LARG,event.button.y/CASE_LONG);
            if (!checkVoid(coordClick, plateau)){
                proposerDeplacer(plateau, plateau -> pions[getIndice(coordClick -> x, coordClick -> y)]);

            }

 //           continuer = 0;
        }
        break;
}
}

//

    SDL_FreeSurface(imageDeFond); /* On lib�re la surface */
    SDL_Quit();

    return EXIT_SUCCESS;
}
