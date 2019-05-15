typedef struct coord_ {
	int x;
	int y;
} * Coord;

typedef struct piece_ {
	int color;
	Coord coord;
	int actif;
	char type;
	int deplace;
} * Piece;

typedef struct grille_ {
	Piece * pions;
	Piece * mort;
	int nbMort;
	int tour;
} * Grille;

void affichage(Grille grille);

Grille initialisation();

Coord createCoord(int x, int y);

Piece createPiece(int color, int x, int y, char type);

int jouer(Grille grille);

Piece choosePawn(Grille grille);

Coord * proposerDeplacer(Grille grille,Piece piece,int * taille_max,int * nombre_element,Coord * deplacement);

Coord chooseMove(Coord * moves);

void movePawn(Grille grille, Coord depart, Coord fin);

int getIndice(int i, int j);

void mouvTour(Grille grille,Piece piece,Coord * coords, int * taille_max, int * nombre_element);

void mouvPion(Grille grille,Piece piece,Coord * coords, int * taille_max, int * nombre_element);

void ajoutCoord(Coord * coords,Coord coord,int * taille_max,int * nombre_element);

void placerPiece(Grille grille,Piece piece);

void mouvCavalier(Grille grille,Piece piece,Coord * coords, int * taille_max, int * nombre_element);

void mouvFou(Grille grille,Piece piece,Coord * coords, int * taille_max, int * nombre_element);

void parcoursCoord(Coord * coords,int nombre_element);

Coord choixCoord(Coord * coords, int nombre_element);

void deplacerPiece(Grille grille,Coord coordDepart, Coord coordFin);