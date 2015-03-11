#include <stdio.h>
#include "saisieEntier.h"


/*Fonction qui permet d'appeler l'ascenseur
  @return       etg   int :   étage sélectionné*/

int appel(int etg){
    char chaine[50];
    sprintf(chaine, "A quel etage etes vous ?\n");
    printf("Appel ascenseur (etage: %d)\n",etg);
    int valeur = saisieEntier(chaine , etg ); /**/
    /* debug */
    printf("debug post saisieEntier dans fonction appel\n");
   /* logg(valeur, "appel","Appel ascenseur", "Notice");*/
    return valeur;
}