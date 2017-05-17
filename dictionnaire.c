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
	char * res = (char *)malloc(TAILLEMAXMOT*sizeof(char));
	dico_t * ptrDico = dico;
	pile_t pile = init_pile(TAILLEMAXMOT);
	res ="";
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

void insertionMot(dico_t * dico, char * mot)
{
	int taille = 0;
	dico_t ** cour = Recherche(dico, mot, &taille);
	dico_t * tmp = *cour;
	int i = 2;	/*probleme de la taille a regler*/
	printf("%d\n", taille);

	*cour = (dico_t*)malloc(sizeof(dico_t));
	tmp->frere = *cour; /*chainage sur le frere de l'element que l'on vient d'allouer*/
	(*cour)->fils = NULL;
	(*cour)->fils = NULL;
	if (mot[i]!= '\0') /* si le mot est vide ou qu'il est déjà dans le dictionnaire */
	{
		while (mot[i+1]!='\0')  /*on est pas a la fin donc on insere la lettre en majuscule*/
		{
			(*cour)->lettre = tolower(mot[i]);
			cour = &((*cour)->fils); /*adresse de la case dans laquelle on va stocker le fils*/
			*cour = (dico_t*)malloc(sizeof(dico_t)); /* on alloue la taille d'un fils */
			(*cour)->fils = NULL;
			(*cour)->frere = NULL;	/*on initialise les valeurs a NULL*/
			i++; 
		}
		(*cour)->lettre = toupper(mot[i]);  /*derniere lettre donc on l'ajoute en maj*/
	}
}

char * rechercheFromMotif(dico_t * dico, char * motif){
	char* res = (char *) malloc(TAILLEMAXMOT*sizeof(char));
	int i = 0;
	dico_t * ptrDico = dico;
/*	dico_t ** resRec = recherche(ptrDico, motif, &i);*/
/*	res = affichage(*resRec);*/
	return res;
}

dico_t** Recherche(dico_t * dico, char* mot, int * taille)
{
	dico_t** cour = &dico;
	dico_t** prec = *cour;
	int i=0;

	while (mot[i]!='\0' && *cour!=NULL && (*cour)->lettre!='\0' && tolower((*cour)->lettre)<=tolower(mot[i]))
	{
		if (mot[i+1]=='\0' && (*cour)->lettre==mot[i]) /*le mot est deja dans le dico*/
		{
			/**prec = *cour;*/
			(*cour)->lettre = toupper((*cour)->lettre); /*mettre en maj la derniere lettre du mot*/
			i++; 
		}
		else if ((*cour)->lettre==mot[i])
		{	
			i++;
			*prec = *cour;
			*cour = (*cour)->fils;
		}
		else
		{
			*prec = *cour;
			*cour = (*cour)->frere;
		}
	}
	taille = i;
	printf("%c\n", (*prec)->lettre);
	printf("%d\n", taille);
	return prec;
}


#endif
