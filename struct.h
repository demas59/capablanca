typedef struct coord_ {
	int x;
	int y;
} * Coord;

typedef struct piece_ {
	int color;
	Coord coord;
	int actif;
	char type;
} * Piece;

typedef struct grille_ {
	Piece * pions;
	Piece mort;
} * Grille;

void affichage(Grille grille);

Grille initialisation();

Coord createCoord(int x, int y);

Piece createPiece(int color, int x, int y, int type);