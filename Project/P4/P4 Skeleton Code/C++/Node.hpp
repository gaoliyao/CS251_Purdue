#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

using namespace std;

class Node
{
    //add necessary variables and functions

public:
    int key;
    Node *parent;
    Node *left;
    Node *right;
    int color; //0: red; 1: black;
    Node() {
        key = 0;
        parent = NULL;
        left = NULL;
        right = NULL;
        color = -1;
    }
    Node(int k) {
        key = k;
        parent = NULL;
        left = NULL;
        right = NULL;
        color = -1;
    }
    Node(int k, Node *p) {
        key = k;
        parent = p;
        left = NULL;
        right = NULL;
        color = -1;
    }
    Node(int k, int c) {
        key = k;
        parent = NULL;
        left = NULL;
        right = NULL;
        color = c;
    }
    Node(int k, Node *p, int c) {
        key = k;
        parent = p;
        left = NULL;
        right = NULL;
        color = c;
    }
    int getKey() {
        return key;
    }
    void setKey(int k) {
        key = k;
    }
    Node* getParent() {
        return parent;
    }
    void setParent(Node *p) {
        parent = p;
    }
    Node* getLeft() {
        return left;
    }
    void setLeft(Node *l) {
        left = l;
    }
    Node* getRight() {
        return right;
    }
    void setRight(Node *r) {
        right = r;
    }
    int getColor() {
        return color;
    }
    void setColor(int c) {
        color = c;
    }
};

#endif // Node_hpp

