all: main 

main : entreeSortieLC.o biblioLC.o main.o
	gcc entreeSortieLC.o biblioLC.o main.o -o main

biblioLC.o: biblioLC.c biblioLC.h
	gcc -c biblioLC.c -o biblioLC.o

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h biblioLC.h
	gcc -c entreeSortieLC.c -o entreeSortieLC.o

main.o: main.c entreeSortieLC.h biblioLC.h
	gcc -c main.c -o main.o

clean: rm-f*.o rm-f main
