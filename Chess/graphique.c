#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../struct.h"
#include "graphique.h"

void changeCouleurFond(Piece piece,SDL_Surface * ecran ){
    SDL_Surface * rectangle = NULL;
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, CASE_LARG - 2, CASE_LONG - 2, 32, 0, 0, 0, 0);
    SDL_Rect position;
    position.x = piece -> coord -> y * CASE_LARG + 1 + X_MARGIN;
    position.y = piece -> coord -> x * CASE_LONG + 1 + Y_MARGIN;

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

//Fonction d'affichage graphique du plateau
void affichageGraphique(Grille plateau, SDL_Surface * ecran){

  SDL_Surface * echiquier = NULL;
  SDL_Rect posinit;
  echiquier = IMG_Load("echiquier.png");
  posinit.x = X_MARGIN;
  posinit.y = Y_MARGIN;
  SDL_BlitSurface(echiquier,NULL,ecran,&posinit);
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
              }
              changeCouleurFond(piece,ecran);
              if(piece->type != ' '){
              SDL_BlitSurface(imagePiece, NULL, ecran, &posPiece);
              SDL_FreeSurface(ecran); /* On lib�re la surface */
            }

        }
    }
		SDL_Flip(ecran);
}

    // deselection des pieces lorsqu'un clic a eu lieu sur la precedente, ou que le déplacement a été fait
    void deselectMouvements(Piece piece,Grille plateau){
        int i;
        piece -> select = 0;
        for(i=0; i<piece -> deplacement -> nombre_element;i++){
            Coord coordMouv = piece -> deplacement -> mouvements[i];
            plateau -> pions[getIndice(coordMouv->x,coordMouv->y)]-> select = 0 ;
        }
    }

    //selectionne une piece et les coordonnees disponible une fois le clic réalisé
    void selectMouvements(Piece piece,Grille plateau){
        int i;
        for(i=0; i<piece -> deplacement -> nombre_element;i++){
            Coord coordMouv = piece -> deplacement -> mouvements[i];
            //Si la case cliquée est vide affichera la case en vert, sinon en rouge
            if(plateau -> pions[getIndice(coordMouv -> x, coordMouv -> y)] -> color != piece -> color && plateau -> pions[getIndice(coordMouv -> x, coordMouv -> y)] -> color != 0){
              plateau -> pions[getIndice(coordMouv->x,coordMouv->y)]-> select = 2;
            }else{
              plateau -> pions[getIndice(coordMouv->x,coordMouv->y)]-> select = 1;
            }
        }
    }

    //transforme un pion en reine une fois arrivé au bout du plateau
    void promotion(Piece piece){
        if(piece -> color == 1 && piece -> coord -> x == 7){
          piece -> type = 'q';
        }
        if(piece -> color == 2 && piece -> coord -> x == 0){
          piece -> type = 'q';
        }
    }

    Piece selectPiece(Grille plateau,Piece precedent,int * quitter){
        SDL_Event event;
        Coord coordClick;
        int continuer = 1;
        while(continuer){
            SDL_WaitEvent(&event);
            switch(event.type)
        {
            case SDL_QUIT:
                printf("FERMER\n" );
                continuer = 0;
                * quitter = 0;
                return createPiece(0,0,0,' ');
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT){ /* Si on fait un clique gauche, on lance l'instruction*/
                    coordClick = createCoord((event.button.y-Y_MARGIN)/CASE_LONG,(event.button.x-X_MARGIN)/CASE_LARG);
                    Piece pieceSelect = plateau -> pions[getIndice(coordClick -> x,coordClick -> y)];

                    if((pieceSelect -> type == ' ' && pieceSelect -> select == 0) ||(pieceSelect -> color != plateau -> tour % 2 + 1 && precedent == NULL)){
                      break;
                    }

                    //si la case cliquée est déjà cliquée, la désélectionne
                    if(pieceSelect -> select == 3){
                        pieceSelect -> select = 0;
                        deselectMouvements(pieceSelect,plateau);
                    }else{

                        //Si la piece selectionné est une case non selectionnée et qu'il n'y a une piece selectionnée précedemment arrete la fonction
                      if(pieceSelect -> select == 0 && precedent != NULL){
                        break;
                      }
                      //Si la case n'était pas séléctionnée avant la séléctionne
                      if(pieceSelect -> select == 0){
                          pieceSelect -> select = 3;
                          selectMouvements(pieceSelect,plateau);
                          return pieceSelect;
                      }
                      else{
                            int seraEnEchec = roiPeutEtrePris(precedent,pieceSelect -> coord,plateau,plateau -> tour % 2 + 1);
                            if(seraEnEchec == 1){
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
