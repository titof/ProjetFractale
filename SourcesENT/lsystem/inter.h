#ifndef INTERPRETE_H_INCLUS
#define INTERPRETE_H_INCLUS

#include <limits.h>

#include "tortue.h"
#include "pile.h"
#include "gramm.h"

#define INFINI INT_MAX

typedef struct
 {
   char               *mot;   /* Mot de la grammaire à interpréter graphiquement */
   int                taille; /* Taille = strlen(mot) */
   float              xmin;   /* Taille de la fenêtre de la tortue */
   float              ymin;
   float              xmax;
   float              ymax;
 }  Interprete;

void inter_init(Interprete *inter);
void inter_interpreter(Interprete *inter, float factor, Tortue *tortue, char *nom_fichier);
int inter_generer(int niveau_max, Grammaire *g, Interprete *t);
void inter_nettoyer(Interprete *inter);
void inter_calc_dim(Interprete *inter, Tortue *tortue);
Pile inter_transition(Pile p, char cmd, Tortue *tortue);
void inter_liberer(Interprete *inter);

#endif
