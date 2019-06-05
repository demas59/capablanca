#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct.h"
#include "graphique.h"


void affichageGraphique(Grille plateau, SDL_Surface * ecran){
	int m ; int l;
    for (m = 0; m < 8 ; m++){
        for(l=0; l < 10; l++){
            switch (plateau -> pions[getIndice(m,l)] -> type){
        case 'k' :
            {
                if(plateau -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionRoiN; positionRoiN.x = CASE_LARG * l; 
                positionRoiN.y = CASE_LONG * m; 
                SDL_Surface *roiN = NULL; 
                roiN = IMG_Load("Image/black_king.png"); 
                
                SDL_BlitSurface(roiN, NULL, ecran, &positionRoiN);
                }
                else if(plateau -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionRoiB; positionRoiB.x = CASE_LARG * l; positionRoiB.y = CASE_LONG * m; SDL_Surface *roiB = NULL; roiB = IMG_Load("Image/white_king.png"); SDL_BlitSurface(roiB, NULL, ecran, &positionRoiB);
                }
            }break;
        case 'q' :
            {
                if(plateau -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionReineN ; positionReineN.x = CASE_LARG * l; positionReineN.y = CASE_LONG * m; SDL_Surface *reineN = NULL; reineN = IMG_Load("Image/black_queen.png"); SDL_BlitSurface(reineN, NULL, ecran, &positionReineN);
                }
                else if(plateau -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionReineB; positionReineB.x = CASE_LARG * l; positionReineB.y = CASE_LONG * m; SDL_Surface *reineB = NULL; reineB = IMG_Load("Image/white_queen.png"); SDL_BlitSurface(reineB, NULL, ecran, &positionReineB);
                }
            }break;
        case 'c' :
            {
                if(plateau -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionCavalierN ; positionCavalierN.x = CASE_LARG * l; positionCavalierN.y = CASE_LONG * m; SDL_Surface *cavalierN = NULL ; cavalierN = IMG_Load("Image/black_knight.png"); SDL_BlitSurface(cavalierN, NULL, ecran, &positionCavalierN);
                }
                else if(plateau -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionCavalierB; positionCavalierB.x = CASE_LARG * l; positionCavalierB.y = CASE_LONG * m; SDL_Surface *cavalierB = NULL; cavalierB = IMG_Load("Image/white_knight.png"); SDL_BlitSurface(cavalierB, NULL, ecran, &positionCavalierB);
                }
            }break;
        case 'f' :
            {
                if(plateau -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionFouN ; positionFouN.x = CASE_LARG*l; positionFouN.y = CASE_LONG*m; SDL_Surface *fouN = NULL ; fouN = IMG_Load("Image/black_bishop.png"); SDL_BlitSurface(fouN, NULL, ecran, &positionFouN);
                }
                else if(plateau -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionFouB; positionFouB.x = CASE_LARG * l; positionFouB.y = CASE_LONG * m; SDL_Surface *fouB = NULL; fouB = IMG_Load("Image/white_bishop.png"); SDL_BlitSurface(fouB, NULL, ecran, &positionFouB);
                }
            }break;
        case 't' :
            {
                if(plateau -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionTourN ; positionTourN.x = CASE_LARG*l; positionTourN.y = CASE_LONG*m; SDL_Surface *tourN = NULL ; tourN = IMG_Load("Image/black_rook.png"); SDL_BlitSurface(tourN, NULL, ecran, &positionTourN);
                }
                else if(plateau -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionTourB; positionTourB.x = CASE_LARG * l; positionTourB.y = CASE_LONG * m; SDL_Surface *tourB = NULL; tourB = IMG_Load("Image/white_rook.png"); SDL_BlitSurface(tourB, NULL, ecran, &positionTourB);
                }
            }break;
        case 'p' :
        {
            if(plateau -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionPionN ; positionPionN.x = CASE_LARG*l; positionPionN.y = CASE_LONG*m; SDL_Surface *pionN = NULL ; pionN = IMG_Load("Image/black_pawn.png"); SDL_BlitSurface(pionN, NULL, ecran, &positionPionN);
                }
                else if(plateau -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionPionB; positionPionB.x = CASE_LARG * l; positionPionB.y = CASE_LONG * m; SDL_Surface *pionB = NULL; pionB = IMG_Load("Image/white_pawn.png"); SDL_BlitSurface(pionB, NULL, ecran, &positionPionB);
                }
        }break;
        case 'i' :
            {
                if(plateau -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionImperatriceN ; positionImperatriceN.x = CASE_LARG*l; positionImperatriceN.y = CASE_LONG*m; SDL_Surface *imperatriceN = NULL ; imperatriceN = IMG_Load("Image/black_imperatrice.png"); SDL_BlitSurface(imperatriceN, NULL, ecran, &positionImperatriceN);
                }
                else if(plateau -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionImperatriceB; positionImperatriceB.x = CASE_LARG * l; positionImperatriceB.y = CASE_LONG * m; SDL_Surface *imperatriceB = NULL; imperatriceB = IMG_Load("Image/white_imperatrice.png"); SDL_BlitSurface(imperatriceB, NULL, ecran, &positionImperatriceB);
                }
            }break;
        case 'x' :
            {
                if(plateau -> pions[getIndice(m,l)] -> color == 2){
                SDL_Rect positionPrincesseN ; positionPrincesseN.x = CASE_LARG*l; positionPrincesseN.y = CASE_LONG*m; SDL_Surface *princesseN = NULL ; princesseN = IMG_Load("Image/black_princesse.png"); SDL_BlitSurface(princesseN, NULL, ecran, &positionPrincesseN);
                }
                else if(plateau -> pions[getIndice(m,l)] -> color == 1){
                SDL_Rect positionPrincesseB; positionPrincesseB.x = CASE_LARG * l; positionPrincesseB.y = CASE_LONG * m; SDL_Surface *princesseB = NULL; princesseB = IMG_Load("Image/white_princesse.png"); SDL_BlitSurface(princesseB, NULL, ecran, &positionPrincesseB);
                }
            }break;
            }
        }
    }
}