EXE = soundex

OBJ = main.o soundex.o

CXX = g++
CXXFLAGS = -Wall -g -std=c++11

$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

soundex.o: soundex.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean :
	rm -f $(OBJ) $(EXE)