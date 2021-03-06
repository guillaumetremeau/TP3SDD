all: tp3

tp3: dictionnaire.o pile.o main.o 
	gcc -o tp3.out -g dictionnaire.o pile.o main.o

dictionnaire.o: dictionnaire.c
	gcc -o dictionnaire.o -c dictionnaire.c -Wall -Wextra -ansi -pedantic

pile.o: pile.c
	gcc -o pile.o -c pile.c -Wall -Wextra -ansi -pedantic

main.o: main.c dictionnaire.h
	gcc -o main.o -c main.c -Wextra -Wall -ansi -pedantic

clean:
	rm -rf *.o

mrproper: clean
	rm -rf tp3.out
