#include<iostream>
#include<queue>
#include<vector>

using namespace std;
vector<pair<int, int>>v[200005];
int v2[200005][3];
bool vis[200005];
int main() {

	int n = 0; int m = 0; int a = 0; int b = 0; int c = 0;
	
	cin >> n >> m;

	for (int i = 0; i < m;i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
		v2[i][0] = a; v2[i][1] = b; v2[i][2] = c;
	}
	int num = 0;
	int answer = 0;
	for (int i = 0; i < m;i++) {
		priority_queue<pair<int, int>> pq;
		answer = 0;
		vis[1] = true;
		int now_node = 1;
		while (num < n - 1) {
			for (int i = 0; i < v[now_node].size(); i++) {
				if (vis[v[now_node][i].first] != true) {
					pq.push(make_pair(-v[now_node][i].second, v[now_node][i].first));
				}
			}
			while (1) {
				int w = -pq.top().first; int node = pq.top().second; pq.pop();
				if (vis[node]!=true) {
					now_node = node; answer += w; vis[node] = true; num += 1; break;//노드변경, 답갱신
				}
			}
			
		}
		cout << answer << "\n";
	}


}