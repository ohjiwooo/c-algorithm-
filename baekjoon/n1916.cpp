#include<iostream>
#include<queue>
#include<vector>

using namespace std;

priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n,m;
int a, b, c;
bool vis[1005];
int arr[1005];
vector <pair<int, int>> map[1005];
int s,d;
int w1, w2, n2, n1;

int main() {

	cin >> n >> m;

	for (int i = 0; i < m;i++) {
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b,c));
	}

	cin >> s >> d;

	for (int i = 1; i <= n;i++) {
		vis[i] = false;
		arr[i] = 987654321;
	}

	
	arr[s] = 0;
	pq.push(make_pair(0,s));

	while (pq.empty()!=true) {
		w1 = pq.top().first; //현재가중치
		n1 = pq.top().second; //현재노드
		pq.pop();
		

		if (vis[n1]) {  //방문 안했으면 계속
			continue;
		}
		vis[n1] = true; //방문 체크

		for (int i = 0; i < map[n1].size();i++) {
			n2 = map[n1][i].first;
			w2 = map[n1][i].second;

			if (arr[n2] > w1+w2) {
				arr[n2] = w2 + w1;
				pq.push(make_pair(arr[n2],n2));
			}
		}
	}

	cout << arr[d];

	return 0;
}