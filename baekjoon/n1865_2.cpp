#include<iostream>
#include<vector>
using namespace std;


int t;
int n, m, w;//����,����,��Ȧ
int a, b, c;
int dist[505];
int inf = 987654321;
vector<pair<int,int>>map[505];

void init(int n) {

	for (int i = 1; i <= n;i++) {
		dist[i] = inf;
		map[i].clear();
	}

}

int bellman(int start) {
	dist[start] = 0;
	for (int i = 0; i < n;i++) { //node�� ������ŭ �ݺ�
		for (int j = 1; j <= n;j++) {//����忡 ���ؼ�
			for (int k = 0; k < map[j].size();k++) { //������� �湮
				if (dist[map[j][k].first] > dist[j]+map[j][k].second) { //���Ű���
					dist[map[j][k].first] = dist[j] + map[j][k].second;//����
					if (i == n - 1)return 1;//yes
				}
			}
		}
	}
	return 0;
}

int main() {

	cin >> t;

	while (t--) {
	
		cin >> n >> m >> w;
		init(n);
		while (m--) {
			cin >> a >> b >> c;
			map[a].push_back(make_pair(b, c));
			map[b].push_back(make_pair(a, c));
		}
		while (w--) {
			cin >> a >> b >> c;
			map[a].push_back(make_pair(b, -c));
		}

	
		if (bellman(1) == 1)cout << "YES\n";
		else { cout << "NO\n"; }
	}

	return 0;
}