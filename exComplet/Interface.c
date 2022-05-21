#include "JoueursPerso.h"


void dialogues(Message* pLexique) {
	CodeErreur codeErreur = PAS_D_ERREUR;
	Joueur* pDebutJoueur = NULL;
	ChoixMenu choix = choixObtenu(pLexique,MENU_PRINCIPAL); 
	while (choix != QUITTER) {
		if (choix == CHARGER_JOUEURS_PERSONNAGES) {

		}
		if (choix == AJOUTER_JOUEUR_PERSONNAGES) {
			ajouterJoueurPersonnages(pLexique, &pDebutJoueur);
		}
		if (choix == AJOUTER_PERSONNAGE_PERSONNAGES) {
			ajouterPersonnage(pLexique, &pDebutJoueur);
		}
		if (choix == SUPPRIMER_JOUEUR) {
			supprimerJoueurPersonnages(pLexique, &pDebutJoueur); 
		}
		if (choix == AFFICHER_JOUEURS_PERSONNAGES) {
			afficherJoueursPersonnages(pLexique, pDebutJoueur);
			PAUSE;
		}
		if (choix == SAUVER_JOUEURS_PERSONNAGES) {

		}
		if (codeErreur != PAS_D_ERREUR) {
			afficherMessage(pLexique, NUM_DEB_MESSAGE_ERREUR + codeErreur);
			codeErreur = PAS_D_ERREUR;
		}
		choix = choixObtenu(pLexique, MENU_PRINCIPAL);
	}

}

ChoixMenu choixObtenu(Message* pLexique, NumMessage numero) { 
	ChoixMenu choix;
	bool choixValide;
	do {
		int maxChoix = afficherMenu(pLexique,numero);
		afficherMessage(pLexique, OBT_CHOIX);
		scanf_s("%d", &choix); 
		choixValide = choix >= 1 && choix <= maxChoix; 
		if (!choixValide) {
			afficherMessage(pLexique, NUM_DEB_MESSAGE_ERREUR + MAUVAIS_CHOIX);
		}
	} while (!choixValide);
	return choix;
}

CodeErreur chargerJoueursPersonnages(Message* pLexique, Joueur** pDebJoueurs) {
	CodeErreur codeErreur = PAS_D_ERREUR; 

	return codeErreur;
}

CodeErreur ajouterJoueurPersonnages(Message* pLexique, Joueur** pDebJoueurs) {
	Joueur* pNouvJoueur = NULL;
	Personnage* pNouvPerso = NULL;  
	CodeErreur codeErreur;
	char pseudo[TPSEUDO];
	int reponse;
	bool allocationOk = nouveauJoueur(&pNouvJoueur); 
	bool allocationPerso;
	if (!allocationOk) {
		codeErreur = ALLOCATION_MEMOIRE;
	} 
	else {
		codeErreur = PAS_D_ERREUR;
		afficherTitre(pLexique, TITRE_PERSO_AJOUT);
		pseudoObtenu(pLexique,pseudo);   
		Joueur* pJoueurs = NULL; 
		Joueur* pSauvJoueurs = NULL; 
		bool joueursExiste = joueurExiste(*pDebJoueurs,pseudo,&pJoueurs,&pSauvJoueurs);  
		if (joueursExiste) {
			codeErreur = JOUEUR_DEJA_PRESENT;
			libererJoueur(pNouvJoueur);   
		}
		else {
			ajouteJoueur(pDebJoueurs, pseudo, pNouvJoueur, pJoueurs, pSauvJoueurs); 
			do {
				allocationPerso = nouveauPersonnage(&pNouvPerso);
				if (!allocationPerso) {
					codeErreur = ALLOCATION_MEMOIRE;
				} 
				else {
					ajouterPersonnageAJoueur(pLexique,pDebJoueurs, &pNouvJoueur, &pNouvPerso);
					if (codeErreur == PAS_D_ERREUR) {
						reponse = reponseObtenu(pLexique, OBT_ENCORE); 
					}
				}
			} while (allocationPerso && codeErreur == PAS_D_ERREUR && reponse == OUI);

		}
	}
	return codeErreur;
}

CodeErreur ajouterPersonnageAJoueur(Message* pLexique,Joueur** pDebJoueur,Joueur** pJoueur,Personnage** pNouvPerso) {  
	CodeErreur codeErreur = PAS_D_ERREUR;
	char nom[TNOM];
	nomObtenu(pLexique, nom);
	bool persoExiste = personnageExiste(*pDebJoueur, nom);
	if (persoExiste) {
		codeErreur = PERSONNAGE_DEJA_PRESENT;
		libererPersonnage(*pNouvPerso); 
	} 
	else {
		int nbPerso = nbPersonnages(*pJoueur);
		if (nbPerso < NBMAXPERSO) {
			int nbPoints = pointsObtenus(pLexique);
			ajoutePersonnage(*pJoueur, nom, nbPoints,*pNouvPerso); 
		}
		else {
			codeErreur = NB_MAX_PERSO_ATTEINT;
		}
	}
	return codeErreur; 
}

CodeErreur ajouterPersonnage(Message* pLexique, Joueur** pDebJoueur) {
	Joueur* pJoueur = *pDebJoueur;
	Joueur* pSauvJoueur = NULL;
	Personnage* pNouvPerso = NULL; 
	CodeErreur codeErreur; 
	char pseudo[TPSEUDO];
	bool allocationPerso = nouveauPersonnage(&pNouvPerso);
	if (!allocationPerso) {
		codeErreur = ALLOCATION_MEMOIRE;
	}
	else {
		codeErreur = PAS_D_ERREUR;
		afficherTitre(pLexique, TITRE_PERSO_AJOUT);
		pseudoObtenu(pLexique, pseudo);
		bool jExiste = joueurExiste(*pDebJoueur, pseudo, &pJoueur, &pSauvJoueur);  
		if (!jExiste) {
			codeErreur = JOUEUR_ABSENT;
			libererPersonnage(pNouvPerso); 
		}
		else { 
			ajouterPersonnageAJoueur(pLexique, pDebJoueur, &pJoueur, &pNouvPerso); 
			
		}
	}
	return codeErreur;
}

CodeErreur supprimerJoueurPersonnages(Message* pLexique,Joueur** pDebJoueur) {
	CodeErreur codeErreur;
	Joueur* pJoueur = NULL;
	Joueur* pSauvJoueur = NULL; 
	char pseudo[TPSEUDO];
	afficherTitre(pLexique, TITRE_JOUEUR_ANNUL);
	pseudoObtenu(pLexique, pseudo); 
	bool jouExiste = joueurExiste(*pDebJoueur, pseudo, &pJoueur, &pSauvJoueur);
	if (!jouExiste) { 
		codeErreur = JOUEUR_ABSENT;
	}
	else {
		codeErreur = PAS_D_ERREUR;
		supprimeJoueur(pDebJoueur,pJoueur,pSauvJoueur); 
	}
	return codeErreur;
}

void afficherJoueursPersonnages(Message* pLexique, Joueur* pDebJoueurs) {
	if (pDebJoueurs == NULL) {
		afficherMessage(pLexique, AUCUN_JOUEUR);
	}
	else {
		afficherTitre(pLexique, TITRE_LISTE_JOUEURS);
		listeJoueurs(pDebJoueurs); 
	}
}

void nomObtenu(Message* pLexique, char nom[]) {
	bool nomValide;
	do {
		afficherMessage(pLexique, OBT_NOM);
		gets_s(nom, TNOM);
		nomValide = isalpha(nom[0]);
		if (!nomValide) {
			afficherMessage(pLexique, NUM_DEB_MESSAGE_ERREUR + NOM_NON_VALIDE);
		}
	} while (!nomValide);
}

int reponseObtenu(Message* pLexique,NumMessage message) {
	int reponse;
	bool reponseValide;
	do {
		getchar();
		afficherMessage(pLexique, message);
		scanf_s("%d", &reponse);
		reponseValide = reponse > 0 && reponse < 3;
		if (!reponseValide) {
			afficherMessage(pLexique, NUM_DEB_MESSAGE_ERREUR + REPONSE_NON_VALIDE);
		}
	} while (!reponseValide);
	return reponse;
}

int pointsObtenus(Message* pLexique) {
	int points;
	bool pointsValide;
	do {
		afficherMessage(pLexique, OBT_POINTS);
		scanf_s("%d", &points);
		pointsValide = points >= 1;
		if (!pointsValide) {
			afficherMessage(pLexique, NUM_DEB_MESSAGE_ERREUR + POINTS_NON_VALIDES);
		}
	} while (!pointsValide);
	return points; 
}

void pseudoObtenu(Message* pLexique, char pseudo[]) {
	bool pseudoValide; 
	getchar();
	do {
		afficherMessage(pLexique, OBT_PSEUDO);
		gets_s(pseudo,TPSEUDO); 
		pseudoValide = strlen(pseudo) > 1 && isupper(pseudo[0]);
		if (!pseudoValide) {
			afficherMessage(pLexique, NUM_DEB_MESSAGE_ERREUR + PSEUDO_NON_VALIDE);
		}
	} while (!pseudoValide);
} 