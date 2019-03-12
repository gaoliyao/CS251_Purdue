#include <iostream>
#include<sstream>
#include<fstream>
#include<vector>

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
        rhymer.print();
        rhymer.reverseWordContent();
        rhymer.print();
        rhymer.quickSort();
        rhymer.print();
        rhymer.reverseWordContent();
        rhymer.print();
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
        rhymer.print();
        rhymer.reverseWordContent();
        rhymer.print();
        rhymer.quickSort();
        rhymer.print();
        rhymer.reverseWordContent();
        rhymer.print();
        rhymer.generateGroups();
        rhymer.printGroups(k);
    }
}


void read_part_2(ifstream &inputfile, ofstream &outputfile)
{
    //handle input, output from file
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


    return 0;
}

