HEADERS = dsasort.h

default: main

bubbleSort.o: bubbleSort.c $(HEADERS)
	gcc -c bubbleSort.c -o bubbleSort.o

insertionSort.o: insertionSort.c $(HEADERS)
	gcc -c insertionSort.c -o insertionSort.o

mergeSort.o: mergeSort.c $(HEADERS)
	gcc -c mergeSort.c -o mergeSort.o

quickSort.o: quickSort.c $(HEADERS)
	gcc -c quickSort.c -o quickSort.o

selectionSort.o: selectionSort.c $(HEADERS)
	gcc -c selectionSort.c -o selectionSort.o

shellSort.o: shellSort.c $(HEADERS)
	gcc -c shellSort.c -o shellSort.o

main.o: main.c $(HEADERS)
	gcc -c main.c -o main.o

main: main.o bubbleSort.o insertionSort.o mergeSort.o quickSort.o selectionSort.o shellSort.o
	gcc main.o bubbleSort.o insertionSort.o mergeSort.o quickSort.o selectionSort.o shellSort.o -o sort

clean:
	-rm -f main.o
	-rm -f bubbleSort.o
	-rm -f insertionSort.o
	-rm -f mergeSort.o
	-rm -f quickSort.o
	-rm -f selectionSort.o
	-rm -f shellSort.o
	-rm -f sort