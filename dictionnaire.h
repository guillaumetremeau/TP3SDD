#ifndef __DICTIONNAIRE_H_FARAH_GUILLAUME__
#define __DICTIONNAIRE_H_FARAH_GUILLAUME__

#include <stdlib.h>
#include <stdio.h>

typedef struct dico{
	char lettre;
	struct dico * frere;
	struct dico * fils;
}dico_t;


