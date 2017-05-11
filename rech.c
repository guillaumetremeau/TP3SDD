
#include "rech.h"

void insertion(dico_t * ptrDico, char * ptrMot, int * indice)
{
	int taille = 0;
	dico_t ** cour = rechercheMot(ptrDico, ptrMot, &taille);
	dico_t * tmp = *cour;
	int i = *indice;
	*cour = (dico_t*)malloc(sizeof(dico_t));
	(*cour)->frere = tmp; //chainage sur le frere de l'element que l'on vient d'allouer
	(*cour)->fils=NULL;

	if (mot[i]!=NULL) /* si le mot est vide ou qu'il est déjà dans le dictionnaire */
	{
		while (mot[i+1]!=NULL)  //on est pas a la fin donc on insere la lettre en majuscule
		{
			(*cour)->lettre = tolower(mot[i]);
			cour = &((*cour)->fils); //adresse de la case dans laquelle on va stocker le fils
			*cour = (dico_t*)malloc(sizeof(dico_t)); /* on alloue la taille d'un fils */
			(*cour)->fils=NULL;
			(*cour)->frere=NULL;	//on initialise les valeurs a NULL
			i++; 
		}
		(*cour)->lettre=toupper(mot[i]);  //derniere lettre donc on l'ajoute en maj
	}
}

dico_t** Recherche(dico_t * ptrDico, char* ptrMot, int * taille)
{
	dico_t** cour = &ptrDico;
	
	int i=0;
	while (ptrMot[i]!=NULL && *cour!=NULL && tolower((*cour)->lettre)<=tolower(mot[i]))
		{
			if (mot[i+1]==NULL && (*cour)->lettre==mot[i]) //le mot est deja dans le dico
				{
					toupper((*cour)->lettre); //mettre en maj la derniere lettre du mot
					i++; 
				}
			else if ((*cour)->lettre==mot[i])
			{	
				i++;
				cour = &((*cour)->fils);
			}
			else
			{
				cour = &((*cour)->frere);
			}
		}
		*taille = i;
		return cour;
}




