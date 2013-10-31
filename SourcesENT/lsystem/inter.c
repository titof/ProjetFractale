#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "inter.h"
#include "gramm.h"
#include "tools.h"





/* Interpretation initialiser : initialiser l'interpreteur */
void inter_init(Interprete *inter)
{
  *inter.*mot=NULL;
  *inter.taille=NULL;
  *inter.xmin=NULL;
  *inter.ymin=NULL;
  *inter.xmax=NULL;
  *inter.ymax=NULL;

}



/*
  Interpretation graphique : dessin de la chaîne générée
*/

void inter_interpreter(Interprete *inter, float factor, Tortue *tortue, char *nom_fichier)
{ 
  int i;
  float x, y, xprec, yprec;
  char cmd;
  Pile p;
  FILE *fp;
  
  /* Initialisations générales */

  p = pile_initialiser();
  
  fp = fopen(nom_fichier, "w");

  if (!fp) {
    printf("Impossible d'ouvrir le fichier %s...\n", nom_fichier);
    exit(4);
  }

  /* Initialisation du fichier SVG */

  fputs("<?xml version=\"1.0\" standalone=\"no\" ?>\n", fp);
  fputs("<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"", fp);
  fputs(" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n", fp);
  fputs("<svg width=\"100%\" height=\"100%\" version=\"1.1\"", fp);
  fputs(" xmlns=\"http://www.w3.org/2000/svg\">\n", fp);
  fputs("  <svg stroke=\"black\">\n", fp);
  
  /* Dessin des segments */

  x = factor * (tortue->x - inter->xmin);
  y = factor * (tortue->y - inter->ymin);
  
  for (i = 0; i < inter->taille; i++) {
    cmd = inter->mot[i];
    p = inter_transition(p, cmd, tortue);
    xprec = x;
    yprec = y;
    x = factor * (tortue->x - inter->xmin);
    y = factor * (tortue->y - inter->ymin);

    if (cmd == 'F')
      fprintf(fp, "    <line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\"/>\n",
	      xprec, yprec, x, y);
  } 

  /* Fermeture du fichier SVG */
  
  fputs("  </svg>\n", fp);
  fputs("</svg>\n", fp);
  fclose(fp);

  /* Toujours pour le cas où... */

  pile_liberer(p);
}


/*Permet de generer le mot correspondant à une grammaire et à un niveau de developpement*/

int inter_generer(int niveau_max, Grammaire *g, Interprete *t)
{
  *t.*mot= /*Axiome a mettre ici*/
  


}

/*Permet de supprimer du mot courant tous les caractères qui ne sont pas interprétés graphiquement
 (donc tous les caractères sauf F,f,+,-,[ et ]) */

void inter_nettoyer(Interprete *inter){
 
}


/*Interprète graphiquement le mot, sans toutefois générer de dessin, afin de mettre à jour les champs de l'interpréteur
permettant de gérer la boite englobante*/
void inter_calc_dim(Interprete *inter, Tortue *tortue)
{

}

/*Permet l'exécution d'une seule commande graphique, en mettant à jour la pile et la tortue utilisées.*/
Pile inter_transition(Pile p, char cmd, Tortue *tortue)
{

}

/*Permet de libérer les ressources dynamiques utilisées par la structure.*/
void inter_liberer(Interprete *inter)
{

}
