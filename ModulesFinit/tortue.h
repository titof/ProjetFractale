#ifndef TORTUE_H_INCLUS
#define TORTUE_H_INCLUS

#define   DEUXPI   (2 * 3.14159265358979323846)

typedef struct {
  float x; 
  float y;
  int dir;

  /* Valeurs fixes */
  float *si;               /* Tableau des sinus   */
  float *co;               /* Tableau des cosinus */

  /* Valeurs héritées d'une grammaire */
  int  dir_max;            /* Nbr de directions possibles pour la tortue */
} Tortue;


void tortue_initialiser(Tortue *tortue, int dir_max, int dir_init);
void tortue_initialiser_position(Tortue *tortue, int dir_init);
void tortue_liberer(Tortue *tortue);

#endif 
