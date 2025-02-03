TNC: main.o board.o tile.o
	g++ main.o board.o tile.o -o TNC

main.o: main.cpp
	g++ -c main.cpp

board.o: board.cpp
	g++ -c board.cpp

tile.o: tile.cpp
	g++ -c tile.cpp

clean:
	rm *.o TNC