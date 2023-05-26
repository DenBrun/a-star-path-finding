#include "Queue.h"
#include "MazeParser.h"
using namespace std;

int main(int argc, char const *argv[])
{
    MazeParser parser = MazeParser();
    Maze maze = parser.parseMazeFile("input.txt");

    maze.print();

    return 0;
}