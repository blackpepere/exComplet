#include "JoueursPerso.h"

void main(void) {
	Message* pLexique = NULL; 
	CodeErreur codeErreur = chargerLexique(&pLexique);
	if (codeErreur != PAS_D_ERREUR) { 
		if (codeErreur == ALLOCATION_MEMOIRE) {
			puts("Erreur mémoire/memory Erreur");
			libererLexique(pLexique);
		}
		if (codeErreur == FICHIER_INEXISTANT) {
			puts("Erreur ouverture de fichier / file openning error");
		}
	}
	else {
		dialogues(pLexique);
		libererLexique(pLexique);
	}
}