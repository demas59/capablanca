typedef struct deplacement_ {
	int deplace;
	Coord * mouvements;
	int taille_max;
	int nombre_element;
} * Deplacement;

Deplacement createDeplacement();

void initDeplacement(Grille grille);

void clearDeplacement(Grille grille);

void setDeplacement(Grille grille);

Deplacement copyDeplacement(Deplacement origine);

void freeDeplacement(Deplacement deplacement);

void proposerDeplacer(Grille grille,Piece piece);