#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// class AdjNode
// {
// 	public:
// 		vector<string> conCities;
// 		vector<double> conWeights;
// 		string oriCity;

// 		AdjNode();

// 		AdjNode(string ori);

// 		void addCity(string city, double weight);

// };

class Graph
{
	private:
		int numCities;
		int numRoutes;
		vector<string> cities;
		vector<vector<int>> adjList;
		vector<vector<double>> weights;
		vector<bool> visited;
		vector<int> tin, low;
		int timer;
		int connected;
		vector<int> disc;
		vector<int> evalFunc;
		vector<int> tree;
		int disct = 0;
		stack<int> s;
		vector<int> arr; // cut edges
		
		
	public:
		
		Graph(int, int); 
		// Create the graph
		void addRoute(string, string, double);	

		//part 1: Find the connected components and the bridges
		void analyseGraph();		
		void DFS(int s);
		void search();
		void findEdges();
		
		
		// Part 2: Find a ticket using Dijkstra	
		void findCost(const string &source, const string &destination);         
		
		// Part 3: Try to do a tour of all cities
		void eulerianTour(int);  // NOTE : If necessary, you can change the parameters to this function.

		void print();  // NOTE : If necessary, you can change the parameters to this function.

};

#endif
