#include <stdio.h>
#include <stdlib.h>
#include "dictionnaire.h"
#include "rech.h"
#include "pile.h"


















dico_t * creationDicoVide(){
	dico_t * dictio = NULL;

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

void rechDicoPlein(dico_t * dictio){
	printf("Recherche dans un dictionnaire plein du mot 'abi'\n");
	int i = 0;
	char * mot = "abi";
	dico_t ** res = Recherche(dictio, mot, &i);
	printf("Le mot %s va etre inserer apres la letre %c\n", mot, (*res)->lettre);
}

void rechDicoVide(dico_t * dictio){
	printf("Recherche dans un dictionnaire vide du mot 'abi'\n");
	int i = 0;
	char * mot = "abi";
	dico_t ** res = Recherche(dictio, mot, &i);
	printf("Le mot %s va etre inserer apres la letre %c\n", mot, (*res)->lettre);
}

void insertionMotDicoPlein(dico_t * dictio){
	printf("Insertion du mot 'abba' dans un dictionnaire plein\n");
	insertionMot(dictio, "abba");
}

void insertionMotDicoVide(dico_t * dictio){
	printf("Insertion du mot 'abba' dans un dictionnaire vide\n");
	insertionMot(dictio, "abba");
}

void insertionFromFileDicoPlein(dico_t * dictio){
	printf("Insertion de mots depuis un fichier dans un dictionnaire plein\n");
	insertionFromFile(dictio, "dico.txt");
}

void insertionFromFileDicoVide(dico_t * dictio){
	printf("Insertion de mots depuis un fichier dans un dictionnaire vide\n");
	insertionFromFile(dictio, "dico.txt");
}

void insertionFromFileFileVide(dico_t * dictio){
	printf("Insertion de mots depuis un fichier vide\n");
	insertionFromFile(dictio, "dico_vide.txt");
}

void affichageDicoPlein(dico_t * dictio){
	printf("Affichage d'un dictionnaire plein\n");
	printf("%s\n", affichage(dictio));
}

void affichageDicoVide(dico_t * dictio){
	printf("Affichage d'un dictionnaire vide\n");
	printf("%s\n", affichage(dictio));
}

void rechercheFromMotifDicoPlein(dico_t * dico, char * motif){
	printf("Recherche d'un motif dans un dictionnaire plein\n");
	printf("Mots découlants de\n%s\n\n", motif);
	printf("%s\n", rechercheFromMotif(dico,motif));
}

void rechercheFromMotifDicoVide(dico_t * dico, char * motif){
	printf("Recherche d'un motif dans un dictionnaire vide\n");
	printf("Mots découlants de\n%s\n\n", motif);
	printf("%s\n", rechercheFromMotif(dico,motif));
}

void rechercheFromMotifMotifVide(dico_t * dico, char * motif){
	printf("Recherche d'un motif vide dans un dictionnaire plein\n");
	printf("Mots découlants de\n%s\n\n", motif);
	printf("%s\n", rechercheFromMotif(dico,motif));
}

int main(){
	dico_t * dictioP = creationDicoPlein();
	dico_t * dictioV = creationDicoVide();

	/*affichageDicoPlein(dictioP);*/

	/*rechDicoPlein(dictioP);*/

	/*rechDicoVide(dictioV);	seg fault*/ 

	/*insertionMotDicoPlein(dictioP);*/

	/*insertionMotDicoVide(dictioV);	seg fault*/

	/*insertionFromFileDicoPlein(dictioP);*/

	/*insertionFromFileDicoVide(dictioV);		seg fault*/

	/*insertionFromFileFileVide(dictioP);*/

	/*affichageDicoPlein(dictioP);*/

	/*affichageDicoVide(dictioV);*/

	/*rechercheFromMotifDicoPlein(dictioP,"ab");*/

	/*rechercheFromMotifDicoVide(dictioV,"ab");	seg fault*/

	/*rechercheFromMotifMotifVide(dictioP,"");	seg fault*/

	return 0;
}
