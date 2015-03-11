#include <stdio.h>


/*Fonction qui gère les erreurs pour la saisie d'un entier
  @params       chaine  char[]:   texte à afficher
  @return       input   int  :    entier saisie par utilisateur*/
int saisieEntier(char chaine[50] , int etg){/**/
    int input = -100, bool = 0, k = 0;
    
    /* debug 2*/
    printf("debug 2\n");
    
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
	printf("%d",etg);
	/*
	if(input == -100){
	   logg(etg, "saisieEntier","saisieEntier", "Error");
	}else{
	   logg(input, "saisieEntier","saisieEntier", "Notice");
	}*/
	
    }while (bool == 0);
    return (input);
}