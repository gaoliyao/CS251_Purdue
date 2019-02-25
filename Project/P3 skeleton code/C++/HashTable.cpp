//
//  HashTable.cpp
//  
//
//  Created by Wenjie Bai on 2/4/19.
//

#include "HashTable.h"

HashTable::HashTable(){
    //todo
    this->currentSize = 0;
    this->maxCollision = 0;
    this->hash =
}

int HashTable::size() const{
    //todo
}
bool HashTable::empty() const{
    //todo
}
Entry HashTable::get(const K& k) const{
    //todo
}
void HashTable::put(const K& k, const V& v) {
    //todo
}
void HashTable::replace(const K& k, const V&v){
    //todo
}
void HashTable::remove(const K& k) {
    //todo
}
bool HashTable::containsKey(const K& k) {
    //todo
}

int HashTable::getCollision(int hashindex){
    //return the maximum number of collisions (e.g., chain length) of the specified hash table index
}
