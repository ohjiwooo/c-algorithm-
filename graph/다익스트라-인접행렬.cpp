#include<iostream>
#include<queue>
#define inf 987654321;

using namespace std;

int v;//��������
int e;//���� ����
int start;//������
int graph[20002][20002];
int arr[20002]; //�Ÿ�
bool vis[20002];//�湮����
int node = 0;
int w = 0;
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qq;

int a, b, c;


int main() {

	cin >> v >> e >> start;

	for (int i = 1; i <= e; i++) {

		cin >> a >> b >> c;
		graph[a][b] = c;

	}

	for (int i = 1; i <= e; i++) {
		arr[i] = inf;
		vis[i] = false;

	} //�ʱ�ȭ

	arr[start] = 0;



	qq.push(make_pair(start, 0));

	while (qq.empty() != true) {
		node = qq.top().first;
		w = qq.top().second;
		qq.pop();

		if (vis[node]) {  //�湮 �������� ���
			continue;
		}
		vis[node] = true; //�湮 üũ

		for (int i = 1; i <= v; i++) {
			if (graph[node][i] != 0) {
				int node2 = i;
				int w2 = graph[node][i];

				if (arr[node2] > w2 + w) {
					arr[node2] = w2 + w;
					qq.push(make_pair(node2, arr[node2]));
				}
			}

		}
	}

	for (int i = 1; i <= v; i++) {
		if (arr[i] == 987654321) {
			cout << "INF";
		}
		else { cout << arr[i]; }
		cout << "\n";
	}

	return 0;
}