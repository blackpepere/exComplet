#include "JoueursPerso.h"

bool nouveauJoueur(Joueur** pNouvJoueur) {
	*pNouvJoueur = (Joueur*)malloc(sizeof(*pNouvJoueur));
	return *pNouvJoueur != NULL;
}

bool joueurExiste(Joueur* pDebJoueurs, char pseudo[], Joueur** pJoueurs, Joueur** pSauvJoueur) {
	*pJoueurs = pDebJoueurs;
	while (*pJoueurs != NULL && strcmp(pseudo,(*pJoueurs)->pseudo) > 0 ){
		*pSauvJoueur = *pJoueurs;
		*pJoueurs = (*pJoueurs)->pSuiv;
	}
	return *pJoueurs != NULL && strcmp(pseudo, (*pJoueurs)->pseudo) == 0;
}

bool personnageExiste(Joueur* pDebJoueurs,char nom[]) {
	Joueur* pJoueur = pDebJoueurs;
	Personnage* pPerso = NULL;
	bool existe = false;
	while (pJoueur != NULL && !existe) {
		pPerso = pJoueur->pDebutPerso;
		while (pPerso != NULL && strcmp(nom,pPerso->nom) > 0){  
			pPerso = pPerso->pSuiv;
		}
		existe = pPerso != NULL && strcmp(nom, pPerso->nom) == 0;
		pJoueur = pJoueur->pSuiv;
	}
	return existe;
}

void ajouteJoueur(Joueur** pDebJoueur, char pseudo[], Joueur* pNouvJoueur, Joueur* pJoueur, Joueur* pSauvJoueur) {
	strcpy_s(pNouvJoueur->pseudo,TPSEUDO, pseudo); 
	pNouvJoueur->pDebutPerso = NULL;
	if (pJoueur == *pDebJoueur) {
		*pDebJoueur = pNouvJoueur;
	}
	else {
		pSauvJoueur->pSuiv = pNouvJoueur;
	}
	pNouvJoueur->pSuiv = pJoueur;
}

void ajoutePersonnage(Joueur* pJoueur,char nom[], int nbPoints, Personnage* pPerso) {
	strcpy_s(pPerso->nom,TNOM,nom);
	pPerso->points = nbPoints;
	pPerso->pSuiv = pJoueur->pDebutPerso;

	pJoueur->pDebutPerso = pPerso;
}

int nbPersonnages(Joueur* pJoueur) {
	Personnage* pPerso = pJoueur->pDebutPerso;
	int nbPersonnage = 0; 
	while (pPerso != NULL) {
		pPerso = pPerso->pSuiv;
		nbPersonnage++; 
	}
	return nbPersonnage; 
}

bool nouveauPersonnage(Personnage** pNouvPerso) {
	*pNouvPerso = (Personnage*)malloc(sizeof(*pNouvPerso));
	return *pNouvPerso != NULL;
}

void libererJoueur(Joueur* pJoueur) {
	free(pJoueur);
}

void libererPersonnage(Personnage* pPerso) {
	free(pPerso);
}

void supprimeJoueur(Joueur** pDebJoueur, Joueur* pJoueur, Joueur* pSauvJoueur) {
	Personnage* pPerso = pJoueur->pDebutPerso; 
	Personnage* pSauvPerso = NULL;
	while (pPerso != NULL)
	{
		pSauvPerso = pPerso->pSuiv; 
		libererPersonnage(pPerso); 
		pPerso = pSauvPerso;  
	} 
	if (pJoueur == *pDebJoueur) {
		*pDebJoueur = pJoueur->pSuiv;
	}
	else {
		pSauvJoueur->pSuiv = pJoueur->pSuiv;
	}
	libererJoueur(pJoueur);
}

void listeJoueurs(Joueur* pDebJoueur) {
	Joueur* pJoueur = pDebJoueur;
	while (pJoueur != NULL) {
		puts(pJoueur->pseudo);
		int nbPersonnage = nbPersonnages(pJoueur); 
		Personnage* pPerso = pJoueur->pDebutPerso; 
		for (int i = 0; i < nbPersonnage; i++) {
			puts(pPerso->nom);
			pPerso = pPerso->pSuiv;
		}
		pJoueur = pJoueur->pSuiv;
	}
}