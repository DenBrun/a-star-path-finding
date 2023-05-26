class Node
{
private:
public:
    int x, y;
    Node(int x, int y);
    bool operator==(Node n);
    Node operator+(const Node other);
};
