#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

priority_queue <pair<int,int>> pq;
int map[55][55];
bool vis[55][55];
int imap[4] = { -1,0,1,0 };
int jmap[4] = { 0,1,0,-1 };
int inf = 987654321;
int dis[55][55];


int dijk(int n) {
	
	priority_queue <pair<int,pair<int, int>>> pq;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			dis[i][j] = inf;
		}
	}
	
	dis[0][0] = 0;
	pq.push(make_pair(0, make_pair(0, 0)));

	while (pq.empty()!=true) {
		int ni = pq.top().second.first; int nj = pq.top().second.second; int nw = -pq.top().first; pq.pop();
		vis[ni][nj] = true;

		for (int i = 0; i < 4;i++) {
			if ( ni+imap[i] >=0 && ni+imap[i] <n && nj+jmap[i] >=0 && nj+jmap[i] < n && vis[ni+imap[i]][nj+jmap[i]]!=true) {
				dis[ni + imap[i]][nj + jmap[i]] = min(dis[ni + imap[i]][nj + jmap[i]], dis[ni][nj] + map[ni + imap[i]][nj + jmap[i]]);
				vis[ni + imap[i]][nj + jmap[i]] = true;
				pq.push(make_pair(-dis[ni + imap[i]][nj + jmap[i]], make_pair(ni + imap[i], nj + jmap[i])));
			}
		}

	}
	
	return dis[n - 1][n - 1];
	
}

int main() {

	int n = 0; 
	cin >> n ;
	string s;

	for (int i = 0; i < n;i++) {
		cin >> s;
		for (int j = 0; j < n;j++) {
			map[i][j] = s[j] - '0';
			if (map[i][j]==0) {
				map[i][j] = 1;
			}
			else {
				map[i][j] = 0;
			}
		}
	}
	
	cout<<dijk(n);
	return 0;
}