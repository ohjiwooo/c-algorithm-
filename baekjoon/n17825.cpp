#include<iostream>
#include<vector>
using namespace std;

vector <pair<int, int>> v(4);
vector <int> arr(10);

int answer = 0;

int map[6][22] = {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,
               10,13,16,19,25,30,35,40,42,42,42,42,42,42,42,42,42,42,42,42,42,42,
               20,22,24,25,30,35,40,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,
		       25,30,35,40,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,
               30,28,27,26,25,30,35,40,42,42,42,42,42,42,42,42,42,42,42,42,42,42,
               40,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42};

int vis[6][22] = { 0, };

void dfs(int d,int ans) {//이동할 칸 index,현재 답

	if (d == 10) { 
		if (ans > answer) {
			answer = ans; 
		}
		return; 
	}
	
	for (int i = 0; i < 4; i++) {

		int ni = v[i].first;
		int nj = v[i].second;

		if (map[ni][nj] != 42) {
			if (nj + arr[d] > 21) {//도착
				vis[ni][nj]--;
				v[i].first = 0; v[i].second = 21;
				dfs(d + 1, ans);
				vis[ni][nj]++;
				v[i].first = ni; v[i].second = nj;
			}
			else {// 가능한 경우
				if (map[ni][nj + arr[d]] == 10) {
					if (vis[1][0] == 0) {
						vis[ni][nj]--;
						vis[1][0]++;
						v[i].first = 1; v[i].second = 0;
						dfs(d + 1, ans + map[ni][nj + arr[d]]);
						vis[1][0]--;
						vis[ni][nj]++;
						v[i].first = ni; v[i].second = nj;
					}
				}
				else if (map[ni][nj + arr[d]] == 20) {
					if (vis[2][0] == 0) {
						vis[ni][nj]--;
						vis[2][0]++;
						v[i].first = 2; v[i].second = 0;
						dfs(d + 1, ans + map[ni][nj + arr[d]]);
						vis[2][0]--;
						vis[ni][nj]++;
						v[i].first = ni; v[i].second = nj;
					}
				}
				else if (map[ni][nj + arr[d]] == 25) {
					if (vis[3][0] == 0) {
						vis[ni][nj]--;
						vis[3][0]++;
						v[i].first = 3; v[i].second = 0;
						dfs(d + 1, ans + map[ni][nj + arr[d]]);
						vis[3][0]--;
						vis[ni][nj]++;
						v[i].first = ni; v[i].second = nj;
					}
				}
				else if (ni == 0 && map[ni][nj + arr[d]] == 30) {
					if (vis[4][0] == 0) {
						vis[ni][nj]--;
						vis[4][0]++;
						v[i].first = 4; v[i].second = 0;
						dfs(d + 1, ans + map[ni][nj + arr[d]]);
						vis[4][0]--;
						vis[ni][nj]++;
						v[i].first = ni; v[i].second = nj;
					}
				}
				else if (map[ni][nj + arr[d]] == 40) {
					if (vis[5][0] == 0) {
						vis[ni][nj]--;
						vis[5][0]++;
						v[i].first = 5; v[i].second = 0;
						dfs(d + 1, ans + map[ni][nj + arr[d]]);
						vis[5][0]--;
						vis[ni][nj]++;
						v[i].first = ni; v[i].second = nj;
					}
				}
				else if (map[ni][nj + arr[d]] == 42) { //도착하면 전부다 map[0][21]로 이동시킴
					vis[ni][nj]--;
					v[i].first = 0; v[i].second = 21;
					dfs(d + 1, ans);
					vis[ni][nj]++;
					v[i].first = ni; v[i].second = nj;

				}
				else if (vis[ni][nj + arr[d]] == 0) {//자기 라인안에서 이동
					vis[ni][nj]--;
					vis[ni][nj + arr[d]]++;
					v[i].first = ni; v[i].second = nj + arr[d];
					dfs(d + 1, ans + map[ni][nj + arr[d]]);
					vis[ni][nj + arr[d]]--;
					vis[ni][nj]++;
					v[i].first = ni; v[i].second = nj;
				}
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