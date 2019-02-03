#include <iostream>
#include "circular_deque.h"

using namespace std;

Deque::Deque()
{
    //TODO: Write the Deque constructor
    //NOTE: Start with an array of size 2!
    this->size = 0;
    this->max = 2;
    this->rear_index = -1;
    this->front_index = -1;
    this->array = (int *) malloc(2 * sizeof(int *));
}

void Deque::enqueue_front(int n)
{
    //TODO: Front enqueue method
    if (this->size == 0) {
        this->array[0] = n;
        this->size++;
        this->front_index = this->rear_index = 0;
        return ;
    }
    if (this->size + 1 > this->max) {
        int* new_array = (int *) malloc(this->max * 2 * sizeof(int *));
        cout << "front index: " << this->front_index << endl;
        for (int i = this->front_index; i < this->max; i++) {
            new_array[i - this->front_index] = this->array[i];
        }
        int c = this->max - this->front_index;
        for (int i = 0; i < this->front_index; i++) {
            new_array[this->front_index + i] = this->array[i];
        }
        this->max *= 2;
        this->array = new_array;
        this->front_index = 0;
        this->rear_index = (this->max / 2) - 1;
    }
    if (this->front_index == 0) {
        this->front_index = this->max - 1;
    }
    else {
        this->front_index--;
    }
    this->array[this->front_index] = n;
    this->size++;
}

void Deque::enqueue_back(int n)
{
    //TODO: Back enqueue
    if (this->size == 0) {
        this->array[this->max - 1] = n;
        this->size++;
        this->front_index = this->rear_index = 1;
        return ;
    }
    if (this->size + 1 > this->max) {
        int* new_array = (int *) malloc(this->max * 2 * sizeof(int *));
        cout << "rear index: " << this->rear_index << endl;
        for (int i = this->front_index; i < this->max; i++) {
            new_array[i - this->front_index] = this->array[i];
        }
        for (int i = 0; i < this->front_index; i++) {
            new_array[this->front_index + i] = this->array[i];
        }
        this->max *= 2;
        this->array = new_array;
        this->front_index = 0;
        this->rear_index = (this->max / 2) - 1;
    }
    if (this->rear_index == this->max - 1) {
        this->rear_index = 0;
    }
    else {
        this->rear_index++;
    }
    this->array[this->rear_index] = n;
    this->size++;
}

int Deque::dequeue_front()
{
    int element;
    //TODO: front dequeue
    if (this->size == 0) {
        return -1;
    }
    else if (this->front_index == this->rear_index) {
        element = this->array[this->front_index];
        this->array[this->front_index] = 0;
        this->front_index = -1;
        this->rear_index = -1;
    }
    else {
        if (this->front_index == this->max - 1) {
            element = this->array[this->front_index];
            this->array[this->front_index] = 0;
            this->front_index = 0;
        }
        else {
            element = this->array[this->front_index];
            this->array[this->front_index] = 0;
            this->front_index++;
        }
    }
    this->size--;
    //this->array[this->size] = 0;
    return element;
}

int Deque::dequeue_back()
{
    int element;
    //TODO: front dequeue
    if (this->size == 0) {
        return -1;
    }
    else if (this->front_index == this->rear_index) {
        element = this->array[this->rear_index];
        this->array[this->rear_index] = 0;
        this->front_index = -1;
        this->rear_index = -1;
    }
    else {
        if (this->rear_index == 0) {
            element = this->array[this->rear_index];
            this->array[this->rear_index] = 0;
            this->rear_index = this->max - 1;
        }
        else {
            element = this->array[this->rear_index];
            this->array[this->rear_index] = 0;
            this->rear_index--;
        }
    }
    this->size--;
    return element;
}

int Deque::print_array_size()
{
    int size;
    //TODO: get the size of the allocated array
    size = this->max;
    cout << size << " ";
    return size;
}

int Deque::print_front_index()
{
    int index;
    //TODO: get the front index
    if (this->size == 0) {
        index = -1;
    }
    else {
        index = this->front_index;
    }
    cout << index << " ";
    return index;
}

int Deque::print_rear_index()
{
    int index;
    //TODO: get the front index
    if (this->size == 0) {
        index = -1;
    }
    else {
        index = this->rear_index;
    }
    cout << index << endl;
    return index;
}

void Deque::print()
{
    for (int i = 0; i < this->max; i++) {
        cout << this->array[i] << " ";
    }
    cout << endl;
}
