#include "MazeParser.h"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

#define RESET "\033[0m"
#define MAGENTA "\033[35m"

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

void MazeParser::printMaze(const vector<vector<int>> &maze_vector, const vector<Node> &path)
{
    vector<vector<string>> res;
    res.reserve(maze_vector.size());

    const string wallSymbol = "X";
    const string emptySymbol = " ";

    char pathSymbol = '1';

    for (const auto &rowVector : maze_vector)
    {
        vector<string> row;
        row.reserve(rowVector.size());

        for (int c : rowVector)
        {
            if (c == 0)
            {
                row.push_back(wallSymbol);
            }
            else if (c == 1)
            {
                row.push_back(emptySymbol);
            }
        }

        res.push_back(move(row));
    }

    for (const auto &node : path)
    {
        res[node.y][node.x] = MAGENTA + string(1, pathSymbol) + RESET;
        pathSymbol = this->incrementSymbol(pathSymbol);
    }

    for (const auto &row : res)
    {
        for (const auto &c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}

char MazeParser::incrementSymbol(char symbol)
{
    if (symbol == '9')
    {
        return 'a';
    }
    else if (symbol == 'z')
    {
        return 'A';
    }
    else if (symbol == 'Z')
    {
        return '0';
    }
    else
    {
        return symbol + 1;
    }
}

void MazeParser::generateAndSaveMaze(int width, int height, const string &filename)
{
    vector<string> maze(height + 1, string(width + 1, ' ')); // Initialize the maze with spaces

    srand(static_cast<unsigned int>(time(nullptr)));

    // Create outer bounds as walls
    for (int i = 0; i < width + 1; i++)
    {
        maze[0][i] = 'X';
        maze[height][i] = 'X';
    }

    for (int i = 0; i < height + 1; i++)
    {
        maze[i][0] = 'X';
        maze[i][width] = 'X';
    }

    // Generate the maze paths
    for (int y = 2; y < height; y += 2)
    {
        for (int x = 2; x < width; x += 4)
        {
            maze[y][x] = 'X'; // Create walls

            // Randomly remove walls
            if (x != width - 2)
            {
                if (rand() % 2 == 0)
                {
                    maze[y][x + 1] = 'X';
                }
            }

            if (y != height - 2)
            {
                if (rand() % 2 == 0)
                {
                    maze[y + 1][x] = 'X';
                }
            }
        }
    }

    // Add an extra space between each element in a row
    for (auto &row : maze)
    {
        string modifiedRow;
        for (char c : row)
        {
            modifiedRow += c;
            modifiedRow += ' ';
        }
        row = modifiedRow;
    }

    ofstream file(filename);
    if (file.is_open())
    {
        for (const auto &row : maze)
        {
            file << row << endl;
        }
        file.close();
        cout << "Maze saved to " << filename << endl;
    }
    else
    {
        cerr << "Failed to save the maze to " << filename << endl;
    }
}