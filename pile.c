#include <stdio.h>
#include <stdlib.h>

#include "pile.h"

/* Retourne une pile vide */
Pile pile_initialiser()
{
  return (NULL);
}

/* Retourne vrai si la liste est vide */
int pile_vide(Pile p)
{
  return (p == NULL);
}

/* Empile les informations utiles de t sur p et retourne la nouvelle pile p */
Pile pile_empiler(Pile p, Tortue *t)
{
  Pile l;

  l = (Pile) malloc(sizeof(Pile_Cellule));
  if (l == NULL){
    printf("Allocation mémoire impossible...\n");
    exit(1);
  }
  l->x = t.x;
  l->y = t.y;
  l->dir = t.dir;
  l->suc = p;
 
  return (l);
}

/* Dépile un élément de p pour rempiler t et retourne la nouvelle pile p */
Pile pile_depiler(Pile p, Tortue *t)
{
  Pile l = NULL;

  if(!pile_vide(p)){
    l = p -> suc;
    free(p);
  }else{
    printf("Suppression de la liste impossible");
    exit(1);
  }
  return (l);
}

/* Affiche le contenu de la pile */
void pile_afficher(Pile p)
{
  Pile *tmp;
  if(p == NULL){
    printf("Il n'y a rien dans la pile");
    exit(0)
  }else{
    tmp = p->suc
    while(tmp != NULL){
      printf("X: %f, Y: %f, Direction: %d", p->x,p->y,p->dir);
      tmp = p->suc;
   }
    if(tmp = NULL){
      printf("X: %f, Y: %f, Direction: %d", tmp.x,tmp.y,tmp.dir);
    }
    exit(0);
}

/* Libère une pile en la vidant complètement */
void pile_liberer(Pile p)
{
  free(p);
}
