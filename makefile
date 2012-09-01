all: insertionSort

clean:
	rm insertionSort.o insertionSort

insertionSort: insertionSort.o
	g++ -g -o insertionSort insertionSort.o

insertionSort.o: insertionSort.cpp
	g++ -c -g insertionSort.cpp