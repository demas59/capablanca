typedef struct piece_ {
	int color;
	Coord coord;
	char type;
	Deplacement deplacement;
	int select;
} * Piece;

Piece createPiece(int color, int x, int y, char type);

void mouvTour(Grille grille,Piece piece);

void mouvPion(Grille grille,Piece piece);

void mouvCavalier(Grille grille,Piece piece);

void mouvFou(Grille grille,Piece piece);

void mouvRoi(Grille grille,Piece piece);

void placerPiece(Grille grille,Piece piece);

Piece copyPiece(Piece origine);

void freePiece(Piece piece);