#include "pile.h"


/* ---------------------------------------------------
 *
 *              INIT_PILE
 *
 * Retourne une pile vide de taille maximal indique
 * en parametre.
 *
 * Lexique :
 *  - p : tete d'une pile vide (sortie)
 *  - taille_max : taille maximal de la pile (entree)
 *
 * Retour :
 *  - p
 * --------------------------------------------------- */
pile_t init_pile(unsigned taille_max){
  pile_t p;

  if(taille_max){
    p.valeurs = (valeur_t *)malloc(taille_max*sizeof(valeur_t));
  }else{
    p.valeurs=NULL;
  }

  if(p.valeurs){
    p.taille=taille_max;
  }else{
    p.taille = 0;
  }

  p.curseur = -1;

  return p;
}



/* ---------------------------------------------------
 *
 *              FREE_PILE
 *
 * Libere la memoire allouee a la pile passee en
 * parametre.
 *
 * Lexique :
 *  - p : adresse de la tete de la pile a liberer
 *        (entree/sortie)
 * --------------------------------------------------- */
void free_pile(pile_t * p){
  if(p && p->valeurs){
    free(p->valeurs);
    p->valeurs = NULL;
  }
}



/* ---------------------------------------------------
 *
 *              EST_VIDE
 *
 * Indique si une pile passee en parametre est vide
 * ou non.
 *
 * Lexique :
 *  - p : tete de la pile (entree)
 *
 * Retour :
 *  - 1 si la pile est vide
 *  - 0 sinon
 * -------------------------------------------------- */
int est_vide(pile_t p){
  return p.curseur == -1;
}



/* ---------------------------------------------------
 *
 *              EMPILER
 *
 * Empile la valeur passee en parametre dans la pile
 * egalement passee en parametre si la pile n'est pas
 * pleine.
 *
 * Lexique :
 *  - p : adresse de la tete de la pile (entree/sortie)
 *  - v : valeur a ajouter dans la pile (entree)
 *  - erreur : entier vallant 0 si l'empilage a pu 
 *             etre fait, 1 sinon (sortie)
 *
 * Retour :
 *  - erreur
 * --------------------------------------------------- */
int empiler(pile_t * p,valeur_t v){
  int erreur = 1;

  if(p && p->valeurs && p->curseur < p->taille - 1){
    p->curseur++;
    p->valeurs[p->curseur] = v;
    erreur = 0;
  }

  return erreur;
}



/* ---------------------------------------------------
 *
 *              DEPILER
 *
 * Depile la premiere valeure de la pile passee en 
 * parametre dans l'adresse egalement passee en
 * parametre.
 * 
 *
 * Lexique :
 *  - p : adresse de la tete de la pile (entree/sortie)
 *  - v : adresse de destination de la valeur depilee
 *        (entree)
 *  - erreur : entier vallant 0 si le depilage a pu
 *             etre fait, 1 sinon (sortie)
 *
 * Retour :
 *  - erreur
 * --------------------------------------------------- */
int depiler(pile_t * p,valeur_t * v){
  int erreur = 1;

  if(p && p->valeurs && !est_vide(*p)){
    *v = p->valeurs[p->curseur];
    p->curseur--;
    erreur = 0;
  }

  return erreur;
}


char * pileToMot(pile_t * pile){
	char * res = (char *)malloc(TAILLEMAXMOT*sizeof(char));
	int i = 0;
	dico_t * dico;
	res = "";
	if(!(est_vide(*pile))){

		/* Parcours de la pile */
		while (i <= pile->taille){
			dico =(dico_t *) pile->valeurs[i];
			res = strcat(res, &dico->lettre);
			i++;
		}

		/* Inversion de res  (inutile)
		for(i = 0; i< strlen(res)/2; i++){
			temp = res[i];
			res[i] = res[n-i-1];
			res[n-i-1] = temp;
		}*/

		/* Fin du mot */
		res = strcat(res,"/n");
	}
	return res;
}


