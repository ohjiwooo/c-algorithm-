#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 100;


vector <int> graph[MAX];
bool visited[MAX];
queue <int> qq;

int n;//정점의 개수
int m;// 간선의 개수
int a, b;//임시저장변수

void bfs() {

	qq.push(0);
	visited[0] = true;

	while (qq.empty() != true) {
		int cur = qq.front();
		qq.pop();
		cout << cur;
		cout << "\n";

		for (int i = 0; i < graph[cur].size(); i++) {
			if (visited[graph[cur][i]] != true) {
				qq.push(graph[cur][i]);
				visited[graph[cur][i]] = true;
			}
		}
	}


}

void dfs(int n) {

	visited[0] = true;
	cout << n <<"\n";

	for (int i = 0; i < graph[n].size(); i++) {

		if (visited[graph[n][i]] != true) {
			visited[graph[n][i]] = true;
			dfs(graph[n][i]);
		}

	}
}
int main() {

	
	cin >> n;
	cin >> m;

	for (int i = 0; i < m;i++) {
		cin >> a;
		cin >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	
	}
	bfs();
	dfs(0);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < graph[i].size();j++) {
			cout << graph[i][j];
		}
		cout << "\n";
	}

	return 0;
}