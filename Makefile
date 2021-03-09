all: main main2 main3 main4

main : entreeSortieLC.o biblioLC.o main.o
	gcc entreeSortieLC.o biblioLC.o main.o -o main

main2: main2.o entreeSortieH.o biblioH.o
	gcc entreeSortieH.o biblioH.o main2.o -o main2

main3: main3.o entreeSortieH.o biblioH.o entreeSortieLC.o biblioLC.o
	gcc entreeSortieLC.o biblioLC.o entreeSortieH.o biblioH.o main3.o -o main3

main4: main4.o entreeSortieH.o biblioH.o entreeSortieLC.o biblioLC.o
	gcc entreeSortieLC.o biblioLC.o entreeSortieH.o biblioH.o main4.o -o main4

biblioLC.o: biblioLC.c biblioLC.h
	gcc -c biblioLC.c -o biblioLC.o

biblioH.o: biblioH.c biblioH.h
	gcc -c biblioH.c -o biblioH.o

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h biblioLC.h
	gcc -c entreeSortieLC.c -o entreeSortieLC.o

entreeSortieH.o: entreeSortieH.c entreeSortieH.h biblioH.h
	gcc -c entreeSortieH.c -o entreeSortieH.o

main.o: main.c entreeSortieLC.h biblioLC.h
	gcc -c main.c -o main.o

main2.o: main2.c entreeSortieH.h biblioH.h
	gcc -c main2.c -o main2.o

main3.o: main3.c entreeSortieLC.h biblioLC.h entreeSortieH.h biblioH.h
	gcc -c main3.c -o main3.o

main4.o: main4.c entreeSortieLC.h biblioLC.h entreeSortieH.h biblioH.h
	gcc -c main4.c -o main4.o

clean: rm-f*.o rm-f main
