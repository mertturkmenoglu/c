HEADERS = heap.h

default: main

heapify.o: heapify.c $(HEADERS)
	gcc -c heapify.c -o heapify.o

heapSort.o: heapSort.c $(HEADERS)
	gcc -c heapSort.c -o heapSort.o

main.o: main.c $(HEADERS)
	gcc -c main.c -o main.o

main: main.o heapify.o heapSort.o
	gcc main.o heapify.o heapSort.o -o heapTest

clean:
	-rm -f main.o
	-rm -f heapify.o
	-rm -f heapSort.o
	-rm -f heapTest