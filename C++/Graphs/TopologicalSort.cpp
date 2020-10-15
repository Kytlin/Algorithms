// Date: 08/30/20
/* Program: Runs "Topological Sort" and outputs the
order of backtracking nodes (based on "Depth First Search")  */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void dfs(vector<vector<int>> graph, int s) {
	vector<bool> visited(graph.size());
	vector<int> dist(graph.size());
	stack<int> st;
	queue<int> order;
	bool visit = false;

	visited[s] = true;
	st.push(s);

	while (!st.empty()) {
		int f = st.top();
		visit = false;

		for (int i = 0; i < graph[f].size(); ++i) {
			if (!visited[graph[f][i]]) {
				st.push(graph[f][i]);
				dist[graph[f][i]] = dist[f] + 1;
				visited[graph[f][i]] = true;
				visit = true;
				break;
			}
		}
		if (!visit) {
			order.push(f);
			st.pop();
		}
	}

	cout << "Order: ";
	while (!order.empty()) {
		cout << order.front() << ' ';
		order.pop();
	}
	cout << '\n';
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

	dfs(graph, s);
}