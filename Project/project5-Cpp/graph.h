#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iomanip>

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
		int numRoutes;
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
		
		
		
	public:
		int numCities;
		vector<string> circuit;
		double resultCost = -1.0;
		vector<bool> visitedDFS;
		int connCompNum = 1;
		vector<int> arr; // cut edges
		vector<string> cities;
		vector<int> previousVertex;
		vector<string> shortestPath;

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
		double dijk(int src, int B);      
		
		// Part 3: Try to do a tour of all cities
		void eulerianTour(string);  // NOTE : If necessary, you can change the parameters to this function.
		void tour(vector<int> parent, int root);


		void print();  // NOTE : If necessary, you can change the parameters to this function.

};

#endif
