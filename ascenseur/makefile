CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC= ascenseur

all: $(EXEC)

ascenseur: log.o deplacement.o main.o
	$(CC) -o ascenseur log.o deplacement.o main.o $(LDFLAGS)
	
log.o: log.c
	$(CC) -o log.o -c log.c $(CFLAGS)
	
deplacement.o: deplacement.c
	$(CC) -o deplacement.o -c deplacement.c $(CFLAGS)
	
main.o: main.c log.h deplacement.h
	$(CC) -o main.o -c main.c $(CFLAGS) 
		
clean:
	rm -rf *.o
	
mrproper: clean
	rm -rf $(EXEC)