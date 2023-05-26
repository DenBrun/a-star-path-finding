#include <vector>
#include <string>
#include "Node.h"
using namespace std;

class Maze
{
private:
    vector<vector<int>> maze_vector;
    bool in_bounds(Node loc);
    bool passable(Node loc);

public:
    Maze(vector<vector<int>> maze_vector);
    void print();
    vector<Node> get_neighbors(Node node);
};
