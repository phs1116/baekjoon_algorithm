#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
int node[1000][1000];
int n, m, v, a, b;
queue<int> q;
stack<int> s;
void bfs() {
	int k, visited[1000];
	memset(visited, 0, sizeof(visited));
	q.push(v);
	visited[v] = 1;
	while (!q.empty()) {
		k = q.front();
		q.pop();
		cout << k << ' ';
		for (int i = 1; i <= n; i++) {
			if (node[k][i] == 1 && visited[i] != 1) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
	cout << endl;
}

void dfs() {
	int k, visited[1000];
	memset(visited, 0, sizeof(visited));
	s.push(v);
	visited[v] = 1;
	cout << v << ' ';
	while (!s.empty()) {
		for (int i = 1; i <= n; i++) {
			if (node[s.top()][i] == 1 && visited[i] != 1) {
				s.push(i);
				cout << i << ' ';
				visited[i] = 1;
				i = 0;
			}
		}
		s.pop();
	}
	cout << endl;
}

int main() {
	cin >> n >> m >> v;
	for (int i = 0; i<m; i++) {
		cin >> a >> b;
		//인접노드 
		node[a][b] = node[b][a] = 1;
	}
	dfs();
	bfs();
}
