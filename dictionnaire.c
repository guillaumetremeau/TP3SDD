#ifndef __DICTIONNAIRE_C_FARAH_GUILLAUME__
#define __DICTIONNAIRE_C_FARAH_GUILLAUME__

#include "dictionnaire.h"
#include "pile.h"


/* ---------------------------------------------------
 *
 *              INSERTIONFROMFILE
 *
 * Insère les mots d'un fichier texte entré en
 * paramètre dans le dictionnaire
 *
 *
 * Lexique :
 *  - dico : dictionnaire
 *  - fileName : fichier qui contient les mots
 *  - chaine : contient les mots du fichier
 *  - file : fichier que l'on peut lire
 *
 *
 * --------------------------------------------------- */

void insertionFromFile(dico_t * dico, char * filename)
{
	FILE * file = NULL;
	char chaine[TAILLEMAXMOT]= "";		/*chaine qui va contenir les mots du fichier*/
	int i = 0;
	file = fopen(filename, "r");		/*ouvrir le fichier*/

	if (file != NULL)			/*si le fichier existe*/
	{
		while(fgets(chaine, TAILLEMAXMOT, file) != NULL)	/*tant qu'il y a un mot dans le fichier*/
		{
    			while(chaine[i]!='\n')		/*tant qu'on saute pas une ligne donc qu'on est pas à la fin du mot*/
    			{
				i=i+1;
			}
			chaine[i]='\0';			/*changer le dernier caractère \n en \0 pour le mettre en maj dans insertionMot*/
			insertionMot(dico, chaine);	/*on insere la chaine dans le dico*/
		}
		fclose(file);
	}
	else
	{
		printf("erreur à l'ouverture du fichier");
	}
}


/* ---------------------------------------------------
 *
 *              AFFICHAGE
 *
 *
 *
 * Lexique :
 *  -
 *  -
 *  -
 *
 * Retour :
 *  -
 * --------------------------------------------------- */

char * affichage(dico_t * dico){
	char * res = (char *)malloc(TAILLEMAXMOT*sizeof(char));
	dico_t * ptrDico = dico;
	pile_t pile = init_pile(TAILLEMAXMOT);
	res ="";
	printf("debut aff\n");
	while (!est_vide(pile) || ptrDico!=NULL) {
		printf("boucle1\n");
		while (ptrDico->fils != NULL) {
			printf("boucle2\n");
			printf("%c\n", ptrDico->lettre);
			empiler(&pile, (valeur_t)ptrDico);
			ptrDico = ptrDico->fils;
		}
		printf("sortieboucle\n");
		res = strcat(res, pileToMot(&pile));
		printf("%s\n", res);
		while (ptrDico == NULL && !est_vide(pile)){
			printf("boucle3\n");
			depiler(&pile,(struct dico_t **)&ptrDico);
		}
	}

	free_pile(&pile);
	return res;
}


/* ---------------------------------------------------
 *
 *              INSERTIONMOT
 *
 * Insert un mot entré en paramètre dans le dictionnaire
 *
 * Lexique :
 *  - dico : dictionnaire
 *  - mot : mot à insérer
 *  - taille :
 *
 * --------------------------------------------------- */

void insertionMot(dico_t * dico, char * mot)			/*probleme avec premiere lettre*/
{
	int taille = 0;
	dico_t ** cour = Recherche(dico, mot, &taille);		/*cour prend l'adresse de l'élément après lequel il faut inserer le mot*/
	dico_t * tmp = *cour;		/*on stocke cour dans un temp*/
	int i = taille;

	*cour = (dico_t*)malloc(sizeof(dico_t));	/*on alloue un nouvel élément*/
	tmp->frere = *cour; 	/*chainage sur le frere de l'element que l'on vient d'allouer*/
	(*cour)->fils = NULL;	/*on initialise les valeurs du nouvel élément*/
	(*cour)->fils = NULL;

	if (mot[i]!= '\0') 	/* si le mot est vide ou qu'il est déjà dans le dictionnaire */
	{
		while (mot[i+1]!='\0')  /*on est pas a la fin donc on insere la lettre en minuscule*/
		{
			(*cour)->lettre = tolower(mot[i]);
			cour = &((*cour)->fils); 	/*adresse de la case dans laquelle on va stocker le fils*/
			*cour = (dico_t*)malloc(sizeof(dico_t)); 	/* on alloue la taille d'un fils */
			(*cour)->fils = NULL;
			(*cour)->frere = NULL;		/*on initialise les valeurs a NULL*/
			i++;
		}
		(*cour)->lettre = toupper(mot[i]);  	/*derniere lettre donc on l'ajoute en majuscule*/
	}
}

/* ---------------------------------------------------
 *
 *              RECHERCHEFROMMOTIF
 *
 *
 *
 * Lexique :
 *  -
 *  -
 *  -
 *
 * Retour :
 *  -
 * --------------------------------------------------- */

char * rechercheFromMotif(dico_t * dico, char * motif){
	char* res = (char *) malloc(TAILLEMAXMOT*sizeof(char));
	int i = 0;
	dico_t * ptrDico = dico;
	/*dico_t ** resRec = recherche(ptrDico, motif, &i);
	res = affichage(*resRec);*/
	return res;
}


/* ---------------------------------------------------
 *
 *              RECHERCHE
 *
 * Recherche l'adresse de la dernière lettre commune
 * entre le mot et le dictionnaire et renvoie
 * l'adresse de l'élément où il faut insérer le mot
 *
 * Lexique :
 *  - dico : dictionnaire
 *  - mot : mot à rechercher
 *  - taille
 *
 * Retour :
 *  - taille : nb de charactères du mot qui sont déjà
 * dans le dictionnaire
 *  - prec : adresse de l'élément à la suite duquel on
 * peut insérer la suite du mot
 * --------------------------------------------------- */

dico_t** Recherche(dico_t * dico, char* mot, int * taille)
{
	dico_t** cour = &dico;		/*cour prend l'adresse de dico*/
	dico_t** prec = (dico_t**) *cour;		/*prec prend l'adresse de cour*/
	int i=0;

	while (mot[i]!='\0' && *cour!=NULL && (*cour)->lettre!='\0' && tolower((*cour)->lettre)<=tolower(mot[i]))	/* tant qu'on est pas à la fin du mot, que l'adresse du cour est différent de NULL, que la valeur pointée par cour est différente de NULL et que la lettre pointee par cour est inferieure à celle du mot*/
	{
		if (mot[i+1]=='\0' && (*cour)->lettre==mot[i]) /*le mot est deja dans le dico*/
		{
			(*cour)->lettre = toupper((*cour)->lettre); /*mettre en maj la derniere lettre du mot*/
			*prec = *cour;
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
	*taille = i;
	return prec;
}


#endif
