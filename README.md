main
	while(!echec_et_mat)
		jouer()
		tour++


jouer
	demandeCase()
	si null: jouer(); close;
	proposerDeplacements()
	choisirDeplacement()
	deplacerPiece
	

demandeCase()
	demande
	checkcase
	oui: retourn coords
	non: retourne null

proposerDeplacement()
	regarde selon piece et case possibilités
	renvoie tab coords

choisirDeplacement()
	demande
	checkPossible
	oui: retourne coords
	non: retourne null