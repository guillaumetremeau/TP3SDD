#ifndef __DICTIONNAIRE_C_FARAH_GUILLAUME__
#define __DICTIONNAIRE_C_FARAH_GUILLAUME__

#include "dictionnaire.h"
#include "pile.h"

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
	pile_t pile = init_pile(TAILLEMAXMOT);
	while (!est_vide(pile) || ptrDico!=NULL) {
		while (ptrDico->fils != NULL) {
			empiler(&pile, (valeur_t)ptrDico);
			ptrDico = ptrDico->fils;
		}

/*  */

		res = strcat(res, pileToMot(&pile));
		while (ptrDico == NULL && !est_vide(pile)){
			depiler(&pile,(struct dico_t **)&ptrDico);
		}
	}

	free_pile(&pile);
	return res;
}

void insertionMot(dico_t * dico, char * mot){
}

#endif
