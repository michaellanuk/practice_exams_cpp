#ifndef MAZE_H
#define MAZE_H

char **allocate_2D_array(int rows, int columns);
void deallocate_2D_array(char **m, int rows);
char **load_maze(const char *filename, int &height, int &width);
void print_maze(char **m, int height, int width);
bool find_marker(char ch, char **maze, int height, int width, int &row, 
   int &col);
bool valid_solution(std::string path, char **maze, int height, int width);
std::string find_path(char **maze, int height, int width, char start, 
   char end);
bool find_path_r(char **maze, int height, int width, int row, int col, 
   int end_row, int end_col, std::string &path);

#endif