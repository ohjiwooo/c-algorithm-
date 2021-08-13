#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int INF = 987654321;
vector<pair<int,int>>arr[20004];
bool vis[20004];
int dist[20004];

priority_queue <pair<int, int>>pq;

void dijk(int start) {

	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (pq.empty()!=true) {
		int now = pq.top().second; int w = -pq.top().first; pq.pop();

		if (vis[now]) {  //방문 안했으면 계속
			continue;
		}
		vis[now] = true; //방문 체크


		for (int i = 0; i < arr[now].size();i++) { //인접노드 방문
			int newnode = arr[now][i].first; int neww = arr[now][i].second;
			int answer = min(dist[newnode], dist[now] + neww);
			dist[newnode] = answer; pq.push(make_pair(-answer, newnode));

		}
	
	}

}


int main() {

	int v, e,start,a,b,c;
	cin >> v >> e>>start;

	for (int i = 0; i < e;i++) {
		
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
	
	}


	for (int i = 1; i <= v;i++) {
		dist[i] = INF;
	}

	dijk(start);

	for (int i = 1; i <= v;i++) {

		if (dist[i] == INF)cout << "INF\n";
		else {
			cout << dist[i] << "\n";
		}
	}

	return 0;
}