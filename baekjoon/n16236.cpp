#include<iostream>
#include<queue>

using namespace std;

int n;
int eat = 0;
bool vis[25][25] = { false, };
int map[25][25];
int b = 2;//size of baby shark
int imap[4] = { 0,1,0,-1 };
int jmap[4] = { 1,0,-1,0 };
queue <pair<int, int>>qq;
int t = 0;
int temp_t = 0;
queue<pair<int, int>>ans;
int flag = 0;
int fi1, fj1;



void init() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[i][j] = false;
		}
	}
}
void resize() {

	if (eat + 1 == b && b + 1 < 8) {
		b++;
		eat = 0;
	}
	else if (b==8) {
		eat = 0;
	}
	else { eat++; }
}

void init2() {
	while (qq.empty() != true) {
		qq.pop();
	}
}

void ff(int fi, int fj) {

	qq.push(make_pair(fi, fj));
	vis[fi][fj] = true;

	while (qq.empty() != true) {

		int size = qq.size();
		temp_t++;
		flag = 0;
		for (int j = 0; j < size; j++) {
			int ni = qq.front().first;
			int nj = qq.front().second;
			qq.pop();
			for (int i = 0; i < 4; i++) {
				if (ni + imap[i] >= 0 && ni + imap[i] < n && nj + jmap[i] >= 0 && nj + jmap[i] < n &&vis[ni + imap[i]][nj + jmap[i]] != true) {
					if (flag != 1 && (map[ni + imap[i]][nj + jmap[i]] == 0 || map[ni + imap[i]][nj + jmap[i]] == b)) { //move
						qq.push(make_pair(ni + imap[i], nj + jmap[i]));
						vis[ni + imap[i]][nj + jmap[i]] = true;
					}
					else if (map[ni + imap[i]][nj + jmap[i]] < b && map[ni + imap[i]][nj + jmap[i]]>0) {
						ans.push(make_pair(ni + imap[i], nj + jmap[i]));
						vis[ni + imap[i]][nj + jmap[i]] = true;
						flag = 1;
					}
				}
			}
		}
		if (flag == 1) {
			int ans_i = 25;
			int ans_j = 25;

			while (ans.empty() != true) {

				int temp_i = ans.front().first;
				int temp_j = ans.front().second;
				ans.pop();

				if (temp_i < ans_i) {
					ans_i = temp_i;
					ans_j = temp_j;
				}
				else if (temp_i == ans_i && temp_j < ans_j) {
					ans_i = temp_i;
					ans_j = temp_j;
				}

			}//finding answer
			resize();
			t += temp_t;
			temp_t = 0;
			map[ans_i][ans_j] = 0;
			init();
			init2();
			qq.push(make_pair(ans_i, ans_j));
		}
	}
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				fi1 = i; fj1 = j;
			}
		}
	}
	vis[fi1][fj1] = true;
	map[fi1][fj1] = 0;
	ff(fi1, fj1);

	cout << t;
	return 0;

}
