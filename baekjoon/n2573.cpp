#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct s {

	int i;
	int j;
	int n = 0;
}s;
int n, m;
int map[350][350] = { 0 };
int year = 0;
int num = 0;
int imap[4] = { 0,0,1,-1 };
int jmap[4] = { 1,-1,0,0 };
vector <s> v(10005);

int f1() {

	int island = 0;

	bool vis[350][350] = { false };
	queue <pair<int, int>>qq;

	for (int i = 0; i < num; i++) {//섬세기

		if (map[v[i].i][v[i].j] != 0 && vis[v[i].i][v[i].j] != true) { qq.push(make_pair(v[i].i, v[i].j)); island++; }

		while (qq.empty() != true) {
			int ni = qq.front().first;
			int nj = qq.front().second;
			qq.pop();
			for (int k = 0; k < 4; k++) {
				if (ni + imap[k] >= 0 && ni + imap[k] < n && nj + jmap[k] >= 0 && nj + jmap[k] < m && map[ni + imap[k]][nj + jmap[k]] != 0 && vis[ni + imap[k]][nj + jmap[k]] != true) {
					qq.push(make_pair(ni + imap[k], nj + jmap[k]));
					vis[ni + imap[k]][nj + jmap[k]] = true;
				}
			}
		}
	}
	if (island == 0) { cout << 0; return 0; }
	if (island==1) {
	
		for (int i = 0; i < num; i++) {//주변 0 개수
			int ni = v[i].i;
			int nj = v[i].j;
			v[i].n = 0;
			if (map[ni][nj] != 0) {
				for (int j = 0; j < 4; j++) {
					if (ni + imap[j] >= 0 && ni + imap[j] < n && nj + jmap[j] >= 0 && nj + jmap[j] < m && map[ni + imap[j]][nj + jmap[j]] == 0) {
						v[i].n++;
					}
				}
			}
		}

		for (int i = 0; i < num; i++) {//1년후 녹임
			int ni = v[i].i;
			int nj = v[i].j;

			if (map[ni][nj] != 0) {
				map[ni][nj] -= v[i].n;
				if (map[ni][nj] < 0) { map[ni][nj] = 0; }
			}
		}
		return 1;
	}
	
	if (island >= 2) { cout << year; return 0; }
	
}


int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				v[num].i = i;
				v[num++].j = j;
			}
		}
	}

	while (1) {
		int a = f1();
		if (a == 0) { return 0; }
		year++;
	}
	return 0;
}