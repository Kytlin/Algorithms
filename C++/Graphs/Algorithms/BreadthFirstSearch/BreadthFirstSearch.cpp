// Date: 08/30/20
/* Program: Runs "Breadth First Search" and outputs the
total distance of each node from the node 's' */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> graph, int s) {
	vector<bool> visited(graph.size());
	vector<int> dist(graph.size());
	queue<int> q;

	visited[s] = true;
	q.push(s);

	while (!q.empty()) {
		int f = q.front();
		q.pop();

		for (int i = 0; i < graph[f].size(); ++i) {
			if (!visited[graph[f][i]]) {
				q.push(graph[f][i]);
				dist[graph[f][i]] = dist[f] + 1;
				visited[graph[f][i]] = true;
			}
		}
	}

	for (int i = 1; i < dist.size(); ++i) {
		cout << i << ": " << dist[i] << '\n';
	}
}

int main()
{
	int n, k, num, nodes, s;

	cin >> num >> nodes >> s;
	vector<vector<int>> graph(nodes + 1);

	for (int i = 0; i < num; ++i) {
		cin >> n >> k;
		graph[n].push_back(k);
		graph[k].push_back(n);
	}

	bfs(graph, s);
}