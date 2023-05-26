#include "Maze.h"
#include <iostream>
#include <algorithm>

Maze::Maze(vector<vector<int>> maze_vector)
{
    this->maze_vector = maze_vector;
}

void Maze::print()
{
    cout << '[' << endl;
    for (size_t i = 0; i < this->maze_vector.size(); ++i)
    {
        cout << "  [";
        for (size_t j = 0; j < this->maze_vector[i].size(); ++j)
        {
            cout << this->maze_vector[i][j];
            if (j != this->maze_vector[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << ']';
        if (i != this->maze_vector.size() - 1)
        {
            cout << ',' << endl;
        }
    }
    cout << endl
         << ']' << endl;
}

bool Maze::in_bounds(Node loc)
{
    return this->maze_vector.size() > loc.y && this->maze_vector[loc.y].size() > loc.x;
}

bool Maze::passable(Node loc)
{
    return this->maze_vector[loc.y][loc.x] != 0;
}

vector<Node> Maze::get_neighbors(Node node)
{
    if (!this->in_bounds(node) || !this->passable(node))
    {
        return {};
    }

    Node directions[4] = {Node(1, 0),
                          Node(-1, 0),
                          Node(0, -1),
                          Node(0, 1)};

    vector<Node> results;

    for (auto &dir : directions)
    {
        Node next = node + dir;
        if (in_bounds(next) && passable(next))
        {
            results.push_back(Node(next.x, next.y));
        }
    }

    if ((node.x + node.y) % 2 == 0)
    {
        reverse(results.begin(), results.end());
    }

    return results;
}