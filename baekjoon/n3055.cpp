#include<iostream>
#include<queue>
using namespace std;



int r, c;
char map[52][52];
queue <pair<int,pair<int, int>>>q;
int answer = 0;
bool vis[52][52];
vector <pair<int, int>>v;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void p() {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j] << " ";
		}cout << "\n";

	}
}

void water() {

	int size = v.size();
	for (int i = 0; i < size; i++) {
		int ni = v[i].first; int nj = v[i].second;
		for (int k = 0; k < 4; k++) {
			if (ni + dy[k] < 0 || ni + dy[k]>=r || nj + dx[k] <0 || nj + dx[k]>=c)continue;
			if (map[ni + dy[k]][nj + dx[k]] != '.') continue;
			map[ni + dy[k]][nj + dx[k]] = '*';
			v.push_back(make_pair(ni + dy[k], nj + dx[k]));
		}
	}
}
int bfs() {

	while (q.empty()!=true) {
		int size = q.size();
		water();

		while (size--) {

			int now_i = q.front().second.first; int now_j = q.front().second.second; int now = q.front().first; q.pop(); 

			if (map[now_i][now_j] == 'D') {
				answer = now;
				return 0;
			}

			for (int k = 0; k < 4; k++) {
				if (now_i + dy[k] < 0 || now_i + dy[k]>=r || now_j + dx[k] <0 || now_j + dx[k]>=c)continue;
				int new_i = now_i + dy[k]; int new_j = now_j + dx[k];

				if (vis[new_i][new_j] == true || map[new_i][new_j] == '*' || map[new_i][new_j] == 'X')continue;
				q.push(make_pair(now + 1, make_pair(new_i, new_j))); vis[new_i][new_j] = true;

			}
		}
	}
	return 0;

}


int main() {


	cin >> r >> c;

	for (int i = 0; i < r;i++) {
		for (int j= 0; j < c;j++) {
			cin >> map[i][j];
			if (map[i][j]=='*') {
				v.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 'S') {
				q.push(make_pair(0, make_pair(i, j))); map[i][j] = '.';
			}
		}
	}
	

	bfs();
	if (answer == 0)cout << "KAKTUS";
	else { cout << answer; }
	return 0;
}