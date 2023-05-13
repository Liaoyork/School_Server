all: hw2-2
hw2-2: hw2-2.o main.o 
	g++ hw2-2.o main.o -o hw2-2
main.o: main.cpp
	g++ main.cpp -c
hw2-2.o: hw2-2.cpp
	g++ hw2-2.cpp -c
clean:
	rm *.o
	rm hw2-2
