#include <stdio.h>
#include <stdlib.h>
#include "dictionnaire.h"
#include "rech.h"
#include "pile.h"

dico_t* creationDicoPlein();
dico_t* creationDicoVide();


void affichageDicoPlein(dico_t * dictio){
	printf("%s\n", affichage(dictio));
}

void affichageDicoVide(dico_t * dictio){
	printf("%s\n", affichage(dictio));
}

void insertionFromFileFileVide(dico_t * dictio){
	insertionFromFile(dictio, "dico.txt");
	printf("%c%c%c%c\n", dictio->lettre, dictio->fils->lettre, dictio->fils->fils->frere->lettre, dictio->fils->fils->frere->fils->lettre);
}

void insertionFromFileDicoVide(dico_t * dictio){
	insertionFromFile(dictio, "dico.txt");
	printf("%c%c%c%c\n", dictio->lettre, dictio->fils->lettre, dictio->fils->fils->frere->lettre, dictio->fils->fils->frere->fils->lettre);
}

void insertionFromFileDicoPlein(dico_t * dictio){
	insertionFromFile(dictio, "dico.txt");
	printf("%c%c%c%c\n", dictio->lettre, dictio->fils->lettre, dictio->fils->fils->frere->lettre, dictio->fils->fils->frere->fils->lettre);
}

void insertionMotDicoExistant(dico_t * dictio){
	insertionMot(dictio, "abba");
	printf("%c%c%c%c\n", dictio->lettre, dictio->fils->lettre, dictio->fils->fils->frere->lettre, dictio->fils->fils->frere->fils->lettre);
}

void RechDicoExistant(dico_t * dictio){
	int i = 0;
	char * mot = "abi";
	dico_t ** res = Recherche(dictio, mot, &i);
	printf("Le mot %s va etre inserer apres la letre %c\n", mot, (*res)->lettre);
}

void RechDicoVide(dico_t * dictio){
	int i = 0;
	char * mot = "abi";
	dico_t ** res = Recherche(dictio, mot, &i);
	printf("Le mot %s va etre inserer apres la letre %c\n", mot, (*res)->lettre);
}

dico_t * creationDicoVide(){
	dico_t * dictio = (dico_t *) malloc(sizeof(dico_t));
	dictio->lettre = 'a';
	dictio->frere = NULL;
	dictio->fils = NULL;

	return dictio;
}

dico_t* creationDicoPlein(){
	dico_t * fils1;
	dico_t * fils2;
	dico_t * fils3;
	dico_t * frere2;
	dico_t * fils4;
	dico_t * fils5;
	dico_t * frere1;
	dico_t * fils6;
	dico_t * fils7;
	dico_t * fils8;
	dico_t * frere6;

	dico_t * dictio= (dico_t *) malloc(sizeof(dico_t));
	dictio->lettre = 'a';
	dictio->frere = NULL;
	dictio->fils = (dico_t *) malloc(sizeof(dico_t));

	fils1 = dictio->fils;
	fils1->lettre = 'b';
	fils1->frere = (dico_t *) malloc(sizeof(dico_t));
	fils1->fils = (dico_t *) malloc(sizeof(dico_t));

	fils2 = fils1->fils;
	fils2->lettre = 'a';
	fils2->frere = (dico_t *) malloc(sizeof(dico_t));
	fils2->fils = (dico_t *) malloc(sizeof(dico_t));

	fils3 = fils2->fils;
	fils3->lettre = 'T';
	fils3->frere = NULL;
	fils3->fils = NULL;

	frere2 = fils2->frere;
	frere2->lettre = 'i';
	frere2->frere = NULL;
	frere2->fils = (dico_t *) malloc(sizeof(dico_t));

	fils4 = frere2->fils;
	fils4->lettre = 'm';
	fils4->frere = NULL;
	fils4->fils = (dico_t *) malloc(sizeof(dico_t));

	fils5 = fils4->fils;
	fils5->lettre = 'E';
	fils5->frere = NULL;
	fils5->fils = NULL;

	frere1 = fils1->frere;
	frere1->lettre = 'r';
	frere1->frere = NULL;
	frere1->fils = (dico_t *) malloc(sizeof(dico_t));

	fils6 = frere1->fils;
	fils6->lettre = 'a';
	fils6->frere = (dico_t *) malloc(sizeof(dico_t));
	fils6->fils = (dico_t *) malloc(sizeof(dico_t));

	fils7 = fils6->fils;
	fils7->lettre = 'U';
	fils7->frere = NULL;
	fils7->fils = NULL;

	frere6 = fils6->frere;
	frere6->lettre = 'T';
	frere6->frere = NULL;
	frere6->fils = (dico_t *) malloc(sizeof(dico_t));

	fils8 = frere6->fils;
	fils8->lettre = 'S';
	fils8->frere = NULL;
	fils8->fils = NULL;

	return(dictio);
}

void rechercheFromMotifDicoPlein(dico_t * dico, char * motif){
	printf("Mots découlants de\n%s\n\n", motif);
	printf("%s\n", rechercheFromMotif(dico,motif));
}

int main(){
	dico_t * dictioP = creationDicoPlein();
	dico_t * dictioV = creationDicoVide();

	/*RechDicoExistant(dictioP);*/

	/*RechDicoVide(dictioV);*/

	/*insertionMotDicoExistant(dictioP);*/

	/*insertionMotDicoVide(dictioV);*/

	/*insertionFromFileDicoPlein(dictioP);*/

	/*insertionFromFileDicoVide(dictioV);*/

	/*insertionFromFileFileVide(dictioP);*/

	/*affichageDicoPlein(dictioP);*/

	/*affichageDicoVide(dictioV);*/

	/*rechercheFromMotifDicoPlein(dictioP,"ab");*/

	return 0;
}
