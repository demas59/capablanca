#define CASE_LARG 102
#define CASE_LONG 105
#define Y_MARGIN 110
#define X_MARGIN 315
#define LARGEUR 1680
#define LONGUEUR 1050

void affichageGraphique(Grille plateau, SDL_Surface * ecran);

Piece selectPiece(Grille plateau,Piece precedent,int * quitter);

void joueurVsIA(SDL_Surface * ecran);

void joueurVsJoueur(SDL_Surface * ecran);

void iaVsIa(SDL_Surface * ecran);

void promotion(Piece piece);
