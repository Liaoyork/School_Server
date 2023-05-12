all:7-2
7-2:main.o Triangle.o Square.o Shape.o Rect.o Circle.o
	g++ Circle.o main.o Triangle.o Shape.o Square.o Rect.o -o 7-2
Circle.o: Circle.cpp
	g++ Circle.cpp -c
main.o: main.cpp
	g++ main.cpp -c
Triangle.o: Triangle.cpp
	g++ Triangle.cpp -c
Square.o: Square.cpp
	g++ Square.cpp -c
Shape.o: Shape.cpp
	g++ Shape.cpp -c
Rect.o: Rect.cpp
	g++ Rect.cpp -c
clean:
	rm *.o
	rm 7-2
run:7-2
	./7-2
