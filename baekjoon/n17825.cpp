#include<iostream>
#include<vector>
using namespace std;

vector <pair<int, int>> v(4);
vector <int> arr(10);

int answer = 0;
int f = 0;
int map[6][22] = {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,
               10,13,16,19,25,30,35,40,42,42,42,42,42,42,42,42,42,42,42,42,42,42,
               20,22,24,25,30,35,40,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,
		       25,30,35,40,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,
               30,28,27,26,25,30,35,40,42,42,42,42,42,42,42,42,42,42,42,42,42,42,
               40,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42};

int vis[6][22] = { 0, };

void dfs(int d,int ans) {//이동할 칸 index,현재 답,맵에서위치

	
	if (d==10) {
		if (answer < ans) { answer = ans; 
		}
		return;
	}


	for (int i = 0; i < 4; i++) {

		int ni = v[i].first;
		int nj = v[i].second;
		int x;
		f = 0;
		if (map[ni][nj] != 42) {
			if (nj + arr[d] > 21) {
				x = 42;
			}
			else {
				x = map[ni][nj + arr[d]];
			}

			if (ni == 1 || ni == 2) {
				if (x < 25 && vis[ni][nj + arr[d]] == 0) {
					v[i].second = nj + arr[d]; f = 1;
				}
				else if (x == 25 && vis[3][0] == 0) {
					v[i].first = 3; v[i].second = 0; f = 1;
				}
				else if (x == 30 && vis[3][1] == 0) {
					v[i].first = 3; v[i].second = 1; f = 1;
				}
				else if (x == 35 && vis[3][2] == 0) {
					v[i].first = 3; v[i].second = 2; f = 1;
				}
				else if (x == 40 && vis[5][0] == 0) {
					v[i].first = 5; v[i].second = 0; f = 1;
				}
				else if (x == 42) {
					v[i].first = 0; v[i].second = 21;
					x = 0; f = 1;
				}
			}
			else if (ni == 3) {
				if (x < 40 && vis[ni][nj + arr[d]] == 0) {
					v[i].second = nj + arr[d]; f = 1;
				}
				else if (x == 40&& vis[5][0]==0) {
					v[i].first = 5; v[i].second = 0;
					f = 1;
				}
				else if (x == 42) {
					v[i].first = 0; v[i].second = 21;
					x = 0; f = 1;
				}
			}
			else if (ni == 4) {
				if ((x ==28 || x==27 ||x== 26)&& vis[ni][nj + arr[d]] == 0) {
					v[i].second = nj + arr[d]; f = 1;
				}
				else if (x == 25 && vis[3][0] == 0) {
					v[i].first = 3; v[i].second = 0; f = 1;
				}
				else if (x == 30 && vis[3][1] == 0) {
					v[i].first = 3; v[i].second = 1; f = 1;
				}
				else if (x == 35 && vis[3][2] == 0) {
					v[i].first = 3; v[i].second = 2; f = 1;
				}
				else if (x == 40 && vis[5][0] == 0) {
					v[i].first = 5; v[i].second = 0; f = 1;
				}
				else if (x == 42) {
					v[i].first = 0; v[i].second = 21;
					x = 0; f = 1;
				}
			}
			else if (ni == 5) {
				if (x == 42) {
					v[i].first = 0; v[i].second = 21;
					x = 0; f = 1;
				}
			}
			else if (ni == 0) {
				if (x == 10 && vis[1][0] == 0) {
					v[i].first = 1; v[i].second = 0; f = 1;
				}
				else if (x == 20 && vis[2][0] == 0) {
					v[i].first = 2; v[i].second = 0; f = 1;
				}
				else if (x == 30 && vis[4][0] == 0) {
					v[i].first = 4; v[i].second = 0; f = 1;
				}
				else if (x == 40 && vis[5][0] == 0) {
					v[i].first = 5; v[i].second = 0; f = 1;
				}
				else if (x == 42) {
					v[i].first = 0; v[i].second = 21;
					x = 0; f = 1;
				}
				else if (x != 10 && x != 20 && x != 30 && x != 40 && vis[ni][nj + arr[d]] == 0) {
					v[i].second = nj + arr[d]; f = 1;
				}
			}
			if (f==1) {
				vis[ni][nj]--;
				vis[v[i].first][v[i].second]++;
				dfs(d + 1, ans + x);
				vis[ni][nj]++;
				vis[v[i].first][v[i].second]--;
				v[i].first = ni;
				v[i].second = nj;
				f = 0;
			}
		}
	}
	return;

}



int main() {

	
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	v.push_back(make_pair(0,0));
	v.push_back(make_pair(0, 0));
	v.push_back(make_pair(0, 0));
	v.push_back(make_pair(0, 0));

	dfs(0,0);

	cout << answer;

}