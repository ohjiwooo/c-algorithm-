#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;//도시의 수, 버스의 수
int a, b, c;
int inf = 987654321;
int dist[105][105];


void init() {
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			if (i == j)dist[i][j] = 0;
			else { dist[i][j] = inf; }
		}
	}

}

void fw() {

	for (int k = 1; k <= n;k++) {
		for (int i = 1; i <= n;i++) {
			for (int j = 1; j <= n;j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main() {

	cin >> n >> m;
	
	init();
	while (m--) {
		
		cin >> a >> b >> c; //a에서 b로 가는데 비용 c
		dist[a][b] = min(dist[a][b], c);
	
	}
	fw();
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == inf)dist[i][j] = 0;
			cout << dist[i][j] << " ";
		}cout << "\n";
	}
	return 0;
}