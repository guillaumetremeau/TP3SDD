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

void insertionFromFile(dico_t *, char *);
void insertionMot(dico_t *, char *);
void alloueLettre(dico_t *, char);
char * affichage(dico_t *);
char * rechercheFromMotif(dico_t *, char *);
dico_t ** Recherche(dico_t *, char *, int *);

#endif
