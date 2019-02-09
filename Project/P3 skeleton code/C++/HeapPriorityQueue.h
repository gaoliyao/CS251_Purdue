//
//  HeapPriorityQueue.h
//  
//
//  Created by Wenjie Bai on 2/3/19.
//

#ifndef HeapPriorityQueue_h
#define HeapPriorityQueue_h

#include <vector>
using namespace std;


template <typename Item>
class HeapPriorityQueue
{
public:
    HeapPriorityQueue();
    
    int size() const;
  
    bool empty( ) const;

    const Item& min( ) const;
 
    void insert( const Item& x );

    void removeMin( );
    
    vector<Item> heapSort();
    
private:
    int  currentSize;
    vector<Item> array;
    
};
#endif /* HeapPriorityQueue_h */
