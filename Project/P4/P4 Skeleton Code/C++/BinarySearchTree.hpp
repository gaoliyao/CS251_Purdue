#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include<iostream>
#include <stdio.h>
#include<stdlib.h>
#include <vector>
#include <string>

using namespace std;

enum Color {RED, BLACK};

class BinarySearchTree
{
    

    //add necessary constructors and methods following the provided documents
public:
    Node *root;
    int max;
    BinarySearchTree() {
        root = NULL;
        max = 0;
    }
    BinarySearchTree(int k) {
        root = new Node(k);
        max = 0;
    }  
    BinarySearchTree(int k, int c) {
        root = new Node(k, BLACK);
        max = 0;
    }  

    void insertKey(int key) {
        // Node *cur = root;
        // if (key > max) {
        //     max = key;
        // }
        // if (root == NULL) {
        //     root = new Node(key);
        //     return ;
        // }
        // while(1) {
        //     if (key <= cur->getKey()) {
        //         if (cur->getLeft() == NULL) {
        //             Node *n = new Node(key, cur);
        //             break;
        //         }
        //         else {
        //             cur = cur->getLeft();
        //         }
        //     }
        //     else {
        //         if (cur->getRight() == NULL) {
        //             Node *n = new Node(key, cur);
        //             break;
        //         }
        //         else {
        //             cur = cur->getRight();
        //         }
        //     }
        // }
        if (key > max) {
            max = key;
        }
        if (this->root == NULL) {
            this->root = new Node(key);;
            return ;
        }
        Node *pt = new Node(key);
        BSTInsert(this->root, pt);
        // cout << "new root: " << endl;
        // cout << this->root->key << endl;
    }

    Node* BSTInsert(Node* curr, Node *pt) {
        /* If the tree is empty, return a new node */
        if (curr == NULL) 
            return pt; 
    
        /* Otherwise, recur down the tree */
        if (pt->key < curr->key) 
        { 
            curr->left  = BSTInsert(curr->left, pt); 
            curr->left->parent = curr; 
        } 
        else if (pt->key > curr->key) 
        { 
            curr->right = BSTInsert(curr->right, pt); 
            curr->right->parent = curr; 
        } 
    
        /* return the (unchanged) node pointer */
        return curr; 
    }

    void deleteKey(int key) {
        deleteNode(root, key);
    }

    Node* deleteNode(Node* root, int key) { 
        if (searchKey(key) == false) {
            return NULL;
        }
        if (root == NULL) 
            return root; 
        if (key < root->key) 
            root->left = deleteNode(root->left, key); 
        else if (key > root->key) 
            root->right = deleteNode(root->right, key); 
        else
        { 
            if (root->left == NULL) 
            { 
                Node* temp = root->right; 
                free(root); 
                return temp; 
            } 
            else if (root->right == NULL) 
            { 
                Node* temp = root->left; 
                free(root); 
                return temp; 
            } 
            Node* temp = minValueNode(root->right); 
            root->key = temp->key; 
            root->right = deleteNode(root->right, temp->key); 
        } 
        return root; 
    } 

    Node* minValueNode(Node* node) { 
        Node* current = node; 
        while (current->left != NULL) 
            current = current->left; 
    
        return current; 
    }

    bool searchKey(int key) {
        Node *cur = root;
        while(1) {
            if (cur == NULL) {
                break;
            }
            if (key < cur->getKey()) {
                cur = cur->getLeft();
            }
            else if (key > cur->getKey()) {
                cur = cur->getRight();
            }
            else {
                return true;
            }
        }
        return false;
    }

    Node* searchKey(int key, int i) {
        Node *cur = root;
        while(1) {
            if (cur == NULL) {
                break;
            }
            if (key < cur->getKey()) {
                cur = cur->getLeft();
            }
            else if (key > cur->getKey()) {
                cur = cur->getRight();
            }
            else {
                // cout << cur->key << endl;
                return cur;
            }
        }
        return NULL;
    }

    int rangeSum(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            if (searchKey(i)) {
                sum += i;
            }
        }
        return sum;
    }

    int height(int key) {
        int h = 0;
        Node *cur = root;
        while(1) {
            if (cur == NULL) {
                break;
            }
            if (key < cur->getKey()) {
                cur = cur->getLeft();
                h++;
            }
            else if (key > cur->getKey()) {
                cur = cur->getRight();
                h++;
            }
            else {
                return h;
            }
        }
        return -1;
    }

    int height(int key, Node *cur) {
        int h = 0;
        while(1) {
            if (cur == NULL) {
                break;
            }
            if (key < cur->getKey()) {
                cur = cur->getLeft();
                h++;
            }
            else if (key > cur->getKey()) {
                cur = cur->getRight();
                h++;
            }
            else {
                return h;
            }
        }
        return -1;
    }

    void postorder() {
        postorder(root);
    }

    void postorder(Node *cur) {
        if (cur == NULL) {
            return;
        }
        postorder(cur->getLeft());
        postorder(cur->getRight());
        cout << cur->getKey() << " ";
    }

    void levelorder() {
        vector<vector<Node*>> curList;
        curList.resize(0);
        if (root == NULL) {
            return;
        }
        vector<Node*> fl;
        fl.resize(0);
        fl.push_back(root);
        curList.push_back(fl);
        int height = 0;
        while(curList[height].size() != 0) {
            height++;
            vector<Node*> levelList;
            levelList.resize(0);
            for (int i = 0; i < curList[height-1].size(); i++) {
                if (curList[height-1][i]->getLeft() != NULL) {
                    levelList.push_back(curList[height-1][i]->getLeft());
                }
                if (curList[height-1][i]->getRight() != NULL) {
                    levelList.push_back(curList[height-1][i]->getRight());
                }
            }
            curList.push_back(levelList);
        }
        for (int i = 0; i < curList.size(); i++) {
            for (int j = 0; j < curList[i].size(); j++) {
                cout << curList[i][j]->key << " "; 
            }
        }
    }

    int LCA(int key1, int key2) {
        Node *a = searchKey(key1, 1);
        Node *b = searchKey(key2, 1);
        if (a == NULL || b == NULL) {
            return -1;
        }
        vector<int> parListA;
        vector<int> parListB;
        parListA.resize(0);
        parListB.resize(0);
        while (a->getParent() != NULL) {
            a = a->getParent();
            parListA.push_back(a->getKey());
        }
        while (b->getParent() != NULL) {
            b = b->getParent();
            parListB.push_back(b->getKey());
        }
        if (parListA.size() == 0 || parListB.size() == 0) {
            return root->key;
        }
        for (int i = 0; i < parListB.size(); i++) {
            for (int j = 0; j < parListA.size(); j++) {
                if (parListB[i] == parListA[j]) {
                    return parListB[i];
                }
            }
        }
        return -1;
    }

    int Floor(int key) {
        for (int i = key; i >= 0; i--) {
            if (searchKey(i)) {
                return i;
            }
        }
        return -1;
    }

    int Ceil(int key) {
        for (int i = key; i <= max; i++) {
            if (searchKey(i)) {
                return i;
            }
        }
        return -1;
    }

    int dist(int key1, int key2) {
        int lcaKey = LCA(key1, key2);
        if (lcaKey == -1) {
            return -1;
        }
        Node *sameP = searchKey(lcaKey, 1);
        int h1 = height(key1, sameP);
        int h2 = height(key2, sameP);
        return h1 + h2;
    }

    void rotateLeft(Node *&root, Node *&pt) 
    { 
        Node *pt_right = pt->getRight(); 
    
        pt->setRight(pt_right->getLeft()); 
    
        if (pt->getRight() != NULL) 
            pt->getRight()->setParent(pt); 
    
        pt_right->setParent(pt->getParent()); 
    
        if (pt->getParent() == NULL) 
            root = pt_right; 
    
        else if (pt == pt->getParent()->getLeft()) 
            pt->getParent()->setLeft(pt_right); 
    
        else
            pt->getParent()->setRight(pt_right); 
    
        pt_right->setLeft(pt); 
        pt->setParent(pt_right); 
    }

    void rotateRight(Node *&root, Node *&pt) 
    { 
        Node *pt_left = pt->getLeft(); 
    
        pt->setLeft(pt_left->getRight()); 
    
        if (pt->getLeft() != NULL) 
            pt->getLeft()->setParent(pt); 
    
        pt_left->setParent(pt->getParent()); 
    
        if (pt->getParent() == NULL) 
            root = pt_left; 
    
        else if (pt == pt->getParent()->getLeft()) 
            pt->getParent()->setLeft(pt_left); 
    
        else
            pt->getParent()->setRight(pt_left); 
    
        pt_left->setRight(pt); 
        pt->setParent(pt_left); 
    } 

    void fixViolation(Node *&root, Node *&pt) 
    { 
        Node *parent_pt = NULL; 
        Node *grand_parent_pt = NULL; 
    
        while ((pt != root) && (pt->getColor() != BLACK) && 
            (pt->getParent()->getColor() == RED)) 
        { 
    
            parent_pt = pt->getParent(); 
            grand_parent_pt = pt->getParent()->getParent(); 
    
            /*  Case : A 
                Parent of pt is left child of Grand-parent of pt */
            if (parent_pt == grand_parent_pt->getLeft()) 
            { 
    
                Node *uncle_pt = grand_parent_pt->right; 
    
                /* Case : 1 
                The uncle of pt is also red 
                Only Recoloring required */
                if (uncle_pt != NULL && uncle_pt->color == RED) 
                { 
                    grand_parent_pt->color = RED; 
                    parent_pt->color = BLACK; 
                    uncle_pt->color = BLACK; 
                    pt = grand_parent_pt; 
                } 
    
                else
                { 
                    /* Case : 2 
                    pt is right child of its parent 
                    Left-rotation required */
                    if (pt == parent_pt->right) 
                    { 
                        rotateLeft(root, parent_pt); 
                        pt = parent_pt; 
                        parent_pt = pt->parent; 
                    } 
    
                    /* Case : 3 
                    pt is left child of its parent 
                    Right-rotation required */
                    rotateRight(root, grand_parent_pt); 
                    swap(parent_pt->color, grand_parent_pt->color); 
                    pt = parent_pt; 
                } 
            } 
    
            /* Case : B 
            Parent of pt is right child of Grand-parent of pt */
            else
            { 
                Node *uncle_pt = grand_parent_pt->left; 
    
                /*  Case : 1 
                    The uncle of pt is also red 
                    Only Recoloring required */
                if ((uncle_pt != NULL) && (uncle_pt->color == RED)) 
                { 
                    grand_parent_pt->color = RED; 
                    parent_pt->color = BLACK; 
                    uncle_pt->color = BLACK; 
                    pt = grand_parent_pt; 
                } 
                else
                { 
                    /* Case : 2 
                    pt is left child of its parent 
                    Right-rotation required */
                    if (pt == parent_pt->left) 
                    { 
                        rotateRight(root, parent_pt); 
                        pt = parent_pt; 
                        parent_pt = pt->parent; 
                    } 
    
                    /* Case : 3 
                    pt is right child of its parent 
                    Left-rotation required */
                    rotateLeft(root, grand_parent_pt); 
                    swap(parent_pt->color, grand_parent_pt->color); 
                    pt = parent_pt; 
                } 
            } 
        } 
    
        root->color = BLACK; 
    } 
    void insertRB(int key) 
    { 
        Node *pt = new Node(key, RED); 
        root = BSTInsert(root, pt); 
        fixViolation(root, pt); 
    } 

    int getBlackHeight(int key) {
        Node *cur = root;
        int bHeight = 0;
        while(cur != NULL) {
            if (cur->getColor() == 0) {
                bHeight++;
            }
            cur = cur->left;
        }
        return bHeight;
    }
};

#endif // BinarySearchTree_hpp
