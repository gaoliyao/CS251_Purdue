#include <iostream>
#include <utility>
#include "stdio.h"

using namespace std;


class Pair
{
    //TODO : Inplement Pair class
    int num1;
    int num2;
    int index;

public:
    Pair(int, int);
    int getNum1();
    int getNum2();
    void setIndex(int index);
    int getIndex();
    bool checked = false;
};

struct ListNode{
    Pair data;
    ListNode * next;
};

class Stack
{

    int stackSize;
    int top;

public:

    Stack();
    void push(Pair item);
    Pair pop();
    ListNode *head;
    ListNode* peek();
    bool isEmpty();
    void print();
    int getStackSize();
    int getMaxIndex();
};
