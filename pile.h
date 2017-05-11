#ifndef __PILE_H_FARAH_GUILLAUME__
#define __PILE_H_FARAH_GUILLAUME__

#include <stdlib.h>
#include <string.h>
#include "dictionnaire.h"

typedef struct dico_t *valeur_t;

typedef struct
{
  valeur_t * valeurs;
  int taille;
  int curseur;
}pile_t;



/* ---------------------------------------------------
 *
 *              INIT_PILE
 *
 * Retourne une pile vide de taille maximal indique
 * en parametre.
 *
 * Retour :
 *  - tete de la pile initialisee
 * --------------------------------------------------- */
pile_t init_pile(unsigned);



/* ---------------------------------------------------
 *
 *              FREE_PILE
 *
 * Libere la memoire allouee a la pile passee en
 * parametre.
 * --------------------------------------------------- */
void free_pile(pile_t *);



/* ---------------------------------------------------
 *
 *              EST_VIDE
 *
 * Indique si une pile passee en parametre est vide
 * ou non.
 *
 * Retour :
 *  - 1 si la pile est vide
 *  - 0 sinon
 * -------------------------------------------------- */
int est_vide(pile_t);



/* ---------------------------------------------------
 *
 *              EMPILER
 *
 * Empile la valeur passee en parametre dans la pile
 * egalement passee en parametre si la pile n'est pas
 * pleine.
 *
 * Retour :
 *  - 0 si l'empilage a pu etre fait
 *  - 1 sinon
 * --------------------------------------------------- */
int empiler(pile_t *,valeur_t);



/* ---------------------------------------------------
 *
 *              DEPILER
 *
 * Depile la premiere valeure de la pile passee en 
 * parametre dans l'adresse egalement passee en
 * parametre.
 *
 * Retour :
 *  - 0 si le depilage a pu etre fait
 *  - 1 sinon
 * --------------------------------------------------- */
int depiler(pile_t *,valeur_t*);



char * pileToMot(pile_t*);

#endif
