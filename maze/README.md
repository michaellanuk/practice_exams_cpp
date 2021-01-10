# Maze

A hedge maze1 is an outdoor maze or labyrinth in which the “walls” between passages are made of vertical hedges.

In this program a maze is represented as a rectangular two- dimensional array of characters, using the “barrier” 
characters ’-’, ’+’ and ’|’ for hedges and (unique) “marker” characters to denote points of interest; here ’>’ 
represents the entrance, ’X’ the exit, and ’U’ an unreachable square.

A solution path through the maze is a sequence of directions from one marker character to another using the 
letters N, S, E and W for north, south, east and west respectively. The path must not pass through any hedges 
or pass outside the boundaries of the maze. Hence a valid solution path for the example maze from the entrance 
to the exit is “ESSSSSSEEEEEEE”. Although it leads from the entrance to the exit, the path “EEEEEEEESSSSSS” is 
not a valid solution path since it passes through hedges.

example output:

```
Printing simple maze:
              
     012345678
   0 +-+-+-+-+
   1 >     |U|
   2 + +-+ +-+
   3 | | |   |
   4 + + +-+-+
   5 |   |   |
   6 + +-+-+ +
   7 |       X
   8 +-+-+-+-+

Finding the entrance:
The entrance is at row 1 column 0

Finding the exit:
The exit is at row 7 column 8

The move sequence 'EEEEESEENN' is NOT a solution to the maze

The move sequence 'EEEEEEEESSSSSS' is NOT a solution to the maze

The move sequence 'ESSSSSSEEEEEEE' is a solution to the maze

A path through the maze from '>' to 'X' is: 
ESSSSSSEEEEEEE

The path is shown below: 
              
     012345678
   0 +-+-+-+-+
   1 ##    |U|
   2 +#+-+ +-+
   3 |#| |   |
   4 +#+ +-+-+
   5 |#  |   |
   6 +#+-+-+ +
   7 |#######X
   8 +-+-+-+-+
```
