#include "MazeParser.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    MazeParser parser = MazeParser();
    try
    {
        parser.generateAndSaveMaze(40, 20, "maze.txt");
        Maze maze = parser.parseMazeFile("maze.txt");

        vector<Node> res = maze.find_shortest_path(Node(1, 6), Node(39, 8));
        // vector<Node> res = maze.find_shortest_path(Node(1, 5), Node(6, 1));

        parser.printMaze(maze.get_maze_vector(), res);
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    catch (const exception &e)
    {
        cerr << "The problem during the program execution: " << e.what() << '\n';
    }

    return 0;
}