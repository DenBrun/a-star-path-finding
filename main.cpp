#include "MazeParser.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    MazeParser parser = MazeParser();
    parser.generateAndSaveMaze(40, 20, "maze.txt");
    Maze maze = parser.parseMazeFile("maze.txt");

    vector<Node> res = maze.find_shortest_path(Node(1, 6), Node(39, 8));
    // vector<Node> res = maze.find_shortest_path(Node(1, 6), Node(2, 9));

    parser.printMaze(maze.get_maze_vector(), res);
    return 0;
}