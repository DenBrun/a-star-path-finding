#include <string>
class Queue
{
private:
    int *arr;
    int capacity;
    int size;
    int front;
    int back;
    void resize();

public:
    Queue(int capacity);
    ~Queue();

    int extract();
    void insert(int item);
    int get_front();
    int get_size();
    bool isEmpty();
    bool isFull();
    std::string toString();
};
