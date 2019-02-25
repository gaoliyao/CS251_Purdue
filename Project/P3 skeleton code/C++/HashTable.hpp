//
//  HashTable.hpp
//  SeperateChaining
//
//  Created by Wenjie Bai on 2/6/19.
//  Copyright © 2019 Wenjie Bai. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <iostream>
#include <stdio.h>
//throw NotImplementedException whenever you are asked to pop something from an empty container.
#include <list>
#include <vector>
#include <string>
#include <iterator>
#include<sstream>
#include<fstream>
using namespace std;


const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271};

template <typename V> class
Entry {
public:
    Entry(const string& k, const V& v)
    :   _key(k),   _value(v) { }
    const string& getkey() const {return _key;}
    const V& getvalue() const {return _value;}
    bool operator==(const Entry &other) {
        return (other.getkey() == _key) && (other.getvalue() == _value);
    }
private:
    string _key;
    V _value;
};

template <typename V>
class HashTable
{
public:
    HashTable( int capacity )
    {
        //complete constructor, might require initializer list
        theLists.resize(capacity);
        this->capacity = capacity;
        this->currentSize = 0;
        this->keysSize = 0;
        // for (int i = 0; i < capacity; i++) {
        //     list<Entry<V>> l;
        //     theLists.push_back(l);
        // }
    }
    

    int size()
    {
        //complete function
        return currentSize;
    }

    int hashCode(const string& s )
    {
        //complete function
        int totalV = 0;
        for (int i = 0; i < s.length(); i++) {
            totalV += s[i];
        }
        return totalV;
    }
    
    int hashValue(const int hashcode)
    {
        //complete function
        return hashcode % capacity;
    }

    //TODO
    //Not finished
    V put(const string& k, const V& v)
    {
        //complete function
        // print();
        int index = hashValue(hashCode(k));
        // cout << "Put index: "<< index << endl;
        // list<Entry<V>> l = theLists.at(index);
        if (theLists[index].empty()) {
            keysSize ++;
        }
        Entry<V> e = Entry<V>(k, v);
        // cout << "Entry key: "<< e.getkey() << endl;
        // cout << "Entry value: "<< e.getvalue() << endl;
        if (contains(k)) {
            // cout << "Contains" << endl;
            if (theLists[index].empty()) {
                list<Entry<V>> l;
                l.push_back(e);
                theLists[index] = l;
                return -100;
            }
            else {
                list<Entry<V>> l = theLists.at(index);
                typename std::list<Entry<V>>::iterator iter = l.begin();
                for (iter; iter != l.end(); iter++) {
                    if (iter->getkey() == k) {
                        V oriV = iter->getvalue();
                        l.remove(*iter);
                        l.push_back(e);
                        theLists[index] = l;
                        return oriV;
                    }
                }
            }
        }
        else {
            currentSize++;
            list<Entry<V>> l;
            l.push_back(e);
            if (theLists[index].empty()) {
                theLists[index] = l;
            }
            else {
                list<Entry<V>> l = theLists.at(index);
                l.push_back(e);
                theLists[index] = l;
            }
            // cout << l.front().getkey() << endl;
            // cout << "Before rehash" << endl;
            // print();
            if (keysSize * 1.0 / capacity * 1.0 > 0.5) {
                // cout << "rehash" << endl;
                rehash();
            }
            return -100;
        }
    }
    
    V get(const string& k)
    {
        //complete function
        int index = hashValue(hashCode(k));
        list<Entry<V>> l = theLists.at(index);
        typename std::list<Entry<V>>::iterator iter = l.begin();
        for (iter; iter != l.end(); iter++) {
            if (iter->getkey() == k) {
                return iter->getvalue();
            }
        }
        return -100;
    }

    V replace(const string& k, const V& v)
    {
        //complete function
        if (!contains(k)) {
            return -100;
        }
        else {
            return put(k, v);
        }
    }
    
    bool contains(const string& k)
    {
        int hCode = hashValue(hashCode(k));
        // list<Entry<V>> l = theLists.at(hCode);
        if (theLists[hCode].empty()) {
            return false;
        }
        else {
            list<Entry<V>> l = theLists.at(hCode);
            typename std::list<Entry<V>>::iterator iter = l.begin();
            for (iter; iter != l.end(); iter++) {
                if (iter->getkey() == k) {
                    return true;
                }
            }
            return false;
        }
    }

    V remove( const string& k )
    {
        // print();
        //complete function
        int hCode = hashValue(hashCode(k));
        if (theLists[hCode].empty()) {
            return -100;
        }
        else {
            list<Entry<V>> l = theLists.at(hCode);
            typename std::list<Entry<V>>::iterator iter = l.begin();
            for (iter; iter != l.end(); iter++) {
                // cout << iter->getkey() << endl;
                if (iter->getkey() == k) {
                    V ori= iter->getvalue();
                    l.remove(*iter);
                    theLists[hCode] = l;
                    currentSize --;
                    return ori;
                }
            }
            currentSize --;
            // print();
            return -100;
        }

    }
    
    size_t getCollision(int hashIndex)
    {
        //complete function
        list<Entry<V>> l = theLists.at(hashIndex);
        return l.size();
    }
    
    void rehash()
    {
        int newSize = 0;
        int oriCapacity = capacity;
        int doubleCapa = capacity * 2;
        for (int i = 0; i < 58; i++) {
            if (primes[i] > doubleCapa) {
                newSize = primes[i];
                break;
            }
        }
        this->capacity = newSize;
        vector<list<Entry<V>>> newLists;
        newLists.resize(capacity);
        for (int i = 0; i < oriCapacity; i++) {
            int newHashCode = -1;
            if (!theLists[i].empty()) {
                list<Entry<V>> l = theLists.at(i);
                Entry<V> entry = l.front();
                newHashCode = hashValue(hashCode(entry.getkey()));
                if (newLists[newHashCode].empty()) {
                    newLists[newHashCode] = l;
                }
                else {
                    list<Entry<V>> newL = newLists[newHashCode];
                    typename std::list<Entry<V>>::iterator iter = newL.begin();
                    for (iter; iter != newL.end(); iter++) {
                        // cout << iter->getkey() << endl;
                    }
                    iter = l.begin();
                    for (iter; iter != l.end(); iter++) {
                        Entry<V> e = *iter;
                        newL.push_back(e);
                    }
                    newLists[newHashCode] = newL;
                }
            }
        }
        this->theLists = newLists;
    }

    void print() {
        cout << "-------------------------" << endl;
        for (int i = 0; i < theLists.size(); i++) {
            cout << i;
            if (theLists[i].empty()) {
                cout << " empty" << endl;
            }
            else {
                list<Entry<V>> l = theLists.at(i);
                typename std::list<Entry<V>>::iterator iter = l.begin();
                for (iter; iter != l.end(); iter++) {
                    cout << " (" << iter->getkey() << ", " << iter->getvalue() << ")";
                }
                cout << endl;
            }
        }
        cout << "-------------------------" << endl;
    }

    void print(vector<list<Entry<V>>> theLists) {
        cout << "-------------------------" << endl;
        for (int i = 0; i < theLists.size(); i++) {
            cout << i;
            if (theLists[i].empty()) {
                cout << " empty" << endl;
            }
            else {
                list<Entry<V>> l = theLists.at(i);
                typename std::list<Entry<V>>::iterator iter = l.begin();
                for (iter; iter != l.end(); iter++) {
                    cout << " (" << iter->getkey() << ", " << iter->getvalue() << ")";
                }
                cout << endl;
            }
        }
        cout << "-------------------------" << endl;
    }
    
private:
    vector<list<Entry<V>>> theLists;   // The array of Lists
    int  currentSize;
    int keysSize;
    int capacity;
    

};
#endif /* HashTable_hpp */
