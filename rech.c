#include <ctype.h>


void Insertion(dico_t * dico, char * mot){
	int fin = 0;
	dico_t * ptrDico = &dico;
	char * ptrMot = &mot;
	dico_t * res = &dico;

	while(fin = 0){
		while(*ptrMot != NIL){
			while((*ptrMot != *ptrDico) && (*ptrDico != NIL)){
				ptrDico = ptrDico->frere;
			}		
			if(tolower(*ptrMot) = tolower(*ptrDico)){		
				if(ptrMot+1 = NIL){
					toupper(*ptrDico);		//mettre en majuscule
					fin = 1;
				}
				else{
					res = ptrDico;
					ptrMot = ptrMot+1;
					ptrDico = ptrDico->fils;
				}
			}
			else{
				fin = 1;
			}
		}
	}

	ptrDico = res;
	ptrDico = ptrDico->fils;
	while(tolower(*ptrDico) < tolower(*ptrMot)){		//comparaison de caractères
		ptrDico = ptrDico->frere;
	}
	while(*ptrMot != NIL){
		if(ptrMot+1 = NIL){
			alloueLettre(ptrDico->fils, toupper(*ptrMot)); //derniere lettre a inserer donc maj
		}
		else {
			alloueLettre(ptrDico->fils, tolower(*ptrMot)); //pas derniere lettre donc min
		}
		ptrMot = ptrMot+1;
	}
}






void alloueLettre(dico_t * ptrDico, char Lettre){
	dico_t * nouvLettre = (dico_t *) malloc(sizeof(dico_t));
	nouvLettre->lettre = Lettre;
	nouvLettre->fils = ptrDico;
	ptrDico = nouvLettre ;
}

