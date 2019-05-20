typedef struct coord_ {
	int x;
	int y;
} * Coord;

typedef struct deplacement_ {
	int deplace;
	Coord * mouvements;
	int taille_max;
	int nombre_element;
} * Deplacement;

typedef struct piece_ {
	int color;
	Coord coord;
	int actif;
	char type;
	Deplacement deplacement;
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

Deplacement createDeplacement();

int jouer(Grille grille);

Piece choosePawn(Grille grille);

void proposerDeplacer(Grille grille,Piece piece);

Coord chooseMove(Coord * moves);

void movePawn(Grille grille, Coord depart, Coord fin);

int getIndice(int i, int j);

void mouvTour(Grille grille,Piece piece);

void mouvPion(Grille grille,Piece piece);

void ajoutCoord(Coord coord,Piece piece);

void placerPiece(Grille grille,Piece piece);

void mouvCavalier(Grille grille,Piece piece);

void mouvFou(Grille grille,Piece piece);

void mouvRoi(Grille grille,Piece piece);

void parcoursCoord(Coord * coords,int nombre_element);

Coord choixCoord(Coord * coords, int nombre_element);

void deplacerPiece(Grille grille,Coord coordDepart, Coord coordFin);

void clearDeplacement(Grille grille);

void setDeplacement(Grille grille);

int echec(Grille grille);
