capa: main.o
	gcc -o capa.exe main.o -Wall -ansi -g

main.o: main.c
	gcc -o main.o -c main.c -Wall -ansi -g