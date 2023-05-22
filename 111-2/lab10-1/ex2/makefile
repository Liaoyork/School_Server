all:10-2
10-2: Point2D.o ex10-2.o Vector.h
	g++ Point2D.o ex10-2.o -o 10-2
Point2D.o: Point2D.cpp
	g++ Point2D.cpp -c
ex10-2.o: ex10-2.cpp
	g++ ex10-2.cpp -c

clean:
	rm *.o
	rm 10-2

