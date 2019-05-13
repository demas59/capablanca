typedef struct coord_ {
	int x;
	int y;
} * Coord;

typedef struct piece_ {
	int color;
	Coord coord;
	int actif;
	int type;
} * Piece;

typedef struct grille_ {
	Piece ** pions;
	Piece * mort;
} * Grille;

