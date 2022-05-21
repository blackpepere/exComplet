#ifndef JOUEURSPERSO_H
#define JOUEURSPERSO_H

	#include "Constantes.h"
	#include "Lexique.h"


	void dialogues(Message* pLexique);
	ChoixMenu choixObtenu(Message* pLexique, NumMessage numero);
	CodeErreur chargerJoueursPersonnages(Message* pLexique, Joueur** pDebJoueurs);
	CodeErreur ajouterJoueurPersonnages(Message* pLexique, Joueur** pDebJoueurs);
	CodeErreur ajouterPersonnageAJoueur(Message* pLexique, Joueur** pDebJoueur, Joueur** pJoueur, Personnage** pNouvPerso);
	CodeErreur ajouterPersonnage(Message* pLexique, Joueur** pDebJoueur);
	void nomObtenu(Message* pLexique, char nom[]);
	int reponseObtenu(Message* pLexique, NumMessage message);
	int pointsObtenus(Message* pLexique);
	void pseudoObtenu(Message* pLexique, char pseudo[]);
	bool nouveauJoueur(Joueur** pNouvJoueur);
	bool joueurExiste(Joueur* pDebJoueurs, char pseudo[], Joueur** pJoueurs, Joueur** pSauvJoueur);
	bool personnageExiste(Joueur* pDebJoueurs, char nom[]);
	void ajouteJoueur(Joueur** pDebJoueur, char pseudo[], Joueur* pNouvJoueur, Joueur* pJoueur, Joueur* pSauvJoueur);
	int nbPersonnages(Joueur* pJoueur);
	bool nouveauPersonnage(Personnage** pNouvPerso);
	void libererJoueur(Joueur* pJoueur);
	void libererPersonnage(Personnage* pPerso);
	CodeErreur supprimerJoueurPersonnages(Message* pLexique, Joueur** pDebJoueur);
	void supprimeJoueur(Joueur** pDebJoueur, Joueur* pJoueur, Joueur* pSauvJoueur); 
	void ajoutePersonnage(Joueur* pJoueur, char nom[], int nbPoints, Personnage* pPerso);
	void listeJoueurs(Joueur* pDebJoueurs);
	void afficherJoueursPersonnages(Message* pLexique, Joueur* pDebJoueurs);


#endif