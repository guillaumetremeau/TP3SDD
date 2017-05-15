all: tp3

tp3: dictionnaire.o pile.o rech.o main.o 
	gcc -o tp3.out dictionnaire.o pile.o rech.o  main.o

dictionnaire.o: dictionnaire.c
	gcc -o dictionnaire.o -c dictionnaire.c -Wall -Wextra -ansi -pedantic

pile.o: pile.c
	gcc -o pile.o -c pile.c -Wall -Wextra -ansi -pedantic

rech.o:	rech.c
	gcc -o rech.o -c rech.c -Wall -Wextra -ansi -pedantic

main.o: main.c dictionnaire.h
	gcc -o main.o -c main.c -Wextra -Wall -ansi -pedantic

clean:
	rm -rf *.o

mrproper: clean
	rm -rf tp3.out
