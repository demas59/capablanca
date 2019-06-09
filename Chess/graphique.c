#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../struct.h"
#include "graphique.h"

void changeCouleurFond(Piece piece,SDL_Surface * ecran ){
    SDL_Surface * rectangle = NULL;
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, CASE_LARG, CASE_LONG, 32, 0, 0, 0, 0);
    SDL_Rect position;
    position.x = piece -> coord -> y * CASE_LARG;
    position.y = piece -> coord -> x * CASE_LONG;

    if(piece -> coord -> y == 0 && piece -> coord -> x == 3){
    }

		if(piece -> select == 1){
			SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format,  50, 200, 50));
			SDL_BlitSurface(rectangle, NULL, ecran, &position);
		}
		if(piece -> select == 2){
			SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format,  255,0,0));
			SDL_BlitSurface(rectangle, NULL, ecran, &position);
		}
        if(piece -> select == 3){
            SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format,  70,130,180));
            SDL_BlitSurface(rectangle, NULL, ecran, &position);
        }
}

void affichageGraphique(Grille plateau, SDL_Surface * ecran){

    SDL_Surface * fond = NULL;
    fond = IMG_Load("echiquier.png");
    SDL_Rect posinit;
    posinit.x = 0;
    posinit.y = 0;
    SDL_BlitSurface(fond,NULL,ecran,&posinit);

    int m ; int l;
    for (m = 0; m < 8 ; m++){
        for(l=0; l < 10; l++){

            Piece piece = plateau -> pions[getIndice(m,l)] ;
            switch (piece -> type){
        case 'k' :
            {
                if(piece -> color == 2){
                SDL_Rect positionRoiN;
                positionRoiN.x = CASE_LARG * l + X_MARGIN;
                positionRoiN.y = CASE_LONG * m + Y_MARGIN;
                SDL_Surface *roiN = NULL;
                roiN = IMG_Load("Image/black_king.png");
                changeCouleurFond(piece,ecran);
                SDL_BlitSurface(roiN, NULL, ecran, &positionRoiN);
                }
                else if(piece -> color == 1){
                SDL_Rect positionRoiB;
                positionRoiB.x = CASE_LARG * l + X_MARGIN;
                positionRoiB.y = CASE_LONG * m + Y_MARGIN;
                SDL_Surface *roiB = NULL; roiB = IMG_Load("Image/white_king.png");
                changeCouleurFond(piece,ecran);
                SDL_BlitSurface(roiB, NULL, ecran, &positionRoiB);
                }
            }break;
        case 'q' :
            {
                if(piece -> color == 2){
                SDL_Rect positionReineN ;
                positionReineN.x = CASE_LARG * l + X_MARGIN;
                positionReineN.y = CASE_LONG * m + Y_MARGIN;
                SDL_Surface *reineN = NULL;
                reineN = IMG_Load("Image/black_queen.png");
                changeCouleurFond(piece,ecran);
                SDL_BlitSurface(reineN, NULL, ecran, &positionReineN);
                }
                else if(piece -> color == 1){
                SDL_Rect positionReineB;
                positionReineB.x = CASE_LARG * l + X_MARGIN;
                positionReineB.y = CASE_LONG * m + Y_MARGIN;
                SDL_Surface *reineB = NULL;
                reineB = IMG_Load("Image/white_queen.png");
                changeCouleurFond(piece,ecran);
                SDL_BlitSurface(reineB, NULL, ecran, &positionReineB);
                }
            }break;
        case 'c' :
            {
                if(piece -> color == 2){
                SDL_Rect positionCavalierN ;
                positionCavalierN.x = CASE_LARG * l + X_MARGIN;
                positionCavalierN.y = CASE_LONG * m + Y_MARGIN;
                SDL_Surface *cavalierN = NULL ;
                cavalierN = IMG_Load("Image/black_knight.png");
                changeCouleurFond(piece,ecran);
                SDL_BlitSurface(cavalierN, NULL, ecran, &positionCavalierN);
                }
                else if(piece -> color == 1){
                SDL_Rect positionCavalierB; positionCavalierB.x = CASE_LARG * l + X_MARGIN; positionCavalierB.y = CASE_LONG * m + Y_MARGIN; SDL_Surface *cavalierB = NULL; cavalierB = IMG_Load("Image/white_knight.png"); SDL_BlitSurface(cavalierB, NULL, ecran, &positionCavalierB);
                }
            }break;
        case 'f' :
            {
                if(piece -> color == 2){
                SDL_Rect positionFouN ;
                positionFouN.x = CASE_LARG * l + X_MARGIN;
                positionFouN.y = CASE_LONG * m + Y_MARGIN;
                SDL_Surface *fouN = NULL ; fouN = IMG_Load("Image/black_bishop.png");
                changeCouleurFond(piece,ecran);
                SDL_BlitSurface(fouN, NULL, ecran, &positionFouN);
                }
                else if(piece -> color == 1){
                SDL_Rect positionFouB;
                positionFouB.x = CASE_LARG * l + X_MARGIN;
                positionFouB.y = CASE_LONG * m + Y_MARGIN;
                SDL_Surface *fouB = NULL; fouB = IMG_Load("Image/white_bishop.png");
                changeCouleurFond(piece,ecran);
                SDL_BlitSurface(fouB, NULL, ecran, &positionFouB);
                }
            }break;
        case 't' :
            {
                if(piece -> color == 2){
                SDL_Rect positionTourN ;
                positionTourN.x = CASE_LARG * l + X_MARGIN;
                positionTourN.y = CASE_LONG * m + Y_MARGIN;
                SDL_Surface *tourN = NULL ; tourN = IMG_Load("Image/black_rook.png");
                changeCouleurFond(piece,ecran);
                SDL_BlitSurface(tourN, NULL, ecran, &positionTourN);
                }
                else if(piece -> color == 1){
                SDL_Rect positionTourB; positionTourB.x = CASE_LARG * l + X_MARGIN;
                positionTourB.y = CASE_LONG * m + Y_MARGIN; SDL_Surface *tourB = NULL;
                tourB = IMG_Load("Image/white_rook.png");
                changeCouleurFond(piece,ecran);
                SDL_BlitSurface(tourB, NULL, ecran, &positionTourB);
                }
            }break;
        case 'p' :
        {
            if(piece -> color == 2){
                SDL_Rect positionPionN ;
                positionPionN.x = CASE_LARG * l + X_MARGIN;
                positionPionN.y = CASE_LONG * m + Y_MARGIN;
                SDL_Surface *pionN = NULL ; pionN = IMG_Load("Image/black_pawn.png");
                changeCouleurFond(piece,ecran);
                SDL_BlitSurface(pionN, NULL, ecran, &positionPionN);
                }
                else if(piece -> color == 1){
                SDL_Rect positionPionB; positionPionB.x = CASE_LARG * l + X_MARGIN;
                positionPionB.y = CASE_LONG * m + Y_MARGIN; SDL_Surface *pionB = NULL;
                pionB = IMG_Load("Image/white_pawn.png");
                changeCouleurFond(piece,ecran);
                SDL_BlitSurface(pionB, NULL, ecran, &positionPionB);
                }
        }break;
        case 'i' :
            {
                if(piece -> color == 2){
                SDL_Rect positionImperatriceN ;
                positionImperatriceN.x = CASE_LARG * l + X_MARGIN;
                positionImperatriceN.y = CASE_LONG * m + Y_MARGIN;
                SDL_Surface *imperatriceN = NULL ;
                imperatriceN = IMG_Load("Image/black_imperatrice.png");
                changeCouleurFond(piece,ecran);
                SDL_BlitSurface(imperatriceN, NULL, ecran, &positionImperatriceN);
                }
                else if(piece -> color == 1){
                SDL_Rect positionImperatriceB;
                positionImperatriceB.x = CASE_LARG * l + X_MARGIN;
                positionImperatriceB.y = CASE_LONG * m + Y_MARGIN;
                SDL_Surface *imperatriceB = NULL;
                imperatriceB = IMG_Load("Image/white_imperatrice.png");
                changeCouleurFond(piece,ecran);
                SDL_BlitSurface(imperatriceB, NULL, ecran, &positionImperatriceB);
                }
            }break;
        case 'x' :
            {
                if(piece -> color == 2){
                SDL_Rect positionPrincesseN ;
                 positionPrincesseN.x = CASE_LARG * l + X_MARGIN;
                 positionPrincesseN.y = CASE_LONG * m + Y_MARGIN;
                 SDL_Surface *princesseN = NULL ;
                 princesseN = IMG_Load("Image/black_princesse.png");
                changeCouleurFond(piece,ecran);
                 SDL_BlitSurface(princesseN, NULL, ecran, &positionPrincesseN);
                }
                else if(piece -> color == 1){
                SDL_Rect positionPrincesseB;
                positionPrincesseB.x = CASE_LARG * l + X_MARGIN;
                positionPrincesseB.y = CASE_LONG * m + Y_MARGIN;
                SDL_Surface *princesseB = NULL;
                princesseB = IMG_Load("Image/white_princesse.png");
                changeCouleurFond(piece,ecran);
                SDL_BlitSurface(princesseB, NULL, ecran, &positionPrincesseB);
                }
            }break;
            default:
              changeCouleurFond(piece,ecran);
            }
        }
    }
		SDL_Flip(ecran);
}

    void deselectMouvements(Piece piece,Grille plateau){
        int i;
        piece -> select = 0;
        for(i=0; i<piece -> deplacement -> nombre_element;i++){
            Coord coordMouv = piece -> deplacement -> mouvements[i];
            plateau -> pions[getIndice(coordMouv->x,coordMouv->y)]-> select = 0 ;
        }
    }

    void selectMouvements(Piece piece,Grille plateau){
        int i;
        for(i=0; i<piece -> deplacement -> nombre_element;i++){
            Coord coordMouv = piece -> deplacement -> mouvements[i];
            if(plateau -> pions[getIndice(coordMouv -> x, coordMouv -> y)] -> color != piece -> color && plateau -> pions[getIndice(coordMouv -> x, coordMouv -> y)] -> color != 0){
              plateau -> pions[getIndice(coordMouv->x,coordMouv->y)]-> select = 2;
            }else{
              plateau -> pions[getIndice(coordMouv->x,coordMouv->y)]-> select = 1;
            }
        }
    }

    Piece selectPiece(Grille plateau,Piece precedent){
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
                    coordClick = createCoord(event.button.y/CASE_LARG,event.button.x/CASE_LONG);
                    Piece pieceSelect = plateau -> pions[getIndice(coordClick -> x,coordClick -> y)];

                    if(pieceSelect -> select == 3){
                        pieceSelect -> select = 0;
                        deselectMouvements(pieceSelect,plateau);
                        printf("PIECE EST SELECT/ %d\n",pieceSelect -> select );
                        //return selectPiece(plateau,NULL);
                    }else{
                      if(pieceSelect -> select == 0){
                          pieceSelect -> select = 3;
                          selectMouvements(pieceSelect,plateau);
                          printf("PIECE EST SELECT/ %d\n",pieceSelect -> select );
                          return pieceSelect;

                      }
                      else{
                          deplacerPiece(plateau,precedent -> coord, pieceSelect -> coord);
                          deselectMouvements(precedent,plateau);
                      }
                    }
                    precedent = pieceSelect;
    				            continuer = 0;
                    }
              break;
      		    }
    	    }
          return NULL;
        }
