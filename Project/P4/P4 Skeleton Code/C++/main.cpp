#include <iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>

#include "Node.hpp"
#include "BinarySearchTree.hpp"
#include "Rhymer.hpp"

using namespace std;

void read_part_1(ifstream &inputfile, ofstream &outputfile)
{
    int type = -1;
    inputfile >> type;
    if (type == 1) {
        int lineNum = -1;
        inputfile >> lineNum;
        Rhymer rhymer = Rhymer();
        while (lineNum--) {
            string temp;
            inputfile >> temp;
            rhymer.addWord(temp);
        }
        // rhymer.print();
        rhymer.reverseWordContent();
        // rhymer.print();
        rhymer.quickSort();
        // rhymer.print();
        rhymer.reverseWordContent();
        outputfile << rhymer.print();
        // rhymer.printMap();
    }
    if (type == 2) {
        int k = -1;
        inputfile >> k;
        int lineNum = -1;
        inputfile >> lineNum;
        Rhymer rhymer = Rhymer();
        while (lineNum--) {
            string temp;
            inputfile >> temp;
            rhymer.addWord(temp);
        }
        // rhymer.print();
        rhymer.reverseWordContent();
        // rhymer.print();
        rhymer.quickSort();
        // rhymer.print();
        rhymer.reverseWordContent();
        rhymer.print();
        rhymer.generateMap();
        // cout << rhymer.printMap() << endl;
        string output = rhymer.printMap(k);
        // cout << output << endl;
        outputfile << output;
    }
}


void read_part_2(ifstream &inputfile, ofstream &outputfile)
{
    int lineNum = -1;
    inputfile >> lineNum;
    BinarySearchTree tree = BinarySearchTree();
    while (lineNum--) {
        string operation;
        inputfile >> operation;
        // cout << "-1" << endl;
        // cout << "0" << endl;
        if (operation == "insert") {
            int key = -1;
            inputfile >> key;
            tree.insertKey(key);
            // cout << "1" << endl;
            // cout << tree.root->key << endl;
        }
        if (operation == "height") {
            int key = -1;
            inputfile >> key;
            if (tree.searchKey(key) == false) {
                outputfile << "none\n";
            }
            else {
                outputfile << tree.height(key) << endl;
            }
            // cout << "2" << endl;
        }
        if (operation == "delete") {
            int key = -1;
            inputfile >> key;
            if (tree.searchKey(key) == false) {
                outputfile << "deletion failed" << endl;
            }
            else {
                tree.deleteKey(key);
                outputfile << "deleted" << endl;;
            }
            // cout << "3" << endl;
        }
        if (operation == "search") {
            int key = -1;
            inputfile >> key;
            if (tree.searchKey(key) == false) {
                outputfile << "not found" << endl;
            }
            else {
                outputfile << "found" << endl;
            }
            // cout << "4" << endl;
        }
        if (operation == "range") {
            int a, b = -1;
            inputfile >> a >> b;
            int reValue = tree.rangeSum(a, b);
            if (reValue == 0) {
                outputfile << "none" << endl;
            }
            else {
                outputfile << reValue << endl;
            }
            // cout << "5" << endl;
        }
        if (operation == "postorder") {
            if (tree.postorder() == "") {
                outputfile << "none";
            }
            else {
                outputfile << tree.postorder();
            }
            outputfile << endl;
            // cout << "6" << endl;
        }
        if (operation == "levelorder") {
            if (tree.levelorder() == "") {
                outputfile << "none";
            }
            else {
                outputfile << tree.levelorder();
            }
            outputfile << endl;
            // cout << "7" << endl;
        }
        if (operation == "lca") {
            int a, b = -1;
            inputfile >> a;
            inputfile >> b;
            int reValue = tree.LCA(a, b);
            if (reValue == -1) {
                outputfile << "none" << endl;
            }
            else {
                outputfile << reValue << endl;
            }
            // cout << "8" << endl;
        }
        if (operation == "ceil") {
            int a = -1;
            inputfile >> a;
            int reValue = tree.Ceil(a);
            if (reValue == -1) {
                outputfile << "none" << endl;
            }
            else {
                outputfile << reValue << endl;
            }
            // cout << "9" << endl;
        }
        if (operation == "floor") {
            int a = -1;
            inputfile >> a;
            int reValue = tree.Floor(a);
            if (reValue == -1) {
                outputfile << "none" << endl;
            }
            else {
                outputfile << reValue << endl;
            }
            // cout << "10" << endl;
        }
        if (operation == "dist") {
            int a, b = -1;
            inputfile >> a >> b;
            int reValue = tree.dist(a, b);
            if (reValue == -1) {
                outputfile << "none" << endl;
            }
            else {
                outputfile << reValue << endl;
            }
            // cout << "11" << endl;
        }
        if (operation == "insertRB") {
            int a = -1;
            inputfile >> a;
            tree.insertRB(a);
            // cout << "12" << endl;
        }
        if (operation == "Bheight") {
            int a = -1;
            inputfile >> a;
            if (tree.searchKey(a) == false) {
                outputfile << "none" << endl;
            }
            else {
                outputfile << tree.getBlackHeight(a) << endl;
            }
            // cout << "13" << endl;
        }
    }
}

int main(int argc, char *argv[])
{
    //Read in the test case
    ifstream inputfile;
    ofstream outputfile;

    if(argc==3){
        inputfile.open(argv[1]);
        outputfile.open(argv[2]);
    }
    else{
        cout<<"Not enough arguments"<<endl;
    }

    string str;

    getline(inputfile, str);
    int part;
    stringstream convert(str);
    convert >> part;

    switch(part)
    {
        case 1:
            read_part_1(inputfile, outputfile);
            break;
        case 2:
            read_part_2(inputfile,outputfile);
            break;
    }

    inputfile.close();
    outputfile.close();


    return 0;
}

