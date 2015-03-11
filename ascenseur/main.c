/*DEFINTIONS DES BIBLIOTHEQUES */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

/*DEFINITIONS DES BIBLIOTHEQUES PERSONNELLES*/
#include "deplacement.h"
#include "logg.h"
#include "saisieEntier.h"
#include "appel.h"
#include "selection.h"

/* DEFINTIONS des CONSTANTES*/
#define BUFFER_SIZE 256
 
/*DEFINITION DES PROTOTYPES DES FONCTIONS */
int saisieEntier(char chaine[], int etg ); /* */
int selection(int etg, int MIN, int MAX);
void logg(int eCourant, char* fonction, char* message, char* severity);
int deplacement(int a, int asc);
int appel(int etg);

/*DEFINITION DES CONSTANTES*/
int MIN, MAX;

/* ENTREE DU PROGRAMME */ 
int main(void)
{

    /*Définitions des variables*/
    /*int pereVersFilsEnEciture[2],filsVersPereEnEciture[2];
    char pereVersFilsEnLecture[BUFFER_SIZE], pereVersFilsEnEcriture[BUFFER_SIZE],
	 	  filsVersPereEnLecture[BUFFER_SIZE], filsVersPereEnEcriture[BUFFER_SIZE];*/
    int etg = 0, selec=0;/*pid_fils;*/
    
    int valeur;
        
    /*char* fonctionCourante = "main";
    char* messageProcessus = "processus père";
    char* messageErreurPipe = "Erreur dans le pipe";
    char* messageErreurProcessus = "processus enfant"; 
    char* typeErreurGrave = "Error";
    char* typeErreurPasGrave = "Notice";*/
    
    MIN = -3, MAX = 11;
    
    /*boucle principale*/
    do{
        do{
	    /*création du tube*/
	    /*if( (pipe(pereVersFilsEnEciture) != 0) && (pipe(filsVersPereEnEciture) != 0) ){
	       logg(etg, fonctionCourante, messageErreurPipe, typeErreurGrave);
	       exit(1);
	    } 
	    if( (pid_fils = fork()) == -1){
	       logg(etg, fonctionCourante,messageErreurProcessus, typeErreurGrave);
	       exit(1);
	    }*/
	    
	    /*récupèration de la valeur */
	    /*if(pid_fils == 0){
		logg(etg, fonctionCourante,messageErreurProcessus, typeErreurPasGrave);
		close(pereVersFilsEnEciture[1]);
		read(pereVersFilsEnEciture[0], &pereVersFilsEnLecture, BUFFER_SIZE);
		valeur = (int)pereVersFilsEnLecture;*/
		
		/*teste si on execute la suite du programme*/
		if (valeur != MAX){
		   etg = deplacement(valeur, etg); 
		   do
		      valeur = selection(etg,MIN,MAX);     
		   while (valeur < MIN || valeur > MAX-1);
		      etg = deplacement(valeur, etg); 
		}
		
		/*sinon on retourne processus père
		if( etg == MAX){ 
		  close(filsVersPereEnEciture[0]);
		  sprintf(filsVersPereEnEcriture,"%d", selec);
		  write(filsVersPereEnEciture[1], &filsVersPereEnEcriture, BUFFER_SIZE);
		  wait(NULL);
		  
		}*/	
		
	    /*}else{ passage de la valeur sélectionné au processus enfant
		récupère la sélection 
		if(valeur != MAX ){
		  
		  debug 
		  printf(" debug 1\n");
		  
		  selec = appel(etg);*/
		  
		 /* logg(etg, fonctionCourante,messageProcessus, typeErreurPasGrave);
		  close(pereVersFilsEnEciture[0]);
		  sprintf(pereVersFilsEnEcriture,"%d", selec);
		  write(pereVersFilsEnEciture[1], &pereVersFilsEnEcriture, BUFFER_SIZE);
		  wait(NULL);
		}*/
		/*récupère la valeur de retour du fils
		close(filsVersPereEnEciture[1]);
		read(filsVersPereEnEciture[0], &filsVersPereEnLecture, BUFFER_SIZE);
		valeur = (int)filsVersPereEnLecture;*/	
		
	    /*}*/      
	}while (etg < MIN || etg > MAX);
       /* if ....do...while*/
    }while (etg != 11);
       /* logg(etg, fonctionCourante,"arrêt ascenseur", typeErreurPasGrave) ;*/
	printf("Arrêt ascenseur\n");
    return 0;
}



