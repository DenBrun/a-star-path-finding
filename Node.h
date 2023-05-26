struct Location
{
    int x;
    int y;
};

class Node
{
private:
    // int x, y;
    Location location;
    Node *came_from;
    float cost;

public:
    Node(int x, int y);
    Location getLocation();
    bool operator==(Node n);
};
