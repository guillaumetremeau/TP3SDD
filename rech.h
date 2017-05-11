#ifndef __SEMAINE_H_GUILLAUME_FARAH__
#define __SEMAINE_H_GUILLAUME_FARAH__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct dico{
	char lettre;
	struct dico * fils;
	struct dico * frere;
}dico_t;

void Insertion(dico_t *, char *)
void Recherche(dico_t *, char *, dico_t *, int)
void alloueLettre(dico_t *, char)

#endif
