#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <string>

using namespace std;

char **allocate_2D_array(int rows, int columns) {
  char **m = new char *[rows];
  assert(m);
  for (int r=0; r<rows; r++) {
    m[r] = new char[columns];
    assert(m[r]);
  }
  return m;
}

void deallocate_2D_array(char **m, int rows) {
  for (int r=0; r<rows; r++)
    delete [] m[r];
  delete [] m;
}

bool get_maze_dimensions(const char *filename, int &height, int &width) {
  char line[512];
  
  ifstream input(filename);

  height = width = 0;

  input.getline(line,512);  
  while (input) {
    if ( (int) strlen(line) > width)
      width = strlen(line);
    height++;
    input.getline(line,512);  
  }

  if (height > 0)
    return true;
  return false;
}

char **load_maze(const char *filename, int &height, int &width) {

  bool success = get_maze_dimensions(filename, height, width);
  
  if (!success)
    return NULL;

  char **m = allocate_2D_array(height, width);
  
  ifstream input(filename);

  char line[512];

  for (int r = 0; r<height; r++) {
    input.getline(line, 512);
    strcpy(m[r], line);
  }
  
  return m;
}

void print_maze(char **m, int height, int width) {
  cout << setw(4) << " " << " ";
  for (int c=0; c<width; c++)
    if (c && (c % 10) == 0) 
      cout << c/10;
    else
      cout << " ";
  cout << endl;

  cout << setw(4) << " " << " ";
  for (int c=0; c<width; c++)
    cout << (c % 10);
  cout << endl;

  for (int r=0; r<height; r++) {
    cout << setw(4) << r << " ";    
    for (int c=0; c<width; c++) 
      cout << m[r][c];
    cout << endl;
  }
}

bool find_marker(char ch, char **maze, int height, int width, int &row, 
  int &col) {
  row = -1;
  col = -1;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < height; j++) {
      if (maze[i][j] == ch) {
        row = i;
        col = j;
        return true;
      }
    }
  }
  
  return false;
}

bool valid_solution(std::string path, char **maze, int height, int width) {
  int current_row = 0, current_col = 0;

  char ch = '>';
  char current_ch;

  if (!find_marker(ch, maze, height, width, current_row, current_col)) {
    return false;
  }

  for (int i = 0; i < path.length(); i++) {
    if (path[i] == 'N') {
      current_row--;
    }
    if (path[i] == 'E') {
      current_col++;
    }
    if (path[i] == 'S') {
      current_row++;
    }
    if (path[i] =='W') {
      current_col--;
    }

    current_ch = maze[current_row][current_col];
    if (current_ch == '+' || current_ch == '-' || current_ch == 'U') {
      return false;
    }
  }

  if (current_ch == 'X') {
    return true;
  }

  return false;
}

bool find_path_r(char **maze, int height, int width, int row, int col, 
  int end_row, int end_col, std::string &path) {
  if (maze[row][col + 1] == 'X') {
    maze[row][col] = '#';
    path.push_back('E');
    return true;
  }
  if (maze[row][col - 1] == 'X') {
    maze[row][col] = '#';
    path.push_back('W');
    return true;
  }
  if (maze[row + 1][col] == 'X') {
    maze[row][col] = '#';
    path.push_back('S');
    return true;
  }
  if (maze[row - 1][col] == 'X') {
    maze[row][col] = '#';
    path.push_back('N');
    return true;
  }

  maze[row][col] = '#';

  if (col > 0 && (maze[row][col - 1] == ' ') && find_path_r(maze, height, 
    width, row, col - 1, end_row, end_col, path)) {
    path.push_back('W');
    maze[row][col] = '#';
    return true;
  }

  if (col < width - 1 && (maze[row][col + 1] == ' ') && find_path_r(maze, 
    height, width, row, col + 1, end_row, end_col, path)) {
    path.push_back('E');
    maze[row][col] = '#';
    return true;
  }

  if (row > 0 && (maze[row - 1][col] == ' ') && find_path_r(maze, height, 
    width, row - 1, col, end_row, end_col, path)) {
    path.push_back('N');
    maze[row][col] = '#';
    return true;
  }

  if (row < height - 1 && (maze[row + 1][col] == ' ') && find_path_r(maze, 
    height, width, row + 1, col, end_row, end_col, path)) {
    path.push_back('S');
    maze[row][col] = '#';
    return true;
  }

  maze[row][col] = ' ';
  
  return false;
} 

std::string find_path(char **maze, int height, int width, char start, 
  char end) {
  std::string path;

  int start_row = 0, start_col = 0, end_row = 0, end_col = 0;

  if (!find_marker('>', maze, height, width, start_row, start_col)) {
    return NULL;
  }

  if (!find_marker('X', maze, height, width, end_row, end_col)) {
    return NULL;
  }

  int current_row = start_row;
  int current_col = start_col;
  
  if (find_path_r(maze, height, width, current_row, current_col, end_row, 
    end_col, path)) {
    std::string actual_path;

    for (int i = path.length() - 1; i >= 0; i--) {
      actual_path.push_back(path[i]);
    }

    return actual_path;
  }

  return "no solution";
}

