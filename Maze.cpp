#include "Maze.h"
#include "PriorityQueue.h"
#include <iostream>
#include <algorithm>

namespace std
{
    template <>
    struct hash<Node>
    {
        size_t operator()(const Node &n) const noexcept
        {
            return hash<int>()(n.x ^ (n.y << 16));
        }
    };
}

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

vector<Node> Maze::find_shortest_path(Node start, Node end)
{
    if (!this->in_bounds(start) || !this->passable(start) || !this->in_bounds(end) || !this->passable(end))
    {
        throw invalid_argument("A Node can't be a wall or be outside the maze");
    }

    PriorityQueue<Node, double> frontier;
    unordered_map<Node, Node> previous;
    unordered_map<Node, double> curr_cost;

    frontier.put(start, 0);
    previous[start] = start;
    curr_cost[start] = 0;

    while (!frontier.is_empty())
    {
        Node current = frontier.get();
        // cout << "Frontier -> " << current.x << " " << current.y << endl;

        if (current == end)
        {
            break;
        }

        for (Node next : this->get_neighbors(current))
        {
            double new_cost = curr_cost[current] + 1;
            if (curr_cost.find(next) == curr_cost.end() || new_cost < curr_cost[next])
            {
                curr_cost[next] = new_cost;
                double priority = new_cost + this->heuristic(next, end);
                frontier.put(next, priority);
                previous[next] = current;
                // cout << next.x << " " << next.y << " priority: " << priority << endl;
            }
        }
        // cout << endl;
    }

    return this->trace_back(previous, start, end);
}

double Maze::heuristic(Node a, Node b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

vector<Node> Maze::trace_back(unordered_map<Node, Node> path, Node start, Node end)
{
    vector<Node> result;
    // result.push_back(end);
    Node curr = end;
    if (path.find(end) == path.end())
    {
        throw invalid_argument("Path between " + start.to_string() + " and " + end.to_string() + " doesn't exist.");
    }

    while (curr != start)
    {
        result.push_back(curr);
        curr = path[curr];
    }
    result.push_back(start);
    reverse(result.begin(), result.end());
    return result;
}

vector<vector<int>> Maze::get_maze_vector()
{
    return this->maze_vector;
}