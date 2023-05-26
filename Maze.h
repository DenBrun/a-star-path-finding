#include <vector>
#include <string>
using namespace std;

class Maze
{
private:
    vector<vector<int>> maze_vector;

public:
    Maze(vector<vector<int>> maze_vector);
    void print();
};
