#ifndef LEXIQUE_H
#define LEXIQUE_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include <stdbool.h>
	#include "Constantes.h"

	#define FIFRANCAIS "Francais.txt"
	#define FIENGLISH "English.txt"

	#define TNOMFICHIER 20
	#define TTITRE		100
	#define TMENU		100
	#define TTXT		150

	typedef struct personnage Personnage;
	struct personnage {
		char nom[TNOM];
		int points;
		Personnage* pSuiv;
	};

	typedef struct joueur Joueur;
	struct joueur{
		char pseudo[TPSEUDO];
		Personnage* pDebutPerso;
		Joueur* pSuiv;
	};

	typedef enum numMessage NumMessage;
	enum numMessage {
		// Menu
		MENU_PRINCIPAL = 1001,
		// Messages d'obtention
		OBT_PSEUDO = 2001,
		OBT_NOM,
		OBT_POINTS,
		OBT_ENCORE = 2101,
		OBT_CHOIX,
		OBT_CONTINUER,
		// Titres
		TITRE_PRINCIPAL = 3000,
		TITRE_JOUEUR = 3001,
		TITRE_PERSONNAGE = 3002,
		TITRE_AFFICHAGE = 3003,
		TITRE_JOUEUR_AJOUT = 3101,
		TITRE_JOUEUR_ANNUL = 3102,
		TITRE_PERSO_AJOUT = 3201,
		TITRE_PERSO_ANNUL = 3202,
		TITRE_LISTE_JOUEURS = 3301,
		CHARGEMENT = 3401,
		SAUVEGARDE,
		AUCUN_JOUEUR,
		AUCUN_PERSONNAGE,
		// Num�ro de d�but des messages d'erreur
		NUM_DEB_MESSAGE_ERREUR = 5000,
	};

	typedef struct message Message;

	// Fonctions publiques

	CodeErreur chargerLexique(Message** pPLexique);
	// Chargement du fichier des diff�rents textes � afficher dans une liste chain�e simple
	// Pr� : pPLexique est l'adresse de l'adresse d�but de la liste (pLexique)
	// Post : renvoie un code erreur sur l'erreur �ventuellement rencontr�e 
	//        si pas d'erreur, pLexique contient l'adresse d�but de la liste des messages textes
	
	void afficherMessage(Message* pLexique, int numMessage);
	// Affiche un message texte
	// Pr� : pLexique est l'adresse d�but de la LC des messages
	//       numMessage est le num�ro du message � afficher (0 < num�ro <= numMax dans le fichier)
	// Post : le message sera affich�
	
	int afficherMenu(Message* pLexique, int debMenu);
	// Affiche un menu 
	// Pr� : pLexique est l'adresse d�but de la LC des messages
	//       debMenu est le num�ro du titre du menu � afficher (0 < num�ro <= numMax dans le fichier)
	// Post : le titre du menu et ses options seront affich�s

	void afficherTitre(Message* pLexique, int numTitre);
	// Affiche un titre apr�s avoir effac� l'�cran
	// Pr� : pLexique est l'adresse d�but de la LC des messages
	//       numTitre est le num�ro du titre � afficher (0 < num�ro <= numMax dans le fichier)
	// Post : le titre sera affich� en d�but de page

	void libererLexique(Message* pLexique);
	// Lib�re la LC des messages
	// pLexique est l'adresse d�but de la liste
#endif
