#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

int l, r, c;

char map[32][32][32];
bool vis[32][32][32];
string str;

int fmap[6] = { 0,0,0,0,1,-1 };
int imap[6] = { 0,1,0,-1,0,0 };//동 남 서 북 상 하
int jmap[6] = { 1,0,-1,0,0,0 };
int nowi = 0; int nowj = 0; int nowf = 0;



void bfs() {

	queue<pair<int, pair<int, int>>>q;
	int answer = 0;
	q.push(make_pair(nowf, make_pair(nowi, nowj)));
	while (q.empty() != true) {
		answer++;
		int ss = q.size();
		for (int t = 0; t < ss; t++) {
			int curf = q.front().first; int curi = q.front().second.first; int curj = q.front().second.second; q.pop();
			if (vis[curf][curi][curj] == true)continue;
			if (map[curf][curi][curj] == 'E') {
				cout << "Escaped in ";
				cout << answer - 1;
				cout<<" minute(s).\n"; return;
			}
			vis[curf][curi][curj] = true;

			for (int i = 0; i < 6; i++) {
				int newf = curf + fmap[i]; int newi = curi + imap[i]; int newj = curj + jmap[i];
				if (curf >= 0 && curf < l && newi >= 0 && newi < r && newj >= 0 && newj < c && map[newf][newi][newj] != '#'&& vis[newf][newi][newj] == false) {
					q.push(make_pair(newf, make_pair(newi, newj)));
				}
			}
		}
	}

	cout << "Trapped!\n"; return;

}
int main() {

	cin >> l >> r >> c;
	while (l !=0 && r!=0 && c!=0) {
		for (int i = 0; i < l;i++) {
			for (int j = 0; j < r;j++) {
				cin >> str;
				for (int k = 0; k < c;k++) {
					map[i][j][k] = str[k];
					if (map[i][j][k] == 'S') {
						nowf = i; nowi = j; nowj = k; //현재위치 저장 
					}
				}
			}
		} //입력끝
		memset(vis, false, sizeof(vis));
		bfs();
		
		cin >> l >> r >> c;
	}

	

	return 0;
}