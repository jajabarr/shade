all: run

run: shade.exe
	./shade.exe
	
shade: 
	g++ -lncurses -std=c++11 -Wall -Werror -pedantic Main.cpp Object.cpp Position.cpp World.cpp -o shade.exe 

debug: 
	valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all ./shade.exe





	 
