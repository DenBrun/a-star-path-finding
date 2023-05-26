#include "Maze.h"
#include <iostream>

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