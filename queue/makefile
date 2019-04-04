HEADERS = queue.h

default: main

queue.o: queue.c $(HEADERS)
	gcc -c queue.c -o queue.o

main.o: main.c $(HEADERS)
	gcc -c main.c -o main.o

main: main.o queue.o
	gcc main.o queue.o -o executable

clean:
	-rm -f main.o
	-rm -f queue.o
	-rm -f executable