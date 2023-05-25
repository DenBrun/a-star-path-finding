#include "Queue.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Queue q(5);
    cout << q.toString() << endl;
    q.insert(2);
    q.insert(3);
    q.insert(4);
    q.insert(5);
    q.extract();
    cout << q.toString() << endl;
    q.insert(6);
    q.insert(7);
    q.insert(8);
    q.insert(9);
    cout << q.toString() << endl;
    return 0;
}
