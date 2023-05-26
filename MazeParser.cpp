#include "MazeParser.h"
#include <iostream>
#include <fstream>

Maze MazeParser::parseMazeFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    vector<vector<int>> maze;
    string line;

    while (getline(file, line))
    {
        vector<int> row;
        for (size_t i = 0; i < line.length(); i = i + 2)
        {
            char c = line[i];
            if (c == 'X')
            {
                row.push_back(0);
            }
            else if (c == ' ')
            {
                row.push_back(1);
            }
        }
        if (!row.empty())
        {
            maze.push_back(row);
        }
    }

    file.close();
    return Maze(maze);
}
