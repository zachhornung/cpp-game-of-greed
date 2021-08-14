game_of_greed:	main.o game_functions.o game_logic.o game.o
	g++ main.o game_functions.o game_logic.o game.o -o game_of_greed

main.o: main.cpp
	g++ -c main.cpp

game_functions.o: implimentation_files/game_functions.cpp header_files/game_functions.h
	g++ -c implimentation_files/game_functions.cpp -o game_functions.o

game_logic.o: implimentation_files/game_logic.cpp header_files/game_logic.h
	g++ -c implimentation_files/game_logic.cpp -o game_logic.o

game.o: implimentation_files/game.cpp header_files/game.h
	g++ -c implimentation_files/game.cpp -o game.o

clean:
	rm *.o game_of_greed