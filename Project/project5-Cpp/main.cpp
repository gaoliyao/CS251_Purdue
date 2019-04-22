#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "graph.h"
#define INFI 1000000

 
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
    // graph.print();
    graph.analyseGraph();
    outputfile << graph.connCompNum << endl;
    outputfile << (int)(graph.arr.size() / 2);
    for (int i = 0; i < graph.arr.size(); i = i + 2) {
        outputfile << endl << graph.cities[graph.arr[i]] << " " << graph.cities[graph.arr[i + 1]];
    }

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
    int count = 0;
    while (true) {
        string fir = "";
        inputfile >> fir;
        string sec = "";
        if (fir == "END") {
            break;
        }
        else {
            inputfile >> sec;
            graph.findCost(fir, sec);
        }
        if (count == 0) {

        }
        else {
            outputfile << endl;
        }
        if (graph.resultCost == -1) {
            outputfile << fir << " " << sec << " " << "not possible";
        }
        else {
            for (int i = 0; i < graph.shortestPath.size(); i++) {
                outputfile << graph.shortestPath[i] << " ";
            }
            outputfile << setprecision(2) << fixed << graph.resultCost;
        }
        count++;
    }
}

 // Part 3 :Try to do a tour of all cities 
void part3(ifstream &inputfile, ofstream &outputfile)
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
    // graph.print();
    string root = "";
    inputfile >> root;
    graph.eulerianTour(root);
    if (graph.circuit.size() < graph.numCities) {
        outputfile << "not possible";
    }
    else{
        outputfile << graph.circuit[0];
        for (int i = 1; i < graph.circuit.size(); i++) {
            outputfile << endl << graph.circuit[i];
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


     if(part == 1) part1(inputfile, outputfile);
     else if(part == 2) part2(inputfile, outputfile);
     else if(part == 3) part3(inputfile, outputfile);

     return 0;
 }
