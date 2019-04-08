default: main

main.o: main.c
	gcc -c main.c -o main.o -lm

main: main.o
	gcc main.o -o prime -lm

clean:
	-rm -f main.o
	-rm -f prime