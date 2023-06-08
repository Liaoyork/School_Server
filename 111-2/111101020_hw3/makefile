hw3-1: Button.o hw3-1.o Label.o TextInput.o View.o Window.o
	g++ Button.o hw3-1.o Label.o TextInput.o View.o Window.o -o hw3-1
	rm *.o
hw3-2: Button.o hw3-2.o Calculator.o Label.o Window.o View.o
	g++ Button.o hw3-2.o Calculator.o Label.o Window.o View.o -o hw3-2
	rm *.o
Button.o: Button.cpp
	g++ Button.cpp -c
hw3-1.o: hw3-1.cpp
	g++ hw3-1.cpp -c
hw3-2.o: hw3-2.cpp
	g++ hw3-2.cpp -c
Label.o: Label.cpp	
	g++ Label.cpp -c
TextInput.o: TextInput.cpp
	g++ TextInput.cpp -c
View.o: View.cpp
	g++ View.cpp -c
Window.o: Window.cpp
	g++ Window.cpp -c
Calculator.o: Calculator.cpp
	g++ Calculator.cpp -c
clean:
	rm *.o
