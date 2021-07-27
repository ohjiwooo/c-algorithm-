#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int dist[105][105];
int n, m, a, b, c;
int INF = 987654321;

void fw() {

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n;j++) { //k 를 거처갈때의 최단거리 갱신
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}




}
int main() {



	
	cin >> n >> m;

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			if (i == j)continue;
			dist[i][j] = INF;
		}
	}
	for (int i = 0; i < m;i++) {
		cin >> a >> b >> c;
		dist[a][b] =min(c,dist[a][b]); 
	}


	fw();

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			if (dist[i][j]==INF) {
				cout << "0 ";
			}
			else {
				cout << dist[i][j] << " ";
			}
		}cout << "\n";
	}


	return 0;
}