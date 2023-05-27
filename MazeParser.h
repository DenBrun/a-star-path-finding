#include "Maze.h"
using namespace std;

class MazeParser
{
private:
    char incrementSymbol(char symbol);

public:
    Maze parseMazeFile(const string &filename);
    void printMaze(const vector<vector<int>> &maze_vector, const vector<Node> &path);
    void generateAndSaveMaze(int width, int height, const string &filename);
};
