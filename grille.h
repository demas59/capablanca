typedef struct grille_ {
	Piece * pions;
	Piece * mort;
	int nbMort;
	int tour;
} * Grille;

typedef struct coord_ {
	int x;
	int y;
} * Coord;

Grille createGrille();

void setColor(int i,int j,Piece * pieces);

void setType(int i,int j, Piece * pieces);

Grille initialisation();

void affichage(Grille grille);

void deplacerPiece(Grille grille,Coord coordDepart, Coord coordFin);

Grille copyGrille(Grille origine);

void freeGrille(Grille grille);

void ajoutCoord(Coord coord,Piece piece);

int getIndice(int i, int j);

Coord createCoord(int x, int y);