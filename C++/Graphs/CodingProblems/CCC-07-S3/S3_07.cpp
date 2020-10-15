// Date: 08/31/20
/* Program: Solution to "CCC '07 S3: Friends" */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> graph, int s, int e) {
	vector<bool> visited(graph.size());
	vector<int> dist(graph.size());
	queue<int> q;
	bool found = false;

	q.push(s);

	while (!q.empty()) {
		int f = q.front();
		q.pop();

		for (int i = 0; i < graph[f].size(); ++i) {
			if (!visited[graph[f][i]]) {
				if (graph[f][i] == e) {
					found = true;
				}

				q.push(graph[f][i]);
				dist[graph[f][i]] = dist[f] + 1;
				visited[graph[f][i]] = true;
			}
		}

		if (found) {
			cout << "Yes " << dist[e] - 1 << '\n';
			break;
		}
	}

	if (!found) {
		cout << "No\n";
	}
}

int main()
{
	vector<vector<int>> graph(10001);
	int n, a, b, x, y;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
	}

	while (true) {
		cin >> x >> y;
		if (x == 0) {
			break;
		}
		else {
			bfs(graph, x, y);
		}
	}
}