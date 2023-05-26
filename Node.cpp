#include "Node.h"

Node::Node(int x, int y) : location(Location{x, y}), came_from(nullptr), cost(0){};

Location Node::getLocation()
{
    return this->location;
}

bool Node::operator==(Node n)
{
    return this->location.x == n.getLocation().x && this->location.y == n.getLocation().y;
}