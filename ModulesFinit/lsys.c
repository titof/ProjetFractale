#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tortue.h"
#include "gramm.h"
#include "inter.h"

int main(int argc, char *argv[])
{ 
  Grammaire gram;
  Interprete inter;
  Tortue tortue;
  float factor;
  int niveau_max, deb;
  int largeur_dessin, longueur_dessin;
  int taille_image;

  
  /* Vérification des paramètres */

  if (argc != 5) {
    printf("Usage : %s <fichier grammaire> <niveau> <fichier svg> <taille image>\n", argv[0]);
    exit(1);
  }

  /* Chargement de la grammaire */

  grammaire_lire(argv[1], &gram);
  grammaire_afficher(gram);
  
  /* Initialisations */

  inter_init(&inter);
  tortue_initialiser(&tortue, gram.turtle_dir_max, gram.turtle_dir_init);

  /* Production du mot à interpréter */

  niveau_max = atoi(argv[2]);
  deb = inter_generer(niveau_max, &gram, &inter);

  if (deb)
    printf("Attention debordement !! Le dessin ne sera pas complet !!\n");

  inter_nettoyer(&inter);

  /*
    La tortue est utilisée une première fois pour déterminer
    les dimensions du dessin
  */

  inter_calc_dim(&inter, &tortue);

  /*
    Dessin.

    On détermine quelle dimension est la *moins* importante et 
    on se cale dessus pour le calcul du facteur de ratio.
  */

  largeur_dessin = inter.xmax - inter.xmin;
  longueur_dessin = inter.ymax - inter.ymin;
  taille_image = atoi(argv[4]);

  if ((float) taille_image / largeur_dessin <
      (float) taille_image / longueur_dessin)
    factor = (float) taille_image / largeur_dessin; 
  else
    factor = (float) taille_image / longueur_dessin;

  printf("La fenêtre tortue est X[%f,%f],Y[%f,%f]\n", 
	 inter.xmin,
	 inter.xmax,
	 inter.ymin,
	 inter.ymax);
  printf("La fenêtre graphique a pour dimension  %d x %d\n", taille_image, taille_image);
  printf("Le facteur d'homothétie est de %f\n", factor);

  /*
    La tortue a déjà été utilisée, il faut réinitialiser sa position
  */

  tortue_initialiser_position(&tortue, gram.turtle_dir_init);
  inter_interpreter(&inter, factor, &tortue, argv[3]);

  /* Un peu de ménage */

  inter_liberer(&inter);
  tortue_liberer(&tortue);
  return 0;
}
