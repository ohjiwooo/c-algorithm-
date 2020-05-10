#include<iostream>
#include<queue>
#include<stack>

using namespace std;

const int max_num = 1000;
int graph[max_num][max_num];

int n; //노드의 개수
int m; //간선의 개수
int a, b; //입력때 쓰임

stack <int> s;
bool visited[max_num];





void print(int a[max_num][max_num], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j];
		}
		cout << "\n";
	}

}

void bfs() {
	queue<int> q;

	q.push(0);
	visited[0] = true;
	int level = 0;

	while (q.empty() != true) {
		int size = q.size();
		cout << "\n====" << level << "====\n";
		for (int i = 0; i < size; i++) {
			int qur = q.front();
			q.pop();
			cout << " " << qur << " ";
			for (int i = 0; i < n; i++) {
				if ((graph[qur][i] == 1) && (visited[i] != true)) {
					q.push(i);
					visited[i] = true;
				}
			}
		}
		level++;
	}

}

void dfs(int now) {



	visited[now] = true;


	cout << " " << now << " ";

	for (int i = 0; i < n; i++) {
		if ((graph[now][i] == 1) && (visited[i] != true)) {
			dfs(i);

		}
	}




}


int main() {

	cout << "n입력: ";
	cin >> n;
	cout << "\n m입력: ";
	cin >> m;
	cout << "\n값입력";

	for (int j = 0; j < m; j++) {

		cin >> a;
		cin >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;

	}

	//	cout << "------print-------\n";
	//	print(graph,n);

	//	cout << "-----너비우선탐색 실행------\n";
	//	bfs();

	dfs(0);


	return 0;
}