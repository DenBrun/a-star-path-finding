#include "MazeParser.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    MazeParser parser = MazeParser();
    Maze maze = parser.parseMazeFile("input.txt");

    maze.print();

    vector<Node> res = maze.find_shortest_path(Node(1, 6), Node(8, 2));

    for (const auto &node : res)
    {
        cout << "(" << node.x << ", " << node.y << ") ";
    }
    cout << endl;

    parser.printMaze(maze.get_maze_vector(), res);
    return 0;
}