all: Notification.cpp Notification.hpp DynamicList.hpp user.cpp user.hpp menu.cpp menu.hpp Authentication.hpp Authentication.cpp FileHandler.hpp FileHandler.cpp main.cpp
	g++ -c Authentication.cpp
	g++ -c FileHandler.cpp
	g++ -c menu.cpp
	g++ -c main.cpp
	g++ -c user.cpp
	g++ -c Notification.cpp
	g++ Notification.o user.o menu.o FileHandler.o Authentication.o main.o -o exec

run: all
	./exec

clean: 
	rm -f *.o
	rm -f exec

valgrind:
    valgrind --leak-check=yes ./exec
