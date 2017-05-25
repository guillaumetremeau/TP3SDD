#ifndef __DICTIONNAIRE_H_FARAH_GUILLAUME__
#define __DICTIONNAIRE_H_FARAH_GUILLAUME__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pile.h"

typedef struct dico{
	char lettre;
	struct dico * fils;
	struct dico * frere;
}dico_t;

#define TAILLEMAXMOT 100
#define TAILLEMAXDICO 1000


/* ---------------------------------------------------
 *
 *              INSERTIONFROMFILE
 *
 * Insère les mots d'un fichier texte entré en
 * paramètre dans le dictionnaire
 *
 * --------------------------------------------------- */

void insertionFromFile(dico_t *, char *);

/* ---------------------------------------------------
 *
 *              INSERTIONMOT
 *
 * Insert un mot entré en paramètre dans le dictionnaire
 *
 * --------------------------------------------------- */

void insertionMot(dico_t *, char *);

/* ---------------------------------------------------
 *
 *              AFFICHAGE
 *
 * Affiche la liste des mots contenus dans un dictionnaire
 * --------------------------------------------------- */

char * affichage(dico_t *);


/* ---------------------------------------------------
 *
 *              RECHERCHEFROMMOTIF
 *
 * Affiche les mots du dictionnaire possedant un motif
 * donné
 *
 * --------------------------------------------------- */

char * rechercheFromMotif(dico_t *, char *);

/* ---------------------------------------------------
 *
 *              RECHERCHE
 *
 * Recherche l'adresse de la dernière lettre commune
 * entre le mot et le dictionnaire et renvoie
 * l'adresse de l'élément où il faut insérer le mot
 *
 * Retour :
 *  - taille : nb de charactères du mot qui sont déjà
 * dans le dictionnaire
 *  - prec : adresse de l'élément à la suite duquel on
 * peut insérer la suite du mot
 * --------------------------------------------------- */

dico_t ** Recherche(dico_t *, char *, int *);

#endif
