//
//  HeapPriorityQueue.hpp
//
//  Created by Wenjie Bai on 2/7/19.
//  Copyright © 2019 Wenjie Bai. All rights reserved.
//

#ifndef HeapPriorityQueue_hpp
#define HeapPriorityQueue_hpp

#include <stdio.h>
//throw NotImplementedException whenever you are asked to pop something from an empty container.
#include <vector>
#include<sstream>
#include<fstream>
#include <iostream>
using namespace std;


template <typename Item>
class HeapPriorityQueue
{
public:
    HeapPriorityQueue( int capacity)
    {
        //complete constructor, might require initializer list
        currentSize = 0;
        array.resize(capacity);
    }
    
    
    bool empty( ) const
    {
        return (currentSize == 0);
    }
    
    int size() {
        return currentSize;
    }
    
    
    const Item& min( ) const
    {
        //complete function
        if (empty()) {
            //cout << "empty" << endl;
            const Item& i = 0;
            return i;
        }
        return array[0];
    }
    
    
    void insert( const Item & x )
    {
        currentSize++;
        if (empty()) {
            array.push_back(x);
        }
        else{
            array.push_back(x);
            int indexPlusOne = array.size();
            while (indexPlusOne != 1) {
                int index = indexPlusOne - 1;
                int parentIndexPlusOne = indexPlusOne / 2;
                if (array[parentIndexPlusOne - 1] < array[indexPlusOne - 1]) {
                    break;
                }
                else{
                    int parentNum = array[parentIndexPlusOne - 1];
                    array[parentIndexPlusOne - 1] = array[indexPlusOne - 1];
                    array[indexPlusOne - 1] = parentNum;
                    indexPlusOne = parentIndexPlusOne;
                }
            }
        }
    }
    
    
    
    void removeMin( )
    {
        if (empty()) {
            return ;
        }
        else {
            if (size() == 1) {
                array.clear();
                currentSize = 0;
            }
            else {
                int replaceRoot = array[array.size() - 1];
                array[0] = replaceRoot;
                array.pop_back();
                currentSize--;
                int currIndexPlusOne = 1;
                int lChildPOne, rChildPOne;
                while (true) {
                    lChildPOne = 2 * currIndexPlusOne;
                    rChildPOne = 2 * currIndexPlusOne + 1;
                    if (lChildPOne > array.size()) {
                        break;
                    }
                    if ((array[currIndexPlusOne - 1] < array[lChildPOne - 1]) && (array[currIndexPlusOne - 1] < array[rChildPOne - 1])) 
                    {
                        break;
                    }
                    if (array[rChildPOne - 1] > array[lChildPOne - 1]) {
                        if (array[currIndexPlusOne - 1] < array[lChildPOne - 1]) {
                            break;
                        }
                        else {
                            int parent = array[currIndexPlusOne - 1];
                            array[currIndexPlusOne - 1] = array[lChildPOne - 1];
                            array[lChildPOne - 1] = parent;
                            currIndexPlusOne = lChildPOne;
                            continue;
                        }
                    }
                    else {
                        if (array[currIndexPlusOne - 1] < array[rChildPOne - 1]) {
                            break;
                        }
                        else {
                            int parent = array[currIndexPlusOne - 1];
                            array[currIndexPlusOne - 1] = array[rChildPOne - 1];
                            array[rChildPOne - 1] = parent;
                            currIndexPlusOne = rChildPOne;
                            continue;
                        }
                    }
                }
            }
        }
    }
    
    void resize()
    {
        
    }

    void print() 
    {
        for (int i = 0; i < currentSize; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    
    
private:
    int currentSize;  // Number of elements in heap
    vector<Item> array;        // The heap array
    
    

};
#endif /* HeapPriorityQueue_hpp */

