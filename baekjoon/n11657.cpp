#include<iostream>
#include<vector>

using namespace std;

int n, m;
int a, b, c;
vector <pair<int, int>> map[505];
long long arr[505];
bool c2 = false;

int main() {

	cin >> n >> m;

	for (int i = 0; i < m;i++) {
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b,c));
	}

	for (int i = 0; i <= n; i++) {
		arr[i] = 50000000000;
	}


	arr[1] = 0;

	for (int i = 1; i <= n; i++) {//n번 반복
		for (int j = 1; j <= n;j++) { //현재노드
			for (int k = 0; k < map[j].size();k++) { //인접노드
				int node = map[j][k].first;
				int w = map[j][k].second;

				if (arr[j]!=50000000000 &&arr[node] > arr[j] + w) {
					arr[node] = arr[j] + w;

					if (i == n) { c2 = true; }
				}
			}
		}
	}

	if (c2==true) {
		cout << "-1";
	}
	else {
		for(int i=2;i<=n;i++){
			if (arr[i] == 50000000000) { cout << "-1\n"; }
			else { cout << arr[i]<<"\n"; }
		}
	}
	return 0;
}