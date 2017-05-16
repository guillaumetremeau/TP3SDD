#include <stdio.h>
#include <stdlib.h>
#include "dictionnaire.h"
#include "rech.h"
#include "pile.h"

dico_t* creationDico();

int main(){
	dico_t * dictio = creationDico();
	printf("ca va\n");
	int i = 0;
	dico_t ** res = Recherche(dictio, "abou", &i); 
	printf("ca va toujours\n");
	
	printf("%c\n", (*res)->lettre);
	/*insertionMot(dictio, "aba");
	printf("%d - %c\n", dictio->fils->fils->lettre, dictio->fils->fils->lettre);*/
	/*printf("%c\n", dictio->lettre);
	printf("%c\n", dictio->lettre);*/
/*	printf("%s", affichage(dictio));*/
	/*insertionFromFile(dico,"dictionnaire.txt");*/

	return 0;
}

dico_t* creationDico(){
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

	fils8 = (dico_t *) malloc(sizeof(dico_t));
	fils8->lettre = 'S';
	fils8->frere = NULL;
	fils8->fils = NULL;

	return(dictio);
}
