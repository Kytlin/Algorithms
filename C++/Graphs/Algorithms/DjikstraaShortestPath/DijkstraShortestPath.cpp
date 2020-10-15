#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> edges, vector<bool> visited, vector<int> dist, int s) {
	int min = INT_MAX, minNode = 0;
	bool visit = false;
	visited[s] = true;

	for (int i = 0; i < edges[s].size(); ++i) {
		pair<int, int> p = edges[s][i];
		if (!visited[p.first] && (dist[s] + p.second < dist[p.first])) {
			visit = true;
			dist[p.first] = dist[s] + p.second;
			if (min > p.second) {
				min = p.second;
				minNode = p.first;
			}
		}
	}
	if (!visit) {
		for (int i = 0; i < edges.size(); ++i) {
			cout << i << ": " << dist[i] << '\n';
		}
	}
	else {
		dijkstra(edges, visited, dist, minNode);
	}
}

int main()
{
	int n, k, w, num, s;

	cin >> num >> s;

	vector<vector<pair<int, int>>> edges(num + 1);
	vector<bool> visited(num + 1);
	vector<int> dist(100001);

	for (int i = 0; i < dist.size(); ++i) {
		if (i != s) {
			dist[i] = INT_MAX;
		}
	}

	for (int i = 0; i < num; ++i) {
		cin >> n >> k >> w;
		edges[n].push_back(make_pair(k, w));
		edges[k].push_back(make_pair(n, w));
	}

	dijkstra(edges, visited, dist, s);
}