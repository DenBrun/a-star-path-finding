#include "Queue.h"
#include <stdexcept>
#include <sstream>

Queue::Queue(int capacity)
{
    this->arr = new int[capacity];
    this->capacity = capacity;
    this->front = 0;
    this->back = -1;
    this->size = 0;
}

Queue::~Queue()
{
    delete[] arr;
}

void Queue::resize()
{
    int newCapacity = this->capacity * 2;
    int *newArr = new int[newCapacity];

    for (int i = 0; i < this->size; i++)
    {
        newArr[i] = this->arr[(this->front + i) % this->capacity];
    }

    this->front = 0;
    this->back = this->size - 1;

    delete[] this->arr;
    this->arr = newArr;
    this->capacity = newCapacity;
}

int Queue::extract()
{
    if (this->isEmpty())
    {
        throw std::underflow_error("Failed to extract an item from an empty queue.");
    }
    int item = this->arr[this->front];
    this->front = (this->front + 1) % this->capacity;
    this->size--;

    return item;
}

void Queue::insert(int item)
{
    if (this->isFull())
    {
        this->resize();
    }
    this->back = (this->back + 1) % this->capacity;
    this->arr[back] = item;
    this->size++;
}

int Queue::get_front()
{
    if (this->isEmpty())
    {
        throw std::underflow_error("Failed to get an item from an empty queue.");
    }
    return this->arr[this->front];
}

int Queue::get_size()
{
    return this->size;
}

bool Queue::isEmpty()
{
    return (this->size == 0);
}

bool Queue::isFull()
{
    return (this->size == this->capacity);
}

std::string Queue::toString()
{
    std::stringstream ss;

    if (this->isEmpty())
    {
        ss << "Queue is empty";
    }
    else
    {
        ss << "Queue elements: ";
        for (int i = 0; i < this->size; i++)
        {
            int index = (this->front + i) % this->capacity;
            ss << this->arr[index] << " ";
        }
    }

    return ss.str();
}