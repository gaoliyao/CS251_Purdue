#include <iostream>
#include "circular_deque.h"

using namespace std;

Deque::Deque()
{
    //TODO: Write the Deque constructor
    //NOTE: Start with an array of size 2!
    this->size = 0;
    this->max = 2;
    this->array = (int *) malloc(2 * sizeof(int *));
}

void Deque::enqueue_front(int n)
{
    //TODO: Front enqueue method
    if (this->size + 1 >= max) {
        int* new_array = (int *) malloc(this->max * 2 * sizeof(int *));
        for (int i = 0; i < this->max; i++) {
            array[i] = this->array[i];
        }
        this->max *= 2;
        this->array = new_array;
    }
    for (int i = this->size + 1; i > 0; i--) {
        this->array[i] = this->array[i - 1];
    }
    this->array[0] = n;
    this->size++;
}

void Deque::enqueue_back(int n)
{
    //TODO: Back enqueue
    if (this->size + 1 >= max) {
        int* new_array = (int *) malloc(this->max * 2 * sizeof(int *));
        for (int i = 0; i < this->max; i++) {
            array[i] = this->array[i];
        }
        this->max *= 2;
        this->array = new_array;
    }
    this->array[this->size] = n;
    this->size++;
}

int Deque::dequeue_front()
{
    int element;
    //TODO: front dequeue
    if (this->size == 0) {
        return -1;
    }
    element = this->array[0];
    for (int i = 0; i < this->size; i++) {
        this->array[i] = this->array[i + 1];
    }
    this->size--;
    this->array[this->size] = -1;
    return element;
}

int Deque::dequeue_back()
{
    int element;
    if (this->size == 0) {
        return -1;
    }
    //TODO: back dequeue
    this->size--;
    element = this->array[this->size];
    this->array[this->size] = -1;
    return element;
}

int Deque::print_array_size()
{
    int size;
    //TODO: get the size of the allocated array
    size = this->size;
    cout << size << endl;
    return size;
}

int Deque::print_front_index()
{
    int index;
    //TODO: get the front index
    if (this->size == 0) {
        index = -1;
    }
    index = this->array[0];
    cout << index << endl;
    return index;
}

int Deque::print_rear_index()
{
    int index;
    //TODO: get the rear index
    if (this->size == 0) {
        index = -1;
    }
    index = this->array[this->size - 1];
    cout << index << endl;
    return index;
}
