typedef struct Move_
{
	int indiceA;
	int indiceB;
	int value_piece;
	int points;
} * Move;

void ajout_move(Move * moves, int * nbr_elements, int * taille_max, Move m);
int get_importance_piece(Piece p);
Move create_move(int ia, int ib, int value_piece, int points);
int calc_max_victim(Grille grille, int joueur_actu);