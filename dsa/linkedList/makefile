HEADERS = linkedList.h

default: main

linkedList.o: linkedList.c $(HEADERS)
	gcc -c linkedList.c -o linkedList.o

main.o: main.c $(HEADERS)
	gcc -c main.c -o main.o

main: main.o linkedList.o
	gcc main.o linkedList.o -o test

clean:
	-rm -f main.o
	-rm -f linkedList.o
	-rm -f test