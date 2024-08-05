output: main.o occ-grid.o path-planner.o
	g++ main.o occ-grid.o path-planner.o -o output
main.o: main.cpp
	g++ -c main.cpp
occ-grid.o: occ-grid.cpp occ-grid.hpp
	g++ -c occ-grid.cpp
path-planner.o: path-planner.cpp path-planner.hpp
	g++ -c path-planner.cpp
clean:
	rm *.o output