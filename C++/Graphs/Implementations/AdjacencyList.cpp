// Date: 08/30/20
/* Program: Implement an adjancency list for weighted
graph with nodes from 1 to num. If there are 7 nodes,
nodes should be labeled from 1 to 7. */

#include <iostream>
#include <utility>
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

	// Initialize a 2D vector array, where the end node is paired with the weight.
	vector<vector<pair<int, int>>> graph(nodes + 1);

	// For undirected graph, the weights are represents in both the start and end node.
	for (int i = 0; i < num; ++i) {
		cin >> n >> k >> w;
		graph[n].push_back(make_pair(k, w));
		graph[k].push_back(make_pair(n, w));
	}

	for (int i = 0; i < graph.size(); ++i) {
		for (int j = 0; j < graph[i].size(); ++j) {
			cout << graph[i][j].first << ':' << graph[i][j].second << '\t';
		}
		cout << '\n';
	}
}