#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int t,n, d, s; //testcase,컴퓨터갯수,의존성개수,해킹당한 컴퓨터 번호
int a, b, c;//a가 b의존하여 c시간뒤 감염
bool vis[10004];
int dist[10004];
int inf = 987654321;

vector<pair<int, int>>map[10004];

void init(int n) {

	
	
	for (int i = 1; i <= n;i++) {
		vis[i] = false;
		map[i].clear();
		dist[i] = inf;
	}

}
pair<int,int> dijk(int start) {

	int count = 0;
	int maxx = 0;
	dist[start] = 0;
	priority_queue <pair<int, int>>pq;
	pq.push(make_pair(0, start));

	while (pq.empty()!=true) {
		int w = -pq.top().first; int node = pq.top().second; pq.pop();
		if (vis[node] == true)continue;
		vis[node] = true;
		

		for (int i = 0; i < map[node].size();i++) {
			int new_node = map[node][i].first; int new_w = map[node][i].second;
			dist[new_node] = min(dist[new_node], dist[node] + new_w);
			pq.push(make_pair(-dist[new_node], new_node));
		}
	}
	for (int i = 1; i <= n;i++) {
		if (dist[i] != inf) {
			count++;
			maxx = max(maxx, dist[i]);
		}
	}
	return make_pair(count, maxx);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	while (t--) {

		
		cin >> n >> d >> s;
		init(n);
		pair<int, int>answer;
		while (d--) {
			cin >> a >> b >> c;
			map[b].push_back(make_pair(a, c)); //b에서 a로 가는데 c만큼 걸림
		}
		
		answer = dijk(s);
		cout << answer.first << " " << answer.second << "\n";

	}

	return 0;
}