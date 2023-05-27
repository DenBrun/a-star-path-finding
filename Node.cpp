#include "Node.h"

Node::Node(int x, int y) : x(x), y(y){};

bool Node::operator==(Node n) const
{
    return this->x == n.x && this->y == n.y;
}

bool Node::operator!=(Node n) const
{
    return !(this->operator==(n));
}

Node Node::operator+(const Node other)
{
    return Node(this->x + other.x, this->y + other.y);
}

std::string Node::to_string()
{
    return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
}