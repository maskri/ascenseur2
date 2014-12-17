/*DEFINTIONS DES BIBLIOTHEQUES */
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
/*DEFINITIONS DES BIBLIOTHEQUES PERSONNELLES*/
#include "deplacement.h"
#include "log.h"
/* DEFINTIONS des CONSTANTES*/
#define BUFFER_SIZE 256

/*DEFINITION DES PROTOTYPES DES FONCTIONS*/
int appel(int etg);
int selection(int etg);
int saisieEntier(char chaine[], int etg);
int deplacement(int a, int asc);
void log(int eCourant, char* fonction, char* message, char* severity);
/*DEFINITION DES CONSTANTES*/
int MIN = -3, MAX = 11;

/* ENTREE DU PROGRAMME */
int main(int argc, char* argv[], char** envp){

    /*D�finitions des variables*/
    int pid_fils;
    int tube[2];
    unsigned char bufferR[256], bufferW[256];
    int etg = 0, selec;
    
    /*boucle principale*/
    do{
        do{
	    /*cr�ation du tube*/
	    if(pipe(tube) != 0){
	       log(etg, "main","Erreur dans le pipe", "Error");
	       exit(1);	
	    }    
	    /*teste la cr�ation du processus*/
	    if((pid_fils = fork()) == -1){
		 log(etg, "main","processus enfant", "Error");
		 exit(1);
	    }      
	    /*r�cup�re la s�lection */
            selec = appel(etg);
	    
	    /*r�cup�ration de la valeur */
	    if(pid_fils == 0){
		log(etg, "main","processus enfant", "Notice");
		close(tube[1]);
		read(tube[0], bufferR, BUFFER_SIZE);
		int valeur = atoi(bufferR);
		
		/*teste si on execute la suite du programme*/
		if (valeur != MAX){
		   etg = deplacement(valeur, etg); 
		   do				
		      valeur = selection(etg);     
		   while (valeur < MIN || valeur > MAX-1);
		      etg = deplacement(valeur, etg);
		}	
		
	    }else{/* passage de la valeur s�lectionn� au processus enfant*/
		log(etg, "main","processus p�re", "Notice");
		close(tube[0]);
		sprintf(bufferW,"%d", selec);
		write(tube[1], bufferW, BUFFER_SIZE);
		wait(NULL);
		
	    }  
	    
	}while (selec < MIN || selec > MAX);
       /* if (selec != MAX){
            etg = deplacement(selec, etg);
            do
                selec = selection(etg);
            while (selec < MIN || selec > MAX-1);
                etg = deplacement(selec, etg);
        }*/
    }
    while (selec != 11);
        log(etg, "main","arr�t ascenseur", "Notice") ;
	printf("Arr�t ascenseur\n");
    return (0);
}

/*Fonction qui permet d'appeler l'ascenseur
  @return       etg   int :   �tage s�lectionn�*/
int appel(int etg){
    char chaine[50];
    sprintf(chaine, "A quel etage etes vous ?\n");
    printf("Appel ascenseur\n");
    int valeur = saisieEntier(chaine, etg);
    log(valeur, "appel","Appel ascenseur", "Notice");
    return valeur;
}

/*Fonction qui permet de s�l�ctionner l'�tage que l'on veut atteindre
  @return       selec   int :   �tage s�lectionn�*/
int selection(int etg){
    char chaine[50];
    sprintf(chaine, "Selection etage ? [de %d a %d] \n", MIN, MAX);
    int valeur = saisieEntier(chaine, etg);
    log(valeur, "selection","Selection etage", "Notice");
    return valeur;
}

/*Fonction qui g�re les erreurs pour la saisie d'un entier
  @params       chaine  char[]:   texte � afficher
  @return       input   int  :    entier saisie par utilisateur*/
int saisieEntier(char chaine[], int etg){
  
    int input = -100, bool, k;
    
    do{
      
        printf("%s\n",chaine);	
	k = scanf("%d",&input);
	scanf("%*[^\n]");
	getchar();
	
        if( k == 0){	  
            printf("Erreur de saisie !\n");
	    bool = 0;
        }else{
	    bool = 1;
	}

	if(input == -100){
	   log(etg, "saisieEntier","saisieEntier", "Error");
	}else{
	   log(input, "saisieEntier","saisieEntier", "Notice");
	}
	
	
    }while (bool == 0);
    
    return (input);
}

