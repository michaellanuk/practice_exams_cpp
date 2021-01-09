EXE = playfair

OBJ = main.o playfair.o

CXX = g++
CXXFLAGS = -Wall -g -std=c++11

$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

playfair.o: playfair.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean :
	rm -f $(OBJ) $(EXE)