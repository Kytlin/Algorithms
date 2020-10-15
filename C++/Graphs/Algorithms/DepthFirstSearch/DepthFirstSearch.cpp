// Date: 08/30/20
/* Program: Runs "Depth First Search" and outputs the
total distance of each node from the node 's' */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int>> graph, stack<int> track, int s, vector<bool> visited, vector<int> dist) {
	bool visit = false;

	if (!visited[s]) {
		visited[s] = true;
		track.push(s);
	}

	for (int i = 0; i < graph[s].size(); ++i) {
		if (!visited[graph[s][i]]) {
			visit = true;
			dist[graph[s][i]] = dist[s] + 1;
			return dfs(graph, track, graph[s][i], visited, dist);
		}
	}

	if (!visit) {
		if (!track.empty()) {
			int f = track.top();
			track.pop();

			return dfs(graph, track, f, visited, dist);
		}
		else {
			for (int i = 1; i < dist.size(); ++i) {
				cout << i << ": " << dist[i] << '\n';
			}
		}
	}
}

int main()
{
	int n, k, num, nodes, s;

	cin >> num >> nodes >> s;
	vector<vector<int>> graph(nodes + 1);
	vector<bool> visited(nodes + 1);
	vector<int> dist(nodes + 1);
	stack<int> track;

	for (int i = 0; i < num; ++i) {
		cin >> n >> k;
		graph[n].push_back(k);
		graph[k].push_back(n);
	}

	dfs(graph, track, s, visited, dist);
}