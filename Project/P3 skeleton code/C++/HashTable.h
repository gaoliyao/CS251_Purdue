//
//  HashTable.h
//  
//
//  Created by Wenjie Bai on 2/4/19.
//

#ifndef HashTable_h
#define HashTable_h
#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
using namespace std;

template <typename K, typename V>
class Entry {    // a (key, value) pair
public:
    Entry(const K& k = K(), const V& v = V())
    :_key(k),_value(v) { }   // constructor
    const K& key() const { return _key; }  // get key
    const V& value() const { return _value; }// get value
    void setKey(const K& k) { _key = k; }// set key
    void setValue(const V& v) { _value = v; }// set value
private:
    K _key;//key
    V _value;// value
};


template <typename K, typename V>
class HashTable {
public:
    class Entry; // a (key, value) pair
    HashTable(); //constructor
    int size() const; // number of entries in the table
    bool empty() const;
    Entry get(const K& k) const; // find entry with key k
    void put(const K& k, const V& v); // insert pair (k,v)
    void replace(const K& k, const V&v); //replace with pair(k,v)
    void remove(const K& k); // remove/replace entry with key k
    bool containsKey(const K& k); // test if it contains key
    int getCollision(int hashindex); //get number of collisions
private:
    vector<list<Entry>> hash;   // The array of Lists
    int  currentSize;
    int maxCollision;
};



#endif /* HashTable_h */
