#include<iostream>
#include<vector>

using namespace std;

int n, m, w,num;
int a, b, c;
vector <pair<int, int>> map[505];
int arr[505];
int n1,n2, w1, w2;

int main() {
	cin >> num;

	while (num > 0) {
		
		cin >> n >> m >> w;

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			map[a].push_back(make_pair(b,c));
			map[b].push_back(make_pair(a, c));
		}

		for (int i = 0; i < w; i++) {
			cin >> a >> b >> c;
			map[a].push_back(make_pair(b, -c));
		}

		for (int i = 1; i <= n;i++) {
			arr[i] = 987654321;
		}

		arr[1] = 0;

		for (int i = 1; i <= n;i++) {
			n1 = i;
			w1 = arr[i];

			for (int j = 0; j < map[i].size(); j++) {
				n2 = map[i][j].first;
				w2 = map[i][j].second;

				if (arr[n2] > w1 + w2) {
					arr[n2] = w1 + w2;
				}
			}
		}




		num--;
	}
}