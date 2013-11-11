#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "tortue.h"



/* 
   Initialisation d'une tortue
*/

void tortue_initialiser(Tortue *tortue, int dir_max, int dir_init)
{
  int i;
  unsigned int memoire_necessaire;
  
  memoire_necessaire =  dir_max * sizeof(float);

  tortue->co = (float *) malloc(memoire_necessaire);
  tortue->si = (float *) malloc(memoire_necessaire);

  if (!tortue->co || !tortue->si) {
    printf("Problème d'allocation mémoire dans la tortue !\n");
    exit(3);
  }

  for (i = 0; i < dir_max; i++) {
    tortue->co[i] = (float) cos(DEUXPI * (((double) i) / ((double) dir_max)));
    tortue->si[i] = (float) sin(DEUXPI * (((double) i) / ((double) dir_max)));
  }

  tortue->dir_max = dir_max;
  tortue_initialiser_position(tortue, dir_init);
}

/* 
   Initialisation de la position d'une tortue
*/

void tortue_initialiser_position(Tortue *tortue, int dir_init)
{
  tortue->dir = dir_init;
  tortue->x = 0;
  tortue->y = 0;
}

/* 
   La tortue ne va plus servir : on libère les ressources associées
*/

void tortue_liberer(Tortue *tortue)
{
  free(tortue->co);
  free(tortue->si);
}

