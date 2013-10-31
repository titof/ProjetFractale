#include <stdio.c>
#include <stdio.h>
#include "Grammaire.h"



void grammaire_lire(char *nomfic, Grammaire *g){

  FILE *pfo ;
  pfo = fopen((nomfic), "r");
  
  if(!pfo) {
    printf("Ouverture du fichier %s impossible\n", nomfic);
    exit(2);
  }
  /* lecture nom de la fractale */
  fscanf(pfo, "%s\n",g->titre);
  /* lecture nombre de directions */
  fscanf(pfo,"%d\n",&(g->turtle_dir_max));
  /* lecture de la direction initiale */
  fscanf(pfo,"%d\n",&(g->turtle_dir_init));
  /* lecture de l'axiome */
  fscanf(pfo,"%s\n",g->axiome);
  /* aucune regles au depart */
  g->nb_dir = 0;
  while (fscanf(pfo, "%c ->%s\n", &(g->car[g->nb_dir]), g->regle[g->nb_dir]) != (EOF))
    { 
      
      /* calcul de la longueur de la partie droite de la regle */
      g->long_regle[g->nb_dir] = strlen(g->regle[g->nb_dir]);
      g->nb_dir++;
    }
  fclose(pfo);
}

void grammaire_afficher(Grammaire g)
{
  int i = 0;
  
  printf("Nom de la grammaire : %s\n", g.titre);
  printf("Nombre de directions : %d\n", g.nb_dir);
  printf("Direction initiale : %d\n", g.turtle_dir_init);
  printf("Axiome : s\n", g.axiome);
  
  while (i < 10
         && strcmp(&g.car[i], ""))
    {
      printf("Regle de production %d : ", i + 1);
      printf("%c->%s\n", g.car[i], g.regle[i]);
      i++;
    }
}

void grammaire_trouver(Grammaire *g, char cmd){

 FILE *pfo ;
 int i=0;
 tab = malloc( sizeof char);
 while (fscanf(pfo, "%c ->%s\n", &(g->car[g->nb_dir]),g->regle[g->nb_dir]) != (EOF)){
 	if (fscanf(pfo, "%c",commande)==cmd){
	 
	}
 }



}
