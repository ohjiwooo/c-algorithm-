#include<iostream>
#include<queue>

using namespace std;
char map[12][12];
queue <pair<int, int>> qq;
int imap[8] = {-1,-1,0,1,1, 1, 0,-1};
int jmap[8] = { 0, 1,1,1,0,-1,-1,-1};

bool bfs(int a,int b) {

	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	int n = 0;
	bool vis[12][12] = { false };
	vis[a][b] = true;
	while (q.empty()!=true) {
		int size = q.size();
		n++;
		if (n == 5) { return true; }
		for (int i = 0; i < size; i++) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();

			for (int j = 0; j < 8; j++) {
				if (a + imap[j] >= 0 && a + imap[j] < 10 && b + jmap[j] >= 0 && b + jmap[j] < 10 && map[a + imap[j]][b + jmap[j]] == 'X' && vis[a + imap[j]][b + jmap[j]] != true) {
					q.push(make_pair(a + imap[j], b + jmap[j]));
					vis[a + imap[j]][b + jmap[j]] = true;
				}
			}
		}
	}
	return false;
}

bool ans() {
	

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j]=='X') {
				if (bfs(i, j)==true) {
					return true;
				}
			}
		}
	}
	return false;
}
int main() {

	for (int i = 0; i < 10;i++) {
		for (int j = 0; j < 10;j++) {
			cin >> map[i][j];
			if (map[i][j]=='.') {
				qq.push(make_pair(i,j));
			}
		}
	}//.ºóÄ­ x±¸»ç°ú o Å¥ºê·¯¹ö

	while (qq.empty()!=true) {
		int i = qq.front().first;
		int j = qq.front().second;
		qq.pop();

		map[i][j] = 'X';
		if (ans() == true) { cout << 1; cout << "\n" << i << " " << j; return 0; }
		map[i][j] = '.';
	}

	cout << 0;
	return 0;

}