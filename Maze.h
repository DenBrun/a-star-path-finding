#include <vector>
#include <string>
#include "Node.h"
#include <unordered_map>
using namespace std;

class Maze
{
private:
    vector<vector<int>> maze_vector;
    bool in_bounds(Node loc);
    bool passable(Node loc);
    double heuristic(Node a, Node b);
    vector<Node> trace_back(unordered_map<Node, Node> path, Node start, Node end);

public:
    Maze(vector<vector<int>> maze_vector);
    void print();
    vector<Node> get_neighbors(Node node);
    vector<Node> find_shortest_path(Node start, Node end);
};
