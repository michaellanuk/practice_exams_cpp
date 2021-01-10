EXE = maze

OBJ = main.o maze.o

CXX = g++
CXXFLAGS = -Wall -g -std=c++11

$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

maze.o: maze.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean :
	rm -f $(OBJ) $(EXE)