// Date: 08/30/20
/* Program: Implement an adjancency matrix for weighted
graph with nodes from 1 to num. If there are 7 nodes,
nodes should be labeled from 1 to 7. */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	/*
		n: start node value
		k: end node value
		w: edge weight
	*/
	int n, k, w, num, nodes;

	// Get the number of edges and the amount of nodes respectively. 
	cin >> num >> nodes;

	// Initialize a 2D vector array
	vector<vector<int>> graph(nodes + 1, vector<int>(nodes + 1));

	for (int i = 0; i < graph.size(); ++i) {
		for (int j = 0; j < graph[i].size(); ++j) {
			// the weight of a node itself cannot have a value
			if (i == j) {
				graph[i][j] = 0;
			}
			// Setting a large value is applicable for finding shortest path.
			else {
				graph[i][j] = 100001;
			}
		}
	}

	for (int i = 0; i < num; ++i) {
		cin >> n >> k >> w;
		graph[n][k] = w;
		graph[k][n] = w;
	}

	for (int i = 0; i < graph.size(); ++i) {
		for (int j = 0; j < graph[i].size(); ++j) {
			cout << graph[i][j] << '\t';
		}
		cout << '\n';
	}
}