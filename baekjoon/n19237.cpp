#include<iostream>

using namespace std;

typedef struct s {

	int small_num;
	int small_time =0;
	int vis;
}s;

typedef struct ss {

	int now_d=0;
	int p[5][5];
	int i;
	int j;

}ss;

int n, m, k;//Ä­,»ó¾î,³¿»õ½Ã°£
s map[25][25];
s temp[25][25];
ss sh[500];
int imap[5] = {0,-1,1,0,0};
int jmap[5] = {0,0,0,-1,1};
int ans = 1;

bool check() {
	int a = 0;
	for (int i = 1; i <= m;i++) {
		if (sh[i].now_d !=0) {
			a++;
		}
	}
	if (a == 1) { return true; }
	return false;
}

void init_temp() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = map[i][j];
		}
	}

}
void init_map() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = temp[i][j];
		}
	}

}
void remove() {

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			if (map[i][j].small_time >0 && map[i][j].vis != 1) {
				map[i][j].small_time--;
				if (map[i][j].small_time==0) {
					map[i][j].small_num = 0;
				}
			}
			if (map[i][j].vis == 1) {
				map[i][j].vis = 0;
			}
		}
	}
}

void move_shark() {

	init_temp();
	int f = 0;

	for (int i = 1; i <= m; i++) {

		if (sh[i].now_d != 0) {
			int d = sh[i].now_d;
			int ni = sh[i].i;
			int nj = sh[i].j;

			f = 0;

			for (int j = 1; j < 5; j++) {
				if (ni + imap[sh[i].p[d][j]]>=0 && ni + imap[sh[i].p[d][j]]<n && nj + jmap[sh[i].p[d][j]]>=0 && nj + jmap[sh[i].p[d][j]]<n) {
					if (map[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].small_time == 0 & temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].vis == 0) {//empty

						temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].small_time = k;
						temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].small_num = i;
						temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].vis = 1;

						temp[ni][nj].vis = 0;
						sh[i].i = ni + imap[sh[i].p[d][j]];
						sh[i].j = nj + jmap[sh[i].p[d][j]];
						sh[i].now_d = sh[i].p[d][j];
						f = 1;
						break;
					}
					else if (map[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].small_time == 0 && temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].vis == 1
						&& temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].small_num > i) {//change

						sh[temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].small_num].now_d = 0;
						temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].small_time = k;
						temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].small_num = i;
						temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].vis = 1;

						temp[ni][nj].vis = 0;
						sh[i].i = ni + imap[sh[i].p[d][j]];
						sh[i].j = nj + jmap[sh[i].p[d][j]];
						sh[i].now_d = sh[i].p[d][j];
						
						f = 1;
						break;
					}
					else if (map[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].small_time == 0 && temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].vis == 1
						&& temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].small_num < i) {
						sh[i].now_d = 0;
						temp[ni][nj].vis = 0;
						f = 1;
						break;
					}
				}
			}
			if (f == 0) {
				for (int j = 1; j < 5; j++) {
					if (ni + imap[sh[i].p[d][j]] >= 0 && ni + imap[sh[i].p[d][j]] < n && nj + jmap[sh[i].p[d][j]] >= 0 && nj + jmap[sh[i].p[d][j]] < n) {
						if (temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].small_num == i) {
							temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].small_time = k;
							temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].small_num = i;
							temp[ni + imap[sh[i].p[d][j]]][nj + jmap[sh[i].p[d][j]]].vis = 1;
							sh[i].i = ni + imap[sh[i].p[d][j]];
							sh[i].j = nj + jmap[sh[i].p[d][j]];
							sh[i].now_d = sh[i].p[d][j];
							temp[ni][nj].vis = 0;
							break;
						}
					}
				}
			}
		}
	}
	init_map();
}

int main() {

	cin >> n >> m >> k;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			cin >> map[i][j].small_num;
			if (map[i][j].small_num !=0) {
				map[i][j].small_time = k;
				sh[map[i][j].small_num].i = i;
				sh[map[i][j].small_num].j = j;
			}

		}
	}

	for (int i = 1; i <= m;i++) {
		cin >> sh[i].now_d;
	}

	for (int i = 1; i <= m;i++) {
		for (int j = 1; j < 5;j++) {
			for (int k = 1; k < 5;k++) {
				cin >> sh[i].p[j][k];
			}
		}
	}
	while (ans<1001) {
		move_shark();
		remove();
		if (check() == true) { cout << ans; return 0; }
		ans++;
	}
	cout << -1;
	return 0;
}