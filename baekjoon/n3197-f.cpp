#include<iostream>
#include<queue>
#include<vector>

using namespace std;

char map[1505][1505];
bool vis[1505][1505];
bool vis_ice[1505][1505];
queue <pair<int, int>> ice;


int day(int r, int c) {

	queue <pair<int, int>>temp;
	
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };

	while(ice.empty()!=true) {

		int ni = ice.front().first; int nj = ice.front().second;
		ice.pop();
	
		for (int j = 0; j < 4; j++) {
			if (ni + dy[j] >= 0 && ni + dy[j] < r && nj + dx[j] >= 0 && nj + dx[j] < c && map[ni + dy[j]][nj + dx[j]] != 'X') {
				temp.push(make_pair(ni, nj));break;
			}
		}
	}
	while (temp.empty() != true) {
		int a = temp.front().first; int b = temp.front().second;
		map[a][b] = '.';
		for (int j = 0; j < 4; j++) {
			if (a + dy[j] >= 0 && a + dy[j] < r && b + dx[j] >= 0 && b + dx[j] < c && map[a + dy[j]][b + dx[j]] == 'X' && vis_ice[a + dy[j]][b + dx[j]]==false) {
				ice.push(make_pair(a + dy[j], b + dx[j])); vis[a + dy[j]][b + dx[j]] = true;
			}
		}
		temp.pop();
	}
	return 0;
}

int ice_melt(int r, int c) {

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };
	int s = ice.size();
	for (int i = 0; i < s;i++) {
		int a = ice.front().first; int b = ice.front().second;
		map[a][b] = '.';
		for (int j = 0; j < 4; j++) {
			if (a + dy[j] >= 0 && a + dy[j] < r && b + dx[j] >= 0 && b + dx[j] < c && map[a + dy[j]][b + dx[j]] == 'X' && vis_ice[a + dy[j]][b + dx[j]] == false) {
				ice.push(make_pair(a + dy[j], b + dx[j])); vis[a + dy[j]][b + dx[j]] = true;
			}
		}
		ice.pop();
	}
	return 0;
}

int meet(int r, int c, vector<pair<int, int>> swan) {

	int dy[4] = { 0,1,0,-1 };
	int dx[4] = { -1,0,1,0 };
	int si = swan[0].first;
	int sj = swan[0].second;
	int ei = swan[1].first;
	int ej = swan[1].second;

	queue <pair<int, int>> q;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			vis[i][j] = false;
		}
	}


	q.push(make_pair(si, sj));
	vis[si][sj] = true;

	while (q.empty() != true) {
		int ni = q.front().first;
		int nj = q.front().second;
		q.pop();

		if (ni == ei && nj == ej) {
			return 1;
		}

		for (int i = 0; i < 4; i++) {
			if (ni + dx[i] >= 0 && ni + dx[i] < r && nj + dy[i] >= 0 && nj + dy[i] < c && map[ni + dx[i]][nj + dy[i]] !='X' && vis[ni + dx[i]][nj + dy[i]] == false) {
				q.push(make_pair(ni + dx[i], nj + dy[i]));
				vis[ni + dx[i]][nj + dy[i]] = true;
			}
		}
	}

	return 0;
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int r = 0; int c = 0; int a = 0; int n = 0;
	cin >> r >> c;
	vector <pair<int, int>> swan;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
				swan.push_back(make_pair(i, j));
			}
			if (map[i][j] == 'X') {
				ice.push(make_pair(i, j));
			}
		}
	}

	day(r, c);
	int answer = 1;
	while (1) {
		if (meet(r, c, swan) == 1) {
			cout << answer;
			break;
		}
		else {
			answer++;
			ice_melt(r, c);
		}
	}


	return 0;
}