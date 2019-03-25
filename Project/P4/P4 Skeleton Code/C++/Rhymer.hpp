#ifndef Rhymer_hpp
#define Rhymer_hpp

#include<iostream>
#include <stdio.h>
#include<stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <set>

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

    void generateMap() {
        int sublen = 0;
        for (int i = 0; i < wordList.size(); i++) {
            int wordlen = wordList[i].length();
            if (sublen >= wordlen) {
                sublen = 1;
                continue;
            }
            string key = wordList[i].substr(wordlen - 1 - sublen);
            set<string> wordSet;
            wordSet.insert(wordList[i]);
            for (int j = i + 1; j < wordList.size(); j++) {
                if (sublen < wordList[j].length() && wordList[j].substr(wordList[j].length() - 1 - sublen) == key) {
                    wordSet.insert(wordList[j]);
                }
                else {
                    break;
                }
            }
            // printSet(wordSet);
            if (wordSet.size() != 1) {
                i--;
                sublen++;
                if (contains(key) == false) {
                    wordMap.insert(std::make_pair(key, wordSet));
                }
                continue;
            }
            else {
                sublen = 0;
            }
        }
    }

    bool contains(string key) {
        map<string,set<string>>::const_iterator it = wordMap.find(key);
        if(it != wordMap.end()) {
            return true; // do something with value corresponding to the key
        }
        return false;
    }
    
    string printMap() {
        // cout << "Hi" << endl;
        string output = "";
        map<string, set<string>>::iterator it;
        for(it = wordMap.begin(); it != wordMap.end(); it++) {
            cout << it->second.size() << endl;
            if (it->second.size() >= 0) {
                string key = it->first;
                output += key;
                output += " -> [";
                int count = 0;
                for (set<string>::iterator iter=it->second.begin(); iter!=it->second.end(); ++iter) {
                    if (count == 0) {
                        count++;
                    }
                    if(count == 1) {
                        output+= (*iter );
                        count++;
                    }
                    else {
                        output += (", " + *iter);
                        count++;
                    }
                }
                output += "]\n";
            }
        }
        return output;
    }

    void printSet(set<string> s) {
        for (set<string>::iterator iter=s.begin(); iter!=s.end(); ++iter) {
                    if (iter == s.begin()) {
                        cout << (*iter);
                    }
                    cout << ", " << *iter;
        }
        cout << endl;
    }
    string printMap(int k) {
        // cout << wordMap.size() << endl;
        string output = "";
        map<string, set<string>>::iterator it;
        for(it = wordMap.begin(); it != wordMap.end(); it++) {
            cout << it->second.size() << endl;
            if (it->second.size() >= k) {
                string key = it->first;
                output += key;
                output += " -> [";
                int count = 0;
                for (set<string>::iterator iter=it->second.begin(); iter!=it->second.end(); ++iter) {
                    if (count == 0) {
                        count++;
                    }
                    if(count == 1) {
                        output+= (*iter );
                        count++;
                    }
                    else {
                        output += (", " + *iter);
                        count++;
                    }
                }
                output += "]\n";
            }
        }
        return output;
    }
    string print() {
        string output = "";
        for (int i = 0; i < length; i++) {
            output += wordList[i] + "\n";
        }
        return output;
    }
private: 
    vector<string> wordList;
    map<string, set<string>> wordMap;
    int length;
};

#endif // Rhymer_hpp