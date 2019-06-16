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
	char type;
	Deplacement deplacement;
	int select;
} * Piece;

typedef struct grille_ {
	Piece * pions;
	Piece * mort;
	int nbMort;
	int tour;
} * Grille;

typedef struct Move_
{
	int indiceA;
	int indiceB;
	int value_piece;
	int points;
} * Move;

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

void initDeplacement(Grille grille);

void clearDeplacement(Grille grille);

void setDeplacement(Grille grille);

int echecMat(Grille grille);

int echec(Coord coord,Grille grille,int equipe);

Deplacement copyDeplacement(Deplacement origine);

Piece copyPiece(Piece piece);

Grille copyGrille(Grille origine);

int IA_jouer(Grille grille);

Piece trouverRoi(Grille grille,int equipe);

int roiPeutEtrePris(Piece piece,Coord coordArrive,Grille grille,int equipe);

void calc_moves(Grille g, int indice, int joueur, Move * moves, int * nbMoves, int * taille_max);

Coord coord_from_indice(int indice);

int calc_max_victim(Grille grille, int joueur_actu);

void promotion(Piece piece);

void freeGrille(Grille grille);

void freePiece(Piece piece);

void freeDeplacement(Deplacement deplacement);
