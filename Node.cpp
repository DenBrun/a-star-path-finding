#include "Node.h"

Node::Node(int x, int y) : x(x), y(y){};

bool Node::operator==(Node n)
{
    return this->x == n.x && this->y == n.y;
}

Node Node::operator+(const Node other)
{
    return Node(this->x + other.x, this->y + other.y);
}