CC=gcc
CFLAGS=-Wall -Wextra -Werror --std=c99
LDFLAGS=
EXEC= ascenseur

all: $(EXEC)

ascenseur: logg.o deplacement.o saisieEntier.o appel.o selection.o main.o 
	$(CC) -o ascenseur logg.o deplacement.o saisieEntier.o appel.o selection.o main.o $(LDFLAGS)

main.o: main.c
	$(CC) -o main.o -c main.c $(CFLAGS)

logg.o: logg.c
	$(CC) -o logg.o -c logg.c $(CFLAGS)

deplacement.o: deplacement.c
	$(CC) -o deplacement.o -c deplacement.c $(CFLAGS)

saisieEntier.o: saisieEntier.c
	$(CC) -o saisieEntier.o -c saisieEntier.c $(CFLAGS)

appel.o: appel.c
	$(CC) -o appel.o -c appel.c $(CFLAGS)

selection.o: selection.c
	$(CC) -o selection.o -c selection.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)