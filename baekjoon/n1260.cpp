#include<iostream>
#include<queue>
#include<stack>

using namespace std;

//const int max_num = 1001;
int graph[1001][1001];
bool visited[1001];
bool visited1[1001];
int n; //노드의 개수
int m; //간선의 개수
int now;//시작점
int a, b; //입력때 쓰임
stack <int> s;

void bfs(int now) {
	queue<int> q;
	q.push(now);
	visited[now] = true;
	
	while (q.empty() != true) {
		int qur = q.front();
		q.pop(); 
		cout << qur << " ";
			for (int i = 1; i <= n; i++) {
				if ((graph[qur][i] == 1) && (visited[i] != true)) {
					q.push(i);
					visited[i] = true;
				}
			}
		
	}
}


void dfs(int now) {
	visited1[now] = true;
	cout << now<<" ";

	for (int i = 1; i <=n; i++) {
		if ((graph[now][i] == 1) && (visited1[i] != true)) {
			dfs(i);

		}
	}
}


int main() {

	cin >> n;
	cin >> m;
	cin >> now;

	for (int j = 0; j < m; j++) {

		cin >> a;
		cin >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;

	}
	dfs(now);
	cout << "\n";
	bfs(now);

	return 0;
}