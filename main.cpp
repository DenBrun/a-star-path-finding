#include "MazeParser.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    MazeParser parser = MazeParser();
    Maze maze = parser.parseMazeFile("input.txt");

    maze.print();

    vector<Node> neighbors = maze.get_neighbors(Node(8, 3));

    return 0;
}