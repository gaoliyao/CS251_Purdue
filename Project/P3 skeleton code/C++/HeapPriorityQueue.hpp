//
//  HeapPriorityQueue.hpp
//
//  Created by Wenjie Bai on 2/7/19.
//  Copyright © 2019 Wenjie Bai. All rights reserved.
//

#ifndef HeapPriorityQueue_hpp
#define HeapPriorityQueue_hpp

#include <stdio.h>
#include <NotImplementedException.h>
//throw NotImplementedException whenever you are asked to pop something from an empty container.
#include <vector>
using namespace std;


template <typename Item>
class HeapPriorityQueue
{
public:
    HeapPriorityQueue( int capacity)
    {
        //complete constructor
    }
    
    
    bool empty( ) const
    {
        //complete function
    }
    
    
    const Item& min( ) const
    {
        //complete function
    }
    
    
    void insert( const Item & x )
    {
        //complete function
    }
    
    
    
    void removeMin( )
    {
       //complete function
    }
    
    void resize()
    {
        
    }
    
    
private:
    int currentSize;  // Number of elements in heap
    vector<Item> array;        // The heap array
    
    

};
#endif /* HeapPriorityQueue_hpp */

