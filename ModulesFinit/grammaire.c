#include <stdio.c>
#include <stdio.h>
#include <string.h>
#include "grammaire.h"



void grammaire_lire(char *nomfic, Grammaire *g)
{
  FILE *fichier;
  *fichier = NULL;

  fichier = fopen(nomfic,"r");
  if (fichier == NULL){
    printf("Impossible d'ouvrir le fichier");
    exit(0);
  }

  fscanf(fichier,"%s\n",&g->nom);
  fscanf(fichier,"%d\n",&g->turtle_dir_max);
  fscanf(fichier,"%d\n",&g->turtle_dir_init);
  fscanf(fichier,"%s\n",&g->axiome);
  fscanf(fichier,"%c->%s\n",&g->car,&g->regle);
}

void grammaire_afficher(Grammaire g)
{
  
  printf("Nom : %s\n", g.nom);
  printf("Nombre de directions : %d\n", g.turtle_dir_max);
  printf("Direction de départ : %d\n", g.turtle_dir_init);
  printf("Axiome : %s\n", g.axiome);
  
  
}

void grammaire_trouver(Grammaire *g, char cmd)
{
  int i = 0;
  int j = 0;

  while (g->car[i] !=NULL && j == 0){
    if (g->car[i] == cmd){
      j = 1;
      i++;
    }
  }
  if (j=1){
    return -1;
  }else{
    return i;
  }
} 
