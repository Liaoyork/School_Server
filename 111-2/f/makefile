main: Healthy.o Food.o Commodity.o main.o
	g++ Healthy.o Food.o Commodity.o main.o -o main
Healthy.o: Healthy.cpp
	g++ Healthy.cpp -c
Food.o: Food.cpp
	g++ Food.cpp -c
Commodity.o: Commodity.cpp
	g++ Commodity.cpp -c
main.o: main.cpp
	g++ main.cpp -c
clean:
	rm *.o
