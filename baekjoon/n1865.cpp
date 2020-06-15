#include<iostream>
#include<vector>

using namespace std;

bool ans;
int n, m, w,num;
int a, b, c;
int arr[505];


int main() {
	cin >> num;
	
	while ( num>0) {

		cin >> n >> m >> w;
		vector <pair<int, int>> map[505];

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			map[a].push_back(make_pair(b,c));
			map[b].push_back(make_pair(a, c));

		}
		for (int i = 0; i < w; i++) {
			cin >> a >> b >> c;
			map[a].push_back(make_pair(b, -c));

		}
	
		for (int i = 1; i <= n; i++) {
			arr[i] = 987654321;
		}

		ans = false;

		arr[1] = 0;
		for (int i = 1; i <= n;i++){ //n번순환
			for (int j = 1; j <= n; j++) { //현재노드
				for (int k = 0; k < map[j].size();k++) { //인접노드 탐색
					int node = map[j][k].first;
					int w = map[j][k].second;

					if (arr[node] > w + arr[j]) {
						arr[node] = w + arr[j];
						if (i == n) { ans = true; }
					}
				}
			}
		}
		if (ans == true) { cout << "YES\n"; }
		else { cout << "NO\n"; }
		num--;
	}

	
	return 0;
}