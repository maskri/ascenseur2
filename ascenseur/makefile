CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC= ascenseur

all: $(EXEC)

ascenseur: deplacement.o main.o
	$(CC) -o ascenseur deplacement.o main.o $(LDFLAGS)
	
deplacement.o: deplacement.c
	$(CC) -o deplacement.o -c deplacement.c $(CFLAGS)
	
main.o: main.c deplacement.h
	$(CC) -o main.o -c main.c $(CFLAGS) 
		
clean:
	rm -rf *.o
	
mrproper: clean
	rm -rf $(EXEC)