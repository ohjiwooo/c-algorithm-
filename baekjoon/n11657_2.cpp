#include<iostream>
#include<vector>
using namespace std;

vector <pair<int,int>>v[505];
int INF = 987654321;
long long dist[505]; //longlong 안해서 틀림


bool bellman(int start,int n) {

	dist[start] = 0;
	int flag = 0;
	for (int i = 1; i <= n;i++) {	
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < v[j].size();k++) {
				if (dist[j]!= INF && dist[v[j][k].first] > dist[j]+v[j][k].second) {
					dist[v[j][k].first] = dist[j] + v[j][k].second;
					if (i == n) flag = 1; //n번째 변경시 음의 싸이클 발생
				}
			}
		}
	}

	if (flag == 1) return true;
	else { return false; }
}

void init(int n) {

	for (int i = 1; i <= n;i++) {
		dist[i] = INF;
	}


}

int main() {

	int n, m,s,e,w;
	cin >> n >> m;

	for (int i = 0; i < m;i++) {
		cin >> s >> e >> w;
		v[s].push_back(make_pair(e, w));
	}

	init(n);
	if (bellman(1,n) == true) cout << -1;
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF)cout << "-1\n";
			else { cout << dist[i] << "\n"; }
		}
	}

	return 0;
}