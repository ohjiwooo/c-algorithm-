#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int n, m;//도시수, 버스수
int a, b, c;

vector <pair<int, int>>v[505];
ll dist[505];
int inf = 987654321;
void init() {

	for (int i = 1; i <= n;i++) {
		dist[i] = inf;
	}

}

bool bellman(int start) {
	
	bool flag = false; //사이클이 있으면 true
	dist[start] = 0;
	for (int i = 0; i < n;i++) {
		for (int j = 1; j <= n; j++) { //모든 노드에 대해 반복
			if (dist[j] == inf)continue;
			for (int k = 0; k < v[j].size(); k++) {
				if (dist[v[j][k].first] > dist[j] + v[j][k].second) {
					dist[v[j][k].first] = dist[j] + v[j][k].second;
					if (i == n-1) flag = true; //n번째 변경시 음의 싸이클 발생
				}
			}
		}
	}

	return flag;
}

int main() {

	cin >> n >> m;

	while (m--) {
	
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	
	}

	init();

	if (bellman(1) == true)cout << -1;
	else {
		for (int i = 2; i <= n;i++) {
			if (dist[i] == inf)dist[i] = -1;
			cout << dist[i] << "\n";
		}
	
	}


	return 0;
}