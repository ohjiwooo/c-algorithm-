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

void p() {
	cout << "==============\n";
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cout << map[i][j] << " ";
		}cout << "\n";
	}

}
bool f1() {
	int island = 0;
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

	p();

	bool ans = false;;
	for (int i = 0; i < num; i++) {//다 녹았나 확인
		int ni = v[i].i;
		int nj = v[i].j;

		if (map[ni][nj] != 0) {
			ans = true;
		}
	}
	if (ans == false) { return ans; }//다 녹으면 종료

	else {//다 안녹아서 섬 세기

		bool vis[350][350] = { false };
		queue <pair<int, int>>qq;

		for (int i = 0; i < num; i++) {//주변 0 개수

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
	}
	if (island >= 2) { cout << year; return true; }

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
	for (int i = 0; i < m; i++) {
		map[0][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		map[n-1][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		map[i][0] = 0;
	}
	for (int i = 0; i < m; i++) {
		map[i][m-1] = 0;
	}
	while (1) {
		year++;
		bool a = f1();
		if (a == false) { cout << 0; return 0; }
		else if (a == true) { return 0; }
	}
	return 0;
}