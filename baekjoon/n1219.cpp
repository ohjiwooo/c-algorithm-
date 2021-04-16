#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int inf = 9876543210;

int dfs(queue <int> q,int e, vector <pair<long long, long long>> v[105]) {

	bool vis[105] = { false, };
	int f = 0;
	while (q.empty() != true) {
		int x = q.front(); q.pop();
		queue<int>qq;
		qq.push(x);
		while (qq.empty() != true) {
			int y = qq.front(); qq.pop();
			if (y == e) {
				return 1;
			}
			vis[y] = true;
			for (int i = 0; i < v[y].size(); i++) {
				if (vis[v[y][i].first] == false) {
					qq.push(v[y][i].first);
					vis[v[y][i].first] = true;
				}
			}
		}
	}
	return 0;




}


int bellan(vector <pair<long long,long long>> v[105],long long n,long long s, long long e, long long make_money[105]) {
	
	long long dis[105];
	for (int i = 0; i < 105; i++) { dis[i] = inf; }
	dis[s] = -make_money[s];
	int flag = 0;
	queue <int> q;
	for (int i = 0; i < n;i++) { //도시수 만큼 반복
		for (int j = 0; j < n;j++) { //전체 도시반복
			if (dis[j] == inf) { continue; }
			for (int k = 0; k < v[j].size(); k++) {
				int cost = v[j][k].second; int x = v[j][k].first;
				if (dis[x] > dis[j] + cost - make_money[x]) {
					if (i==n-1) {
						q.push(x);
					}
					else {
						dis[x] = dis[j] + cost - make_money[x];
					}
				}
			}
		}
	}

	if (dfs(q, e, v) == 1) { cout << "Gee"; return 0; }
	if (dis[e] == inf) { cout << "gg"; return 0; }
	else { cout << -dis[e]; return 0; }

}

int main() {

	long long n = 0; long long s = 0; long long e = 0; long long m = 0;
	vector <pair<long long, long long>> v[105];
	long long make_money[105] = { 0, };

	cin >> n >> s >> e >> m;
	long long a = 0; long long b = 0; long long c = 0;
	for (int i = 0; i < m;i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b,c));
	}
	for (int i = 0; i < n; i++) {
		cin >> make_money[i];
	}

	bellan(v, n, s, e, make_money);
	return 0;
}