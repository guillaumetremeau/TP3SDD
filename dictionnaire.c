#ifndef __DICTIONNAIRE_C_FARAH_GUILLAUME__
#define __DICTIONNAIRE_C_FARAH_GUILLAUME__

#include "dictionnaire.h"

void insertionFromFile(dico_t * dico, char * fileName){
	FILE * file = NULL;
	char * chaine = "";
	file = fopen(fileName, "r");
	if (file != NULL){
		while(fgets(chaine, TAILLEMAXMOT, file) != NULL){
			insertionMot(dico, chaine);
		}
		fclose(file);
	}else printf("erreur à l'ouverture du fichier");
}

char * affichage(dico_t * dico){
	char * res = "";
	dico_t * ptrDico = dico;
	pile_t pile = initPile(TAILLEMAXMOT);
	while (!estVide(pile) || ptrDico!=NULL) {
		while (ptrDico->fils != NULL) {
			empiler(pile, ptrDico);
			ptrDico = ptrDico->fils;
		}
		while (ptrDico = NULL && !estVide(pile)){
			ptrDico = depiler(pile)->frere;
		}
	}
	return res;
}


#endif
