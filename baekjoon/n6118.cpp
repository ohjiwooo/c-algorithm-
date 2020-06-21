#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


vector <pair<int, int>> map[50005]; //지도
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n, m;//헛간수,길수
int arr[50005];
bool vis[50005];
int a, b;
int node, w;
int ans1, ans2;
int ans3=0;
int arr2[50005];

bool compare(int a, int b) {
	return a > b;
}




int main() {

	cin >> n >> m;

	for (int i = 1; i <= m ;i++) {
		cin >> a >> b;
		map[a].push_back(make_pair(b,1));
		map[b].push_back(make_pair(a,1));
	}
	
	for (int i = 1; i <=n ;i++) {

		vis[i] = false;
		arr[i] = 987654321;
	}

	arr[1] = 0;
	pq.push(make_pair(0,1)); //가중치-노드번호 순서로 삽입

	while (pq.empty() != true) {
		node = pq.top().second;
		w = pq.top().first;
		pq.pop();

		if (vis[node]) {
			continue;
		}
		vis[node] = true;

		for (int i = 0; i < map[node].size();i++) {
			int node2 = map[node][i].first;
			int w2 = map[node][i].second;

			if (arr[node2] > w + w2) {
				arr[node2] = w + w2;
				pq.push(make_pair(arr[node2],node2));
			}
		}

	}
	for (int i = 1; i <= n; i++) {
		arr2[i] = arr[i];
	}
	sort(arr+1,arr+1+n,compare);
	ans2 = arr[1];

	for (int i = 1; i <= n; i++) {
		if (arr[i] == ans2) {
			ans3++;
		}
		else { break; }
	}

	for (int i = 1; i <= n; i++) {
		if (arr2[i] == arr[1]) {
			ans1 = i;
			break;
		}
		
	}
	cout << ans1 << " " << ans2 << " " << ans3;
	return 0;

}