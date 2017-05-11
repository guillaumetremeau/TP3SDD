#ifndef __DICTIONNAIRE_H_FARAH_GUILLAUME__
#define __DICTIONNAIRE_H_FARAH_GUILLAUME__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pile.h"

typedef struct dico{
	char lettre;
	struct dico * frere;
	struct dico * fils;
}dico_t;

#define TAILLEMAXMOT 100

void insertionFromFile(dico_t *, char *);
void insertionMot(dico_t *, char *);
void alloueLettre(dico_t *, char);
char * affichage(dico_t *);

#endif
