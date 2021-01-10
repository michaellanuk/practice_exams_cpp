#include <iostream>
#include <cassert>
#include "maze.h"

using namespace std;

int main() {

  char **maze;
  int height, width;

  cout << "Loading simple maze...";
  
  maze = load_maze("simple.txt", height, width);
  assert(maze);
  cout << " done (height = " << height << ", width = " << width << ")." << endl << endl;

  cout << "Printing simple maze:" << endl;
  
  print_maze(maze,height,width);
  cout << endl;

  cout << "====================== Question 1 ======================" << endl << endl;

  int row = 0, column = 0;
  cout << "Finding the entrance:" << endl;
  find_marker('>', maze, height, width, row, column);
  cout << "The entrance is at row " << row << " column " << column << endl << endl;

  cout << "Finding the exit:" << endl;
  find_marker('X', maze, height, width, row, column);
  cout << "The exit is at row " << row << " column " << column << endl << endl;
  
  cout << "====================== Question 2 ======================" << endl << endl;

  cout << "The move sequence 'EEEEESEENN' is ";
  if (!valid_solution("EEEEESEENN", maze, height, width))
    cout << "NOT ";
  cout << "a solution to the maze" << endl << endl;

  cout << "The move sequence 'EEEEEEEESSSSSS' is ";
  if (!valid_solution("EEEEEEEESSSSSS", maze, height, width))
    cout << "NOT ";
  cout << "a solution to the maze" << endl << endl;

  cout << "The move sequence 'ESSSSSSEEEEEEE' is ";
  if (!valid_solution("ESSSSSSEEEEEEE", maze, height, width))
    cout << "NOT ";
  cout << "a solution to the maze" << endl << endl;
  
  cout << "====================== Question 3 ======================" << endl << endl;

  cout << "A path through the maze from '>' to 'X' is: " << endl;
  cout << find_path(maze, height, width, '>', 'X') << endl << endl;

  cout << "The path is shown below: " << endl;
  print_maze(maze, height, width);
  cout << endl;

  deallocate_2D_array(maze, height);

  cout << "======================= The End ========================" << endl << endl;

  return 0;
}
