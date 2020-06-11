#include<iostream>
#include<queue>
#include<vector>


using namespace std;

int v;//��������
int e;//���� ����
int start;//������
vector <pair<int,int>> graph[20002];
int arr[20002]; //�Ÿ�
bool vis[20002];//�湮����
int node = 0;
int w = 0;
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qq;

int a, b,c;


int main() {

	cin >> v >> e>>start;

	for (int i = 0; i < e;i++) {
		
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b,c));

	}
	
	for (int i = 1; i <= v; i++) {
		arr[i] = 987654321;
		vis[i] = false;

	} //�ʱ�ȭ
	
	arr[start] = 0;
	

	
	qq.push(make_pair(0,start));

	while (qq.empty() != true) {
		w = qq.top().first;
		node = qq.top().second;
		qq.pop();
		
		if (vis[node]) {  //�湮 �������� ���
			continue;
		}
		vis[node] = true; //�湮 üũ

		for (int i = 0; i < graph[node].size(); i++) {
		
				int node2 = graph[node][i].first;
				int w2 = graph[node][i].second;

				if (arr[node2] > w2 + w) {
					arr[node2] = w2 + w;
					qq.push(make_pair(arr[node2],node2));
				}
			

		}
	}
	
	for (int i = 1; i <= v; i++) {
		if (arr[i] == 987654321) {
			cout << "INF" ;
		}
		else { cout << arr[i]; }
		cout << "\n";
	}
	
	return 0;
}