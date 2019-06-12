#define CASE_LARG 102
#define CASE_LONG 105
#define X_MARGIN 0
#define Y_MARGIN 0
#define LARGEUR 1020
#define LONGUEUR 840

void affichageGraphique(Grille plateau, SDL_Surface * ecran);

Piece selectPiece(Grille plateau,Piece precedent,int * quitter);
