#include "stack.h"
#include <utility>
#include <malloc.h>

using namespace std;

Pair::Pair(int n1, int n2) {
    this->num1 = n1;
    this->num2 = n2;
}

int Pair::getNum1 () {
    return this->num1;
}

int Pair::getNum2 () {
    return this->num2;
}

void Pair::setIndex (int index) {
    this->index = index;
}

int Pair::getIndex () {
    return this->index;
}

Stack::Stack()
{
    //TODO: Write the constructor
    this->head = NULL;
    this->stackSize = 0;
}

void Stack::push(Pair p)
{
    //TODO: Write the push method
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->data = p;
    node->next = NULL;
    if (this->head == NULL) {
        cout<<"line1"<<endl;
        this->head = node;
        this->stackSize ++;
    }
    else {
        node->next = this->head;
        this->head = node;
        this->stackSize ++;
    }
}

Pair Stack::pop()
{
    Pair p(-1, -1);
    //TODO: Write the pop method
    if (this->head == NULL) {
        return p;
    }
    else {
        p = this->head->data;
        this->head = this->head->next;
        this->stackSize --;
        return p;
    }
}

ListNode* Stack::peek() {
    return this->head;
}

bool Stack::isEmpty() {
    if (this->head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void Stack::print() {
    struct ListNode* curr = this->head;
    while (curr != NULL) {
        cout << curr->data.getNum1() << " " << curr->data.getNum2() << endl;
        curr = curr->next;
    }
}

int Stack::getStackSize() {
    return this->stackSize;
}
