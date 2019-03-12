#ifndef Rhymer_hpp
#define Rhymer_hpp

#include<iostream>
#include <stdio.h>
#include<stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Group
{
public:
    Group(int l, int s) {
        length = l;
        str_index = s;
        words.resize(l);
    }
    Group(int str) {
        length = 0;
        str_index = str;
        words.resize(0);
    }
    void add(string str) {
        length += 1;
        words.push_back(str);
    }
    int getLength() {
        return words.size();
    }
    string head() {
        return words[0];
    }
    int getStrIndex() {
        return str_index;
    }
    void print() {
        for (int i = 0; i < length; i++) {
            cout << words[i] << ", ";
        }
        cout << endl;
    }
private:
    vector<string> words;
    int length;
    int str_index;
};

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
        quickSort(0, length-1);
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

    void generateGroups() {
        cout << "generate" << endl;
        int str_index = 1;
        int i = 0;
        while (i < wordList.size() - 1) {
            cout << i << endl;
            if (str_index >= wordList[i].size()) {
                str_index = 1;
                i++;
            }
            Group g = Group(str_index);
            g.add(wordList[i]);
            string sub_str = wordList[i].substr(wordList[i].length()-1-str_index);
            for (int j = i + 1; j < length; j++) {
                if (wordList[j].length() >= sub_str.length()) {
                    if (sub_str.compare(wordList[j].substr(wordList[j].length()-1-str_index)) == 0) {
                        cout << "Add" << endl;
                        g.add(wordList[j]);
                    }
                }
            }
            groupList.push_back(g);
            if (g.getLength() == 1) {
                str_index = 1;
                i++;
            }
            else {
                str_index++;
            }
        }
    }

    void print() {
        cout << "print" << endl;
        for (int i = 0; i < length; i++) {
            cout << wordList[i] << endl;
        }
        cout << endl;
    }

    void printGroups() {
        int max_length = -1;
        for (int i = 0; i < groupList.size(); i++) {
            if (groupList[i].getStrIndex() > max_length) {
                max_length = groupList[i].getStrIndex();
            }
        }
        for (int i = 0; i < max_length; i++) {
            for (int j = 0; j < groupList.size(); j++) {
                if (groupList[j].getStrIndex() == i) {
                    cout << groupList[j].head().substr(groupList[j].head().length()-1-i) << " - ";
                    groupList[j].print();
                }
            }
        }
    }

    void printGroups(int k) {
        int max_length = -1;
        for (int i = 0; i < groupList.size(); i++) {
            if (groupList[i].getStrIndex() > max_length) {
                max_length = groupList[i].getStrIndex();
            }
        }
        for (int i = k; i <= max_length; i++) {
            for (int j = 0; j < groupList.size(); j++) {
                if (groupList[j].getStrIndex() == i) {
                    cout << groupList[j].head().substr(groupList[j].head().length()-1-i) << " - ";
                    groupList[j].print();
                }
            }
        }
    }
private: 
    vector<string> wordList;
    vector<Group> groupList;
    int length;
};

#endif // Rhymer_hpp
