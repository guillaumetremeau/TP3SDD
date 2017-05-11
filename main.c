#include <stdio.h>
#include <stdlib.h>
#include "dictionnaire.h"
#include "rech.h"
#include "pile.h"


int main(){
	dico_t * dico = NULL;
	insertionFromFile(dico,"dictionnaire.txt");

	return 0;
}
