#include<iostream>
#include<queue>
using namespace std;

int n, m;
int map[15][15];
int imap[4] = { -1,0,1,0 };//위 오 아 왼
int jmap[4] = { 0,1,0,-1 };

void f(int nn,int a,int b) {

	queue <pair<int, int>>qq;
	int vis[15][15] = { false };
	qq.push(make_pair(a,b));
	map[a][b] = nn;
	vis[a][b] = true;

	while (qq.empty()!=true) {
		int ni = qq.front().first;
		int nj = qq.front().second;
		qq.pop();
		for (int i = 0; i < 4; i++) {
			if (ni+imap[i]>=0 && ni+imap[i]<n && nj+jmap[i] >=0 && nj+jmap[i]<m && map[ni+imap[i]][nj+jmap[i]]==1 && vis[ni + imap[i]][nj + jmap[i]] != true) { //범위를 안넘어가고 같은땅일때
				map[ni + imap[i]][nj + jmap[i]] = nn;
				vis[ni + imap[i]][nj + jmap[i]] = true;
				qq.push(make_pair(ni+imap[i],nj+jmap[i]));
			}
		}
	}
}

int numbering() {

	int nn = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]==1) {
				f(nn++,i,j);
			}
		}
	}
	return --nn;
}

void ff(int a,int b,int vis[15][15]) {

	queue<pair<int, int>> qq;

	qq.push(make_pair(a, b));
	vis[a][b] = true;

	while (qq.empty()!=true) {

		int ni = qq.front().first;
		int nj = qq.front().second;
		qq.pop();


	
	}

}

void find() {

	int vis[15][15] = { false };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0 && vis[i][j]!=true) {
				ff();
			}
		}
	}

}


int main() {

	int num;//섬의개수

	cin >> n >> m;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cin >> map[i][j];
		}
	}

	num = numbering();



	return 0;
}