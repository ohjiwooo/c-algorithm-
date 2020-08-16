#include<iostream>
#include<queue>
using namespace std;

int n, m;
int map[15][15];
int imap[4] = { -1,0,1,0 };//위 오 아 왼
int jmap[4] = { 0,1,0,-1 };
int num;//섬의개수
int ans = 0;

void f(int nn,int a,int b,bool vis[15][15]) {

	queue <pair<int, int>>qq;
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
	bool vis[15][15] = { false };
	int nn = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]==1 && vis[i][j]!=true) {
				f(nn++,i,j,vis);
			}
		}
	}
	return --nn;
}

bool ff(int a,int b,int vis[15][15]) {
	queue<pair<int, int>> qq;
	queue<pair<int, int>> qq2;
	qq.push(make_pair(a, b));
	vis[a][b] = true;

	while (qq.empty()!=true) {

		int ni = qq.front().first;
		int nj = qq.front().second;
		qq.pop();

		if ((ni-1 >= 0 && map[ni+imap[0]][nj+jmap[0]]==0) ||(nj+1 <m && map[ni + imap[1]][nj + jmap[1]] == 0) 
			||(ni+1 < n && map[ni + imap[2]][nj + jmap[2]] == 0 )||(nj-1 >=0 && map[ni + imap[3]][nj + jmap[3]] == 0) ) {
			qq2.push(make_pair(ni, nj));//밖 부분일경우
		}
		for (int i = 0; i < 4; i++) {
			int newi = ni + imap[i];
			int newj = nj + jmap[i];
			if (newi >= 0 && newi < n && newj >= 0 && newj < m && map[newi][newj] != 0 && vis[newi][newj]!=true) {
				qq.push(make_pair(newi, newj));
				vis[newi][newj] = true;
			}
		}
	}
	
	int arr[150] = {150};
	while (qq2.empty() != true) {
		int ni = qq2.front().first;
		int nj = qq2.front().second;
		qq2.pop();
		for (int i = 0; i < 4;i++) {
			int ti = ni;
			int tj = nj;
			int d = 0;
			while (ti+imap[i] >= 0 && ti+imap[i] < n && tj+jmap[i]>=0 && tj+jmap[i] <m ) {
				if (map[ti+imap[i]][tj+jmap[i]] != 0 && map[ti + imap[i]][tj + jmap[i]] != map[a][b]) {
					if (arr[map[ti + imap[i]][tj + jmap[i]]] > d ) {
						arr[map[ti + imap[i]][tj + jmap[i]]] = d;
						break;
					}
				}
				else if (map[ti + imap[i]][tj + jmap[i]] == map[a][b]) {
					break;
				}
				ti += imap[i];
				tj += jmap[i];
				d++;
			}
		}
	}
	for (int i = 1; i <=num;i++) {
		if (i!=map[a][b] && arr[i]!=150 && arr[i]>=2) {
			ans += arr[i];
		}
		else if (i !=map[a][b] && (arr[i]==150 || arr[i] <2)) {
			return false;
		}
	}
	return true;
}

bool find() {

	int vis[15][15] = { false };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0 && vis[i][j]!=true) {
				if (ff(i, j, vis) == false) { cout << -1; return false; }
			}
		}
	}

}


int main() {


	cin >> n >> m;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cin >> map[i][j];
		}
	}

	num = numbering();
/*	cout << "=======================\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout<< map[i][j]<<" ";
		}cout << "\n";
	}*/

	if (find() == false) { return 0; }

	cout << ans;

	return 0;
}