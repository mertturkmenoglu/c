HEADERS = numeric.h

default: main

bisection.o: bisection.c $(HEADERS)
	gcc -c bisection.c -o bisection.o

calculus.o: calculus.c $(HEADERS)
	gcc -c calculus.c -o calculus.o

graphic.o: graphic.c $(HEADERS)
	gcc -c graphic.c -o graphic.o

matrix.o: matrix.c $(HEADERS)
	gcc -c matrix.c -o matrix.o

newtonRhapson.o: newtonRhapson.c $(HEADERS)
	gcc -c newtonRhapson.c -o newtonRhapson.o

regulaFalse.o: regulaFalse.c $(HEADERS)
	gcc -c regulaFalse.c -o regulaFalse.o

main.o: main.c $(HEADERS)
	gcc -c main.c -o main.o

main: main.o bisection.o calculus.o graphic.o matrix.o newtonRhapson.o regulaFalse.o
	gcc main.o bisection.o calculus.o graphic.o matrix.o newtonRhapson.o regulaFalse.o -o numericalAnalysis

clean:
	-rm -f main.o
	-rm -f bisection.o
	-rm -f calculus.o
	-rm -f graphic.o
	-rm -f matrix.o
	-rm -f newtonRhapson.o
	-rm -f regulaFalse.o
	-rm -f executable