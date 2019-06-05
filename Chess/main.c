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
    SDL_Surface *ecran = NULL, *imageDeFond = NULL;
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
    Grille g1 = initialisation();
    int m ; int l;
    for (m = 0; m < 8 ; m++){
        for(l=0; l < 10; l++){
            switch (g1 -> pions[getIndice(m,l)] -> type){
        case 'k' :
            {
                if(g1 -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionRoiN; positionRoiN.x = 68 * l; positionRoiN.y = 70 * m; SDL_Surface *roiN = NULL; roiN = IMG_Load("Image/black_king.png"); SDL_BlitSurface(roiN, NULL, ecran, &positionRoiN);
                }
                else if(g1 -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionRoiB; positionRoiB.x = 68 * l; positionRoiB.y = 70 * m; SDL_Surface *roiB = NULL; roiB = IMG_Load("Image/white_king.png"); SDL_BlitSurface(roiB, NULL, ecran, &positionRoiB);
                }
            }break;
        case 'q' :
            {
                if(g1 -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionReineN ; positionReineN.x = 68 * l; positionReineN.y = 70 * m; SDL_Surface *reineN = NULL; reineN = IMG_Load("Image/black_queen.png"); SDL_BlitSurface(reineN, NULL, ecran, &positionReineN);
                }
                else if(g1 -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionReineB; positionReineB.x = 68 * l; positionReineB.y = 70 * m; SDL_Surface *reineB = NULL; reineB = IMG_Load("Image/white_queen.png"); SDL_BlitSurface(reineB, NULL, ecran, &positionReineB);
                }
            }break;
        case 'c' :
            {
                if(g1 -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionCavalierN ; positionCavalierN.x = 68 * l; positionCavalierN.y = 70 * m; SDL_Surface *cavalierN = NULL ; cavalierN = IMG_Load("Image/black_knight.png"); SDL_BlitSurface(cavalierN, NULL, ecran, &positionCavalierN);
                }
                else if(g1 -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionCavalierB; positionCavalierB.x = 68 * l; positionCavalierB.y = 70 * m; SDL_Surface *cavalierB = NULL; cavalierB = IMG_Load("Image/white_knight.png"); SDL_BlitSurface(cavalierB, NULL, ecran, &positionCavalierB);
                }
            }break;
        case 'f' :
            {
                if(g1 -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionFouN ; positionFouN.x = 68*l; positionFouN.y = 70*m; SDL_Surface *fouN = NULL ; fouN = IMG_Load("Image/black_bishop.png"); SDL_BlitSurface(fouN, NULL, ecran, &positionFouN);
                }
                else if(g1 -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionFouB; positionFouB.x = 68 * l; positionFouB.y = 70 * m; SDL_Surface *fouB = NULL; fouB = IMG_Load("Image/white_bishop.png"); SDL_BlitSurface(fouB, NULL, ecran, &positionFouB);
                }
            }break;
        case 't' :
            {
                if(g1 -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionTourN ; positionTourN.x = 68*l; positionTourN.y = 70*m; SDL_Surface *tourN = NULL ; tourN = IMG_Load("Image/black_rook.png"); SDL_BlitSurface(tourN, NULL, ecran, &positionTourN);
                }
                else if(g1 -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionTourB; positionTourB.x = 68 * l; positionTourB.y = 70 * m; SDL_Surface *tourB = NULL; tourB = IMG_Load("Image/white_rook.png"); SDL_BlitSurface(tourB, NULL, ecran, &positionTourB);
                }
            }break;
        case 'p' :
        {
            if(g1 -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionPionN ; positionPionN.x = 68*l; positionPionN.y = 70*m; SDL_Surface *pionN = NULL ; pionN = IMG_Load("Image/black_pawn.png"); SDL_BlitSurface(pionN, NULL, ecran, &positionPionN);
                }
                else if(g1 -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionPionB; positionPionB.x = 68 * l; positionPionB.y = 70 * m; SDL_Surface *pionB = NULL; pionB = IMG_Load("Image/white_pawn.png"); SDL_BlitSurface(pionB, NULL, ecran, &positionPionB);
                }
        }break;
        case 'i' :
            {
                if(g1 -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionImperatriceN ; positionImperatriceN.x = 68*l; positionImperatriceN.y = 70*m; SDL_Surface *imperatriceN = NULL ; imperatriceN = IMG_Load("Image/black_imperatrice.png"); SDL_BlitSurface(imperatriceN, NULL, ecran, &positionImperatriceN);
                }
                else if(g1 -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionImperatriceB; positionImperatriceB.x = 68 * l; positionImperatriceB.y = 70 * m; SDL_Surface *imperatriceB = NULL; imperatriceB = IMG_Load("Image/white_imperatrice.png"); SDL_BlitSurface(imperatriceB, NULL, ecran, &positionImperatriceB);
                }
            }break;
        case 'x' :
            {
                if(g1 -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionPrincesseN ; positionPrincesseN.x = 68*l; positionPrincesseN.y = 70*m; SDL_Surface *princesseN = NULL ; princesseN = IMG_Load("Image/black_princesse.png"); SDL_BlitSurface(princesseN, NULL, ecran, &positionPrincesseN);
                }
                else if(g1 -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionPrincesseB; positionPrincesseB.x = 68 * l; positionPrincesseB.y = 70 * m; SDL_Surface *princesseB = NULL; princesseB = IMG_Load("Image/white_princesse.png"); SDL_BlitSurface(princesseB, NULL, ecran, &positionPrincesseB);
                }
            }break;
            }
        }
    }

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
            coordClick = createCoord(event.button.x/68,event.button.y/70);
            if (!checkVoid(coordClick, g1)){
                proposerDeplacer(g1, g1 -> pions[getIndice(coordClick -> x, coordClick -> y)]);

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
