#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int n, m,a,b,c,s,d;
int dis[505];
bool vis[505];
vector<pair<int, int>>v[505];
int inf = 987654321;
vector <int> answer[505];
int way[505][505];
void init() {

	for (int i = 0; i < n;i++) {
		dis[i] = inf;
		vis[i] = false;
	}

}
	
int dijk(int start,int d) {

	init();

	priority_queue <pair<int, int>>q;
	dis[start] = 0;
	q.push(make_pair(0, start));

	while (q.empty()!=true) {

		int node = q.top().second; int w = -q.top().first; q.pop();
		if (vis[node] == true)continue;
		vis[node] = true;
		for (int i = 0; i < v[node].size();i++) {
			int tmp_ans = min(dis[v[node][i].first], dis[node] + v[node][i].second);
			if (dis[v[node][i].first] > tmp_ans) { //새로 갱신
				dis[v[node][i].first] = tmp_ans;
				answer[v[node][i].first].clear();
				answer[v[node][i].first].push_back(node); //이전꺼 삭제
			}
			else if (dis[v[node][i].first] == dis[node] + v[node][i].second) {
				answer[v[node][i].first].push_back(node); //같으면 답에 추가만 해줌	
			}
			q.push(make_pair(-dis[v[node][i].first], v[node][i].first));
		}

	}
	//최단경로 찾음


	queue<int>qq;
	qq.push(d);

	while (qq.empty() != true) {
		int node = qq.front(); qq.pop();
		for (int i = 0; i < answer[node].size();i++) {
			int now = answer[node][i];
			if (way[now][node] != 1) {
				qq.push(now); way[now][node] = 1;
			}
		}
	}
	
	init();

	dis[start] = 0;
	q.push(make_pair(0, start));

	while (q.empty() != true) {

		int node = q.top().second; int w = -q.top().first; q.pop();
		if (vis[node] == true)continue;
		vis[node] = true;
		for (int i = 0; i < v[node].size(); i++) {
			int tmp_ans = min(dis[v[node][i].first], dis[node] + v[node][i].second);
			
			if (dis[v[node][i].first] > tmp_ans && way[node][v[node][i].first]!=1) {
				dis[v[node][i].first] = tmp_ans;
				q.push(make_pair(-dis[v[node][i].first], v[node][i].first));
			}
		}
	}

	if (dis[d] == inf)return -1;
	else return dis[d];
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		cin >> s >> d;
		
		for (int i = 0; i < n;i++) {
			for (int j = 0; j < n;j++) {
				way[i][j] = 0;
			}
		}
		for (int i = 0; i < n;i++) {
			v[i].clear();
		}
		for (int i = 0; i < n; i++) {
			answer[i].clear();
		}
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			v[a].push_back(make_pair(b, c));
		}
		cout<<dijk(s,d)<<"\n";

	}
}