#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../piece.h"
#include "../grille.h"
#include "../deplacement.h"
#include "../game.h"
#include "graphique.h"

//Fonction permettant de changer la couleur des cases séléctionnées
void changeCouleurFond(Piece piece,SDL_Surface * ecran ){

    //initialisation du carré qui sera affiché sous la piece
    SDL_Surface * rectangle = NULL;
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, CASE_LARG - 2, CASE_LONG - 2, 32, 0, 0, 0, 0);
    SDL_Rect position;
    position.x = piece -> coord -> y * CASE_LARG + 1 + X_MARGIN;
    position.y = piece -> coord -> x * CASE_LONG + 1 + Y_MARGIN;

        //détermine la couleur du rectangle en fonction de l'état de séléction de la piece
		if(piece -> select == 1){
			SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format,  50, 200, 50));
            SDL_SetAlpha(rectangle, SDL_SRCALPHA, 128);
			SDL_BlitSurface(rectangle, NULL, ecran, &position);
		}
		if(piece -> select == 2){
			SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format,  255,0,0));
            SDL_SetAlpha(rectangle, SDL_SRCALPHA, 128);
			SDL_BlitSurface(rectangle, NULL, ecran, &position);
		}
        if(piece -> select == 3){
            SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format,  70,130,180));
            SDL_SetAlpha(rectangle, SDL_SRCALPHA, 128);
            SDL_BlitSurface(rectangle, NULL, ecran, &position);
        }
}

//Fonction d'affichage graphique du plateau
void affichageGraphique(Grille plateau, SDL_Surface * ecran){

    SDL_Surface * fond = NULL;
    fond = IMG_Load("echiquier.png");
    SDL_Rect posinit;
    posinit.x = X_MARGIN;
    posinit.y = Y_MARGIN;
    SDL_BlitSurface(fond,NULL,ecran,&posinit);

    int m ; int l;
    for (m = 0; m < 8 ; m++){
        for(l=0; l < 10; l++){

            Piece piece = plateau -> pions[getIndice(m,l)] ;

            SDL_Rect posPiece;
            posPiece.x = CASE_LARG * l + X_MARGIN;
            posPiece.y = CASE_LONG * m + Y_MARGIN;

            SDL_Surface * imagePiece = NULL;

            switch (piece -> type){
            case 'k' :
                    if(piece -> color == 2){
                        imagePiece = IMG_Load("Image/black_king.png");
                    }
                    else if(piece -> color == 1){
                        imagePiece = IMG_Load("Image/white_king.png");
                    }   
                    break;
            case 'q' :
                    if(piece -> color == 2){
                        imagePiece = IMG_Load("Image/black_queen.png");
                    }
                    else if(piece -> color == 1){
                        imagePiece = IMG_Load("Image/white_queen.png");
                    }
                    break;
            case 'c' :
                    if(piece -> color == 2){
                    imagePiece = IMG_Load("Image/black_knight.png");
                    }
                    else if(piece -> color == 1){
                    imagePiece = IMG_Load("Image/white_knight.png");
                    }
                    break;
            case 'f' :
                    if(piece -> color == 2){
                        imagePiece = IMG_Load("Image/black_bishop.png");
                    }
                    else if(piece -> color == 1){
                        imagePiece = IMG_Load("Image/white_bishop.png");
                    }
                    break;
            case 't' :
                    if(piece -> color == 2){
                        imagePiece = IMG_Load("Image/black_rook.png");
                    }
                    else if(piece -> color == 1){
                    imagePiece = IMG_Load("Image/white_rook.png");
                    }
                    break;
            case 'p' :
                    if(piece -> color == 2){
                        imagePiece = IMG_Load("Image/black_pawn.png");
                    }
                    else if(piece -> color == 1){
                        imagePiece = IMG_Load("Image/white_pawn.png");
                    }
                    break;
            case 'i' :
                    if(piece -> color == 2){
                        imagePiece = IMG_Load("Image/black_imperatrice.png");
                    }
                    else if(piece -> color == 1){
                        imagePiece= IMG_Load("Image/white_imperatrice.png");
                   }
                    break;
            case 'x' :
                    if(piece -> color == 2){
                    imagePiece = IMG_Load("Image/black_princesse.png");
                    }
                    else if(piece -> color == 1){
                    imagePiece = IMG_Load("Image/white_princesse.png");
                    }
                    break;
            default:
                    changeCouleurFond(piece,ecran);
            }
            changeCouleurFond(piece,ecran);
            SDL_BlitSurface(imagePiece, NULL, ecran, &positionRoiN);
        }
    }
		SDL_Flip(ecran);
}

/*Permet de désafficher les différents mouvements que peut réaliser une piece sur le plateau*/
void deselectMouvements(Piece piece,Grille plateau){
    int i;
    piece -> select = 0;
    for(i=0; i<piece -> deplacement -> nombre_element;i++){
        Coord coordMouv = piece -> deplacement -> mouvements[i];
        plateau -> pions[getIndice(coordMouv->x,coordMouv->y)]-> select = 0 ;
    }
}

/*Permet d'afficher les différents mouvements que peut réaliser une piece sur le plateau*/
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

/*Fonction permettant de promouvoir un pion une fois qu'il atteint le bout du plateau*/
void promotion(Piece piece){
    if(piece -> color == 1 && piece -> coord -> x == 7){
        piece -> type = 'q';
    }
    if(piece -> color == 2 && piece -> coord -> x == 0){
        piece -> type = 'q';
    }
}

/*Fonction de séléction de pièce par le joueur ou de fermeture de la fenètre de jeu */
Piece selectPiece(Grille plateau,Piece precedent,int * quitter){
    SDL_Event event;
    Coord coordClick;
    int continuer = 1;

    while(continuer){

        SDL_WaitEvent(&event);

        switch(event.type){
            case SDL_QUIT:
                printf("FERMER\n" );
                continuer = 0;
                * quitter = 0;
                return createPiece(0,0,0,' ');
                break;

            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT){ /* Si on fait un clique gauche, on lance l'instruction*/

                    coordClick = createCoord((event.button.y-Y_MARGIN)/CASE_LONG,(event.button.x-X_MARGIN)/CASE_LARG); // récupère la coordonnée du clic
                    Piece pieceSelect = plateau -> pions[getIndice(coordClick -> x,coordClick -> y)];

                    /*Si la case cliquée est différentes du joueur et qu'il n'y a pas eut de piece selectionnée avant, quitte la fonction*/

                    //if((pieceSelect -> type == ' ' && pieceSelect -> select == 0) ||(pieceSelect -> color != plateau -> tour % 2 + 1 && precedent == NULL)){
                    if(pieceSelect -> color != plateau -> tour % 2 + 1 && precedent == NULL){
                      break;
                    }

                    // Si la pièce cliquée était déjà séléctionnée, la déselectionne
                    if(pieceSelect -> select == 3){
                        pieceSelect -> select = 0;
                        deselectMouvements(pieceSelect,plateau);
                    }else{

                        //Si la case séléctionné est vide et n'est pas un mouvement possible, quitte la fonction
                        if(pieceSelect -> select == 0 && precedent != NULL){
                            break;
                        }

                        //Si la case séléctionnée est vide mais correspond au pion du joueur, la selectionne!
                        if(pieceSelect -> select == 0){
                            pieceSelect -> select = 3;
                            selectMouvements(pieceSelect,plateau);
                            return pieceSelect;
                        }
                        else{

                            // Si la case selectionnée est un deplacement possible du joueur, vérifie que le deplacement ne mettrais pas le roi du joueur en echec, puis la déplace
                            int seraEnEchec = roiPeutEtrePris(precedent,pieceSelect -> coord,plateau,plateau -> tour % 2 + 1);
                            if(seraEnEchec == 1){
                                plateau -> pions[pieceSelect->coord->x,pieceSelect->coord->y] -> select = 0;
                                printf("IMPOSSIBLE CELA VOUS METTEREZ EN ECHEC CHOISISSEZ UNE AUTRE POSITION\n");
                                break;
                            }
                            deplacerPiece(plateau,precedent -> coord, pieceSelect -> coord);
                            deselectMouvements(precedent,plateau);
                            return precedent;
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
