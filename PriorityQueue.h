#pragma once

#include <queue>
#include <vector>

template <typename T, typename Priority>
class PriorityQueue
{
private:
    struct QueueElem
    {
        Priority priority;
        T item;

        bool operator<(const QueueElem &other) const
        {
            return priority > other.priority;
        }
    };

    std::priority_queue<QueueElem> elements;

public:
    bool is_empty() const
    {
        return elements.empty();
    }

    void put(const T &item, const Priority &priority)
    {
        elements.emplace(QueueElem{priority, item});
    }

    T get()
    {
        T top_item = elements.top().item;
        elements.pop();
        return top_item;
    }
};
