HEADERS = person.h addition.h

default: main

addition.o: addition.c $(HEADERS)
	gcc -c addition.c -o addition.o

main.o: main.c $(HEADERS)
	gcc -c main.c -o main.o

main: main.o addition.o
	gcc main.o addition.o -o executable

clean:
	-rm -f main.o
	-rm -f addition.o
	-rm -f executable