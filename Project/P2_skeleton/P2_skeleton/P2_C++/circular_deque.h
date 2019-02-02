#include <iostream>
#include <malloc.h>

using namespace std;

class Deque
{
    int *array;
    int size;
    int max;
public:
    Deque();
    void enqueue_front(int);
    void enqueue_back(int);
    int dequeue_front();
    int dequeue_back();
    int print_array_size();
    int print_front_index();
    int print_rear_index();

};

