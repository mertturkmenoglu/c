HEADERS = stack.h Boolean.h

default: main

stack.o: stack.c $(HEADERS)
	gcc -c stack.c -o stack.o

main.o: main.c $(HEADERS)
	gcc -c main.c -o main.o

main: main.o stack.o
	gcc main.o stack.o -o test

clean:
	-rm -f main.o
	-rm -f stack.o
	-rm -f test