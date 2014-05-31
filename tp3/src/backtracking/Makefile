CC=g++
CFLAGS=-c -Wall -pedantic
OBJS= backtracking.o Graph.o

.PHONY: clean

backtracking: $(OBJS)
	$(CC) -c backtracking.cpp -o backtracking.o
	$(CC) -c ../common/Graph.cpp -o Graph.o
	$(CC) -o backtracking $(OBJS)

clean:
	rm -f *.o backtracking
