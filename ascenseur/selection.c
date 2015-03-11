#include <stdio.h>


/*Fonction qui permet de séléctionner l'étage que l'on veut atteindre
  @return       selec   int :   étage sélectionné*/
int selection(int etg, int MIN, int MAX){
    char chaine[50];
    sprintf(chaine, "Selection etage (etage %d)? [de %d a %d] \n",etg, MIN, MAX);
    int valeur = saisieEntier(chaine);/* , etg */
    /*logg(valeur, "selection","Selection etage", "Notice");*/
    return valeur;
}