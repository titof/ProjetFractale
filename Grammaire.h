#ifndef GRAMMAIRE_H_INCLUS
#define GRAMMAIRE_H_INCLUS

#define CHMAX 80 /* Dimension maximum d'une ligne du fichier */
#define NUMMAX 10 /* Nombre max de règles de production */

/* Grammaire */ 
typedef struct{
  char nom[CHMAX]; /* Nom de la fractale courante */
  char axiome[CHMAX]; /* Axiome */
  int num; /* Nombre de règles de production */
  char regle[NUMMAX][CHMAX-3]; /* Tableau des parties droites des règles */
  char car[NUMMAX]; /* Tableau des parties gauches des règles */
  int long_regle[NUMMAX]; /* Longueur des parties droites des règles */
  int turtle dir_max; /* Nombre de directions possibles pour la tortue */
  int turtle dir_init; /* Direction initiale */
}Grammaire;

void grammaire_lire(char *nomfic, Grammaire *g);
void grammaire_afficher(Grammaire g);
int grammaire_trouver(Grammaire *g, char cmd);

#endif
