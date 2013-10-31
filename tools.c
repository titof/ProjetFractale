#include "tools.h"

/* Fonction qui permet de reserver dynamiquement la mémoire */
char *tools_nouvelle_chaine(int length)
{
  char *ch = NULL;

  ch = calloc(length, sizeof(char));
  if (ch == NULL)
    printf("Erreur : Allocation impossible\n");

  return (ch);
}
