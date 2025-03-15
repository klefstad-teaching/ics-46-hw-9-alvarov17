CXXFLAGS=-ggdb -std=c++20 -Werror -Wfatal-errors -pedantic

all: dijkstra_main ladder

ladder.o: ladder.cpp
	g++ $(CXXFLAGS) -c ladder.cpp -o ladder.o

ladder: ladder_main.cpp ladder.o
	g++ $(CXXFLAGS) ladder_main.cpp -o ladder ladder.o

dijkstra.o: dijkstras.cpp
	g++ $(CXXFLAGS) -c dijkstras.cpp -o dijkstras.o

dijkstra_main: dijkstras_main.cpp dijkstra.o
	g++ $(CXXFLAGS) dijkstras_main.cpp -o dijkstra_main dijkstras.o

clean:
	/bin/rm -f dijkstra_main dijkstra.o ladder ladder.o