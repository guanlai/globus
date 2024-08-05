========================================================================
overview
This solution would find the shortest path between 2 points on 2D grid.
The path planner used A* algorithm, which is a variation of Breadth First
Search (BFS). By adding a heuristic value tells the likelyhood of optimal
path through each cell along the frontier. Thus, A* can find the target 
faster than BFS.

The solution contains 3 cpp files, 
the occ-grid.cpp is for mapping info
the path-planner.cpp is for planning and validating path
the main.cpp is for UI and test

For simplicity, this solution use a hard coded map and grid size (64x64). 
It can be expanded to take user input for the map json, and parse json
file to compute the grid dimension.
I have a 3rd party json.hpp to parse the json file.

========================================================================
How to use this solution
There is a Makefile to build the souce code. 
The build works on VScode in windows system, should also work on other system.
make clean seems not work for me, but it doesn't block test.
The input map is a json file, and I also included a screenshot of the map

When the build is done, run the executible file,
User would be asked to enter the start pose and target pose
If any of the pose is not free, it would ask user to enter again
Once user finish input, the program would print out the shortest path
between the start pose and target pose

use ctrl+c to exit the program
========================================================================
Sample test run and result:

PS C:\Users\ligua\Documents\globus> make        
g++ -c main.cpp
g++ main.o occ-grid.o path-planner.o -o output
PS C:\Users\ligua\Documents\globus> .\output.exe
enter start row col between [0,63]
15 18
enter target row col between [0,63]
40 45
target pose [40,45] is an obstacle
enter target row col between [0,63]
35 45
the shortest path from [15,18] to [35,45]:
[15,18]
[15,19]
[15,20]
[15,21]
[15,22]
[15,23]
[15,24]
[15,25]
[16,25]
[17,25]
[18,25]
[19,25]
[20,25]
[21,25]
[22,25]
[23,25]
[24,25]
[24,26]
[24,27]
[24,28]
[24,29]
[24,30]
[24,31]
[25,31]
[25,32]
[25,33]
[25,34]
[25,35]
[26,35]
[27,35]
[28,35]
[29,35]
[30,35]
[31,35]
[31,36]
[31,37]
[31,38]
[31,39]
[31,40]
[31,41]
[31,42]
[31,43]
[31,44]
[31,45]
[32,45]
[33,45]
[34,45]
[35,45]
enter start row col between [0,63]
enter target row col between [0,63]
PS C:\Users\ligua\Documents\globus>