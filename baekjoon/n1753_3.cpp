#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int n, m, start; //������ ������ ���۳��
int a, b, c;
vector<pair<int,int>> v[20002];
priority_queue <pair<int, int>>q;
bool vis[20002];
int dis[20002];
int inf = 987654321;

void init() {

	for (int i = 1; i <= n;i++) {
		dis[i] = inf;
	} // �Ÿ� �ʱ�ȭ

	dis[start] = 0;
	q.push(make_pair(0, start));
	
}

void dijk() {

	while (q.empty()!=true) {
	
		int w = -q.top().first; int node = q.top().second; q.pop();

		if (vis[node] == true) continue;
		vis[node] = true;

		for (int i = 0; i < v[node].size();i++) {
			dis[v[node][i].first] = min(dis[v[node][i].first], dis[node] + v[node][i].second);
			q.push(make_pair(-dis[v[node][i].first],v[node][i].first));
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> start;

	for (int i = 0; i < m;i++) {
		cin >> a >> b >> c; //a���� b�ΰ��� ����� ����� c
		v[a].push_back(make_pair(b, c));
	}

	init();
	dijk();

	for (int i = 1; i <= n;i++) {
		if (dis[i] == inf)cout << "INF\n";
		else {
			cout << dis[i] << "\n";
		}
	}

	return 0;
}