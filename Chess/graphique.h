#define CASE_LARG 102
#define CASE_LONG 105
#define Y_MARGIN 60
#define X_MARGIN 315
#define LARGEUR 1680
#define LONGUEUR 1050

void affichageGraphique(Grille plateau, SDL_Surface * ecran);

Piece selectPiece(Grille plateau,Piece precedent,int * quitter);
