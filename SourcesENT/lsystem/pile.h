#ifndef PILE_H_INCLUS
#define PILE_H_INCLUS

#include "tortue.h"

typedef struct pile_cell {
  float                  x;       /* Position en X d'une tortue  */
  float                  y;       /* Position en Y d'une tortue  */
  int                    dir;     /* Direction d'une tortue      */
  struct pile_cell  *suc;         /* Chaînage                    */
} Pile_Cellule;

typedef Pile_Cellule *Pile;

/* Retourne une pile vide */
Pile pile_initialiser();

/* Retourne vrai si la pile est vide */
int pile_vide(Pile p);

/* Empile les informations utiles de t sur p et retourne la nouvelle pile */
Pile pile_empiler(Pile p, Tortue *t);

/* Dépile un élement de p pour remplir t et retourne la nouvelle pile p */
Pile pile_depiler(Pile p, Tortue *t);

/* Affiche le contenu de la pile */
void pile_afficher(Pile p);

/* Libère une pile en la vidant complètement */
void pile_liberer(Pile p);

#endif
