main: main.cpp LinkedList.cpp LinkedList.h LinkedListInterface.h
	g++ -std=c++11 main.cpp LinkedList.cpp -o main
debugged: main.cpp
	g++ -std=c++11 main.cpp -o debugged -g