#include <iostream>
#include <string>
#include "graph.h"

#define INFI 1000000



/*
	Graph class for use in Project 5.
	
	This provided code does not include any specific data structure
	for storing a graph, only a list of methods that will be called 
	from main. Based on the project handout and the lecture slides,
	select a method for storing the graph and implement it here.

*/

// AdjNode::AdjNode() {
// 	conCities.resize(0);
// 	conWeights.resize(0);
// 	oriCity = "";
// }

// AdjNode::AdjNode(string ori) {
// 	conCities.resize(0);
// 	conWeights.resize(0);
// 	oriCity = ori;
// }

// void AdjNode::addCity(string city, double weight) {
// 	conCities.push_back(city);
// 	conWeights.push_back(weight);
// }

// Constructor for Graph 
Graph::Graph(int Vertices, int routes)
{
	numCities = Vertices;
	numRoutes = routes;
	cities.resize(0);
	adjList.resize(numCities);
	weights.resize(numCities);
	for (int i = 0; i < numCities; i++) {
		adjList[i].resize(0);
		weights[i].resize(0);
	}
}

void Graph::addRoute(string ori, string des, double length) {
	bool found = false;
	for (int i = 0; i < cities.size(); i++) {
		if (cities[i] == ori) {
			found = true;
			break;
		}
	}
	if (!found) {
		cities.push_back(ori);
	}
	found = false;
	for (int i = 0; i < cities.size(); i++) {
		if (cities[i] == des) {
			found = true;
			break;
		}
	}
	if (!found) {
		cities.push_back(des);
	}
	int oriId = -1;
	int desId = -1;
	for (int i = 0; i < cities.size(); i++) {
		if (cities[i] == ori) {
			oriId = i;
		}
		if (cities[i] == des) {
			desId = i;
		}
	}
	adjList[oriId].push_back(desId);
	weights[oriId].push_back(length);
	adjList[desId].push_back(oriId);
	weights[desId].push_back(length);
}

void Graph::print() {
	for (int i = 0; i < adjList.size(); i++) {
		cout << cities[i] << " [";
		for (int j = 0; j < adjList[i].size(); j++) {
			cout << cities[adjList[i][j]] << " ";
			cout << weights[i][j] << " - ";
		}
		cout << "]" << endl;
	}
}


// void Graph::dfs(int v, int p = -1) {
//     visited[v] = true;
//     tin[v] = low[v] = timer++;
//     for (int to : adj[v]) {
//         if (to == p) continue;
//         if (visited[to]) {
//             low[v] = min(low[v], tin[to]);
//         } else {
//             dfs(to, v);
//             low[v] = min(low[v], low[to]);
//             if (low[to] > tin[v]) {
//                 IS_BRIDGE(v, to);
// 			}
//         }
//     }
// }

void Graph::analyseGraph() {
	search();
	findEdges();
}

void Graph::search() {
	connected = 0;
	disct = 0;
	disc.resize(numCities + 1);
	evalFunc.resize(numCities + 1);
	tree.resize(numCities + 1);
	visited.assign(numCities + 1, false);
	for (int i = 0; i < numCities; i++) {
		if (!visited[i]) {
			tree[i] = i;
			connected++;
			DFS(i);
		}
	}
}

void Graph::DFS(int p) {
	s.push(p);
	while (!s.empty()) {
		cout << "123" << endl;
		p = s.top();
		s.pop();
		if (!visited[p]) {
			visited[p] = true;
			disct++;
			disc[p] = disct;
			evalFunc[p] = disc[p];
		}

		for (int i = 0; i < adjList[p].size(); i++) {
			if (!visited[adjList[p][i]]) {
				tree[adjList[p][i]] = p;
				s.push(adjList[p][i]);
			}
			else {
				if (adjList[p][i] != tree[p]) {
					if (evalFunc[p] > evalFunc[adjList[p][i]]) {
						int first = adjList[p][i];
						int second = p;
						while (first != second) {
							if (evalFunc[second] > evalFunc[first]) {
								evalFunc[second] = evalFunc[first];
							}
							second = tree[second];
						}
					}
				}
			}
		}
	}
}

void Graph::findEdges() {
	for (int i = 0; i < numCities + 1; i++) {
		if (evalFunc[i] > evalFunc[tree[i]]) {
			arr.push_back(tree[i]);
			arr.push_back(i);
			cout << cities[tree[i]] << " " << cities[i] << endl;
		}
	}
}

// Prints shortest paths from src to all other vertices 
double Graph::dijk(int A, int B) {
  int n = adjList.size();
  vector<double> dist(n);
  vector<bool> vis(n);
 
  for(int i = 0; i < n; ++i) {
    dist[i] = INFI;
  }
  dist[A] = 0.0;
 
  for(int i = 0; i < n; ++i) {
    int cur = -1;
    for(int j = 0; j < n; ++j) {
      if (vis[j]) continue;
      if (cur == -1 || dist[j] < dist[cur]) {
        cur = j;
      }
    }
 
    vis[cur] = true;
    for(int j = 0; j < adjList[cur].size(); ++j) {
	  int index = adjList[cur][j];
      double path = dist[cur] + weights[cur][j];
      if (path < dist[index]) {
        dist[index] = path;
      }
    }
  }
 
  return dist[B];
}

void Graph::findCost(const string &source, const string &destination) {
	int sourId = -1;
	int desId = -1;
	for (int i = 0; i < cities.size(); i++) {
		if (cities[i] == source) {
			sourId = i;
		}
		if (cities[i] == destination) {
			desId = i;
		}
	}
	cout << dijk(sourId, desId) << endl;
}