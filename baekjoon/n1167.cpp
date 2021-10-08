#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int n;
int num,a,b;
int answer = 0;
int start;
vector <pair<int,int>>v[100005];
bool vis[100005];
int imap[4] = { 0,1,0,-1 };
int jmap[4] = { 1,0,-1,0 };

void bfs(int node,int count) {

	if (answer < count) {
		answer = count;
		start = node;
	}
	
		for (int i = 0; i < v[node].size();i++) {
			if (vis[v[node][i].first]==false) {
				vis[v[node][i].first] = true;
				bfs(v[node][i].first, count + v[node][i].second);
				vis[v[node][i].first]= false;
			}
		}
	
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n;i++) {
		cin >> num>>a;
		while (a!=-1) {
			cin >> b;
			v[num].push_back(make_pair(a,b));
			cin >> a;
		}
	}

	
	vis[1] = true;
	bfs(1,0);
	vis[1] = false;
	answer = 0;
	vis[start] = true;
	bfs(start, 0);
		
	
	cout << answer;
}