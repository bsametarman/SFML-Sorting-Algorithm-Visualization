all: compile link

compile:
	g++ -c main.cpp -I"C:\libraries\SFML-2.5.1\include"

link:
	g++ main.o -o sfml-app -L"C:\libraries\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system -lmingw32