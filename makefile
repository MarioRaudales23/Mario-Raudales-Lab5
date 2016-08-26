main: main.o matriz.o
		g++ main.o matriz.o -o main

main.o: main.cpp matriz.h
		g++ -c main.cpp

matriz.o: matriz.h matriz.cpp
		g++ -c matriz.cpp
