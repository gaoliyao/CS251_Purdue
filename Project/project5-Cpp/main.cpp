#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "graph.h"
 
using namespace std;
 

 // Part 1 : Find the connected components and the bridge
void part1(ifstream &inputfile, ofstream &outputfile)
{
    cout << "123" << endl;;
    int numVer = 0;
    inputfile >> numVer;
    int numEdg = 0;
    inputfile >> numEdg;
    Graph graph = Graph(numVer, numEdg);
    cout << "234" << endl;
    while (numEdg--) {
        string fir = "";
        inputfile >> fir;
        string sec = "";
        inputfile >> sec;
        double weight = 0;
        inputfile >> weight;
        graph.addRoute(fir, sec, weight);
    }
    graph.print();
    graph.analyseGraph();

}

 // Part 2 :  Find a ticket using Dijkstra  
void part2(ifstream &inputfile, ofstream &outputfile)
{
    cout << "123" << endl;;
    int numVer = 0;
    inputfile >> numVer;
    int numEdg = 0;
    inputfile >> numEdg;
    Graph graph = Graph(numVer, numEdg);
    cout << "234" << endl;
    while (numEdg--) {
        string fir = "";
        inputfile >> fir;
        string sec = "";
        inputfile >> sec;
        double weight = 0;
        inputfile >> weight;
        graph.addRoute(fir, sec, weight);
    }
    graph.print();
    while (true) {
        string fir = "";
        inputfile >> fir;
        if (fir == "END") {
            break;
        }
        else {
            string sec = "";
            inputfile >> sec;
            graph.findCost(fir, sec);
        }
    }
}

 // Part 3 :Try to do a tour of all cities 
void part3(ifstream &inputfile, ofstream &outputfile)
{
 

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


     if(part == 1) part1(inputfile, outputfile);
     else if(part == 2) part2(inputfile, outputfile);
     else if(part == 3) part3(inputfile, outputfile);

     return 0;
 }
