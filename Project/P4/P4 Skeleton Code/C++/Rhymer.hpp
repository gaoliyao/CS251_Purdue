#ifndef Rhymer_hpp
#define Rhymer_hpp

#include<iostream>
#include <stdio.h>
#include<stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Rhymer
{
    //add necessary constructors and methods following the provided documents
public: 
    Rhymer() {
        length = 0;
        wordList.resize(0);
    }

    Rhymer(int l) {
        length = l;
        wordList.resize(l);
    }

    void addWord(string word) {
        length += 1;
        wordList.resize(length);
        wordList.push_back(word);
    }

    void reverseWordContent() {
        for (int i = 0; i < length; i++) {
            string word = wordList[i];
            string reverseString = "";
            for (int j = word.length() - 1; j >= 0; j--) {
                reverseString += word[j];
            }
            // cout << reverseString << endl;
            wordList[i] = reverseString;
        }
    }

    void quickSort() {
        quickSort(0, length);
    }

    void quickSort(int low, int high) {
        if (low < high) { 
            int pi = partition(low, high); 
    
            quickSort(low, pi - 1); 
            quickSort(pi + 1, high); 
        } 
    }

    int partition (int low, int high) { 
        string pivot = wordList[high];    // pivot 
        int i = (low - 1);  // Index of smaller element 
    
        for (int j = low; j <= high- 1; j++) 
        { 
            // If current element is smaller than or 
            // equal to pivot 
            if (wordList[j].compare(pivot) < 0) 
            { 
                i++;    // increment index of smaller element 
                // swap(&arr[i], &arr[j]); 
                string lower = wordList[i];
                wordList[i] = wordList[j];
                wordList[j] = lower;
            } 
        } 
        string lower = wordList[i+1];
        wordList[i+1] = wordList[high];
        wordList[high] = lower;
        // swap(&arr[i + 1], &arr[high]); 
        return (i + 1); 
    }
    void print() {
        for (int i = 0; i < length; i++) {
            cout << wordList[i] << endl;
        }
    }
private: 
    vector<string> wordList;
    int length;
};

#endif // Rhymer_hpp
