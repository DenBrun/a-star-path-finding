#include <string>
class Node
{
private:
public:
    int x, y;
    Node(int x, int y);
    Node() = default;
    bool operator==(Node n) const;
    bool operator!=(Node n) const;
    Node operator+(const Node other);
    std::string to_string();
};
