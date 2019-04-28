HEADERS = doublyLinkedList.h

default: main

doublyLinkedList.o: doublyLinkedList.c $(HEADERS)
	gcc -c doublyLinkedList.c -o doublyLinkedList.o

main.o: main.c $(HEADERS)
	gcc -c main.c -o main.o

main: main.o doublyLinkedList.o
	gcc main.o doublyLinkedList.o -o test

clean:
	-rm -f main.o
	-rm -f doublyLinkedList.o
	-rm -f test