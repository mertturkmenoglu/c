HEADERS = dsasort.h

default: main

bubbleSort.o: bubbleSort.c $(HEADERS)
	gcc -c bubbleSort.c -o bubbleSort.o

insertionSort.o: insertionSort.c $(HEADERS)
	gcc -c insertionSort.c -o insertionSort.o

selectionSort.o: selectionSort.c $(HEADERS)
	gcc -c selectionSort.c -o selectionSort.o

main.o: main.c $(HEADERS)
	gcc -c main.c -o main.o

main: main.o selectionSort.o insertionSort.o bubbleSort.o
	gcc main.o selectionSort.o insertionSort.o bubbleSort.o -o sort

clean:
	-rm -f main.o
	-rm -f selectionSort.o
	-rm -f insertionSort.o
	-rm -f bubbleSort.o
	-rm -f sort