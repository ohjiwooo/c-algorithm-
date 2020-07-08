#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int map[55][55];
int temp[55][55];
bool vis[55][55] = {false};
int num = 0;
vector <pair<int, int>> v2(15);
queue <pair<int, int>> qq;
int answer = 987654321;
int z = 0;
int imap[4] = { 1,0,-1,0 };
int jmap[4] = { 0,1,0,-1 };

void init_temp() {

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			temp[i][j] = map[i][j];
		}
	}
}

void init_vis() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[i][j] = false;
		}
	}
}
void ff() {
	int ans = 0;
	int tz = z;
	int size;
	while (qq.empty()!=true) {
		size = qq.size();
		for (int i = 0; i < size; i++) {
			int ni = qq.front().first;
			int nj = qq.front().second;
			qq.pop();
			temp[ni][nj] = 9;
			vis[ni][nj] = true;

			for (int i = 0; i < 4; i++) {
				if (ni + imap[i]>=0 && ni + imap[i] < n && nj + jmap[i]>=0 && nj + jmap[i] < n) {
					if (temp[ni + imap[i]][nj + jmap[i]] == 0 && vis[ni + imap[i]][nj + jmap[i]] != true) {//empty
						tz--;
						vis[ni + imap[i]][nj + jmap[i]] = true;
						qq.push(make_pair(ni + imap[i], nj + jmap[i]));
					} 
					else if (temp[ni + imap[i]][nj + jmap[i]] == 2 && vis[ni + imap[i]][nj + jmap[i]] != true) {//virus
						vis[ni + imap[i]][nj + jmap[i]] = true;
						qq.push(make_pair(ni + imap[i], nj + jmap[i]));
					}
				}
			}
		}
		ans++;
		if (tz == 0 && ans < answer) { answer = ans; return; }
	}
}


int main() {

	cin >> n >> m;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			cin >> map[i][j];
			if (map[i][j]==2) {
				v2[num].first = i;
				v2[num].second = j;
				num++;
			}
			if (map[i][j]==0) {
				z++;
			}
		}
	}
	if (z == 0) { cout << 0; return 0; }
	vector <int> v(num);

	for (int i = 0; i < num;i++) {
		v[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		v[i] = 1;
	}

	sort(v.begin(),v.end());
	
	do{

		for (int i = 0; i < num;i++) {
			if (v[i] == 1) {
				qq.push(make_pair(v2[i].first, v2[i]).second);
			}
		} 
		init_temp();
		init_vis();
		ff();
		

	}while (next_permutation(v.begin(),v.end()));

	if (answer == 987654321) { cout << -1; return 0; }
	cout << answer;

	return 0;

}