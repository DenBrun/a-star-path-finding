#include "MazeParser.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    MazeParser parser = MazeParser();
    Maze maze = parser.parseMazeFile("input.txt");

    maze.print();

    // vector<Node> neighbors = maze.get_neighbors(Node(8, 3));
    vector<Node> res = maze.find_shortest_path(Node(1, 1), Node(5, 4));

    for (const auto &node : res)
    {
        cout << "(" << node.x << ", " << node.y << ") ";
    }
    return 0;
}