#include <stdio.h>
#include <time.h>

/*Fonction qui permet de déplacer l'ascenseur de puis l'étage appellant jusqu'à l'étage désiré
  @params       a     int :   étage appelant
  @params       asc   int :   étage désiré
  @return       asc   int :   étage courant*/
int deplacement(int a, int asc){
    if (a > asc){
        do {
            printf("Etage:%d\n", asc);
            sleep(2);
        } while (++asc < a);
        printf("Arrive etage %d\n", asc);
    } else {
        do{
            printf("Etage:%d\n", asc);
            sleep(2);
        } while (--asc > a);
        printf("Arrivee etage %d\n", asc);
    }
    return (asc);
}