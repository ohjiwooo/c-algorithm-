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
	queue<pair<int, int>> qq2;
	qq.push(make_pair(a, b));
	vis[a][b] = true;

	while (qq.empty()!=true) {

		int ni = qq.front().first;
		int nj = qq.front().second;
		qq.pop();

		if (map[ni+imap[0]][nj+jmap[0]]==0 || map[ni + imap[1]][nj + jmap[1]] == 0 || map[ni + imap[2]][nj + jmap[2]] == 0 || 
			map[ni + imap[3]][nj + jmap[3]] == 0 ) {
			qq2.push(make_pair(ni, nj));//밖 부분일경우
		}
		else {//아닐경우
			for (int i = 0; i < 4; i++) {
				int newi = ni + imap[i];
				int newj = nj + jmap[i];
				if (newi >= 0 && newi < n && newj >= 0 && newj < m && map[newi][newj] != 0 && vis[newi][newj]!=true) {
					qq.push(make_pair(newi, newj));
					vis[newi][newj] = true;
				}
			}
		}
	}
	
	int arr[150] = {150};
	while (qq2.empty() != true) {
		int ni = qq2.front().first;
		int nj = qq2.front().second;

		for (int i = 0; i < 4;i++) {
			int a = ni;
			int b = nj;
			int d = 0;
			while (a+imap[i] >= 0 && a+imap[i] < n && b+jmap[i]>=0 && b+jmap[i] <m) {
				if (map[a+imap[i]][b+jmap[i]] != 0) {
					if (map[a + imap[i]][b + jmap[i]] > d ) {
						map[a + imap[i]][b + jmap[i]] = d;
					}
				}
				d++;
			}
		}
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