#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dist[1002][1002];
int map[1002][1002];
int answer[1002];
int inf = 987654321;

void init(int n) {

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			if (i == j)continue;
			dist[i][j] = inf;
		}
	}
}

int fw(int n,int x) {

	for (int k = 1; k <= n;k++) {
		for (int i = 1; i <= n;i++) {
			for (int j = 1; j <= n;j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n;i++) {
		answer[i] = dist[i][x] + dist[x][i];
		ans = max(ans, answer[i]);
	}
	return ans;
}
int main() {


	int n, m,x;// 마을수, 도로수
	int a, b, c;
	cin >> n >> m >> x;
	init(n);
	for (int i = 0; i < m;i++) {
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	cout<<fw(n,x);

}