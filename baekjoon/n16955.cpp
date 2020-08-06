#include<iostream>
#include<queue>

using namespace std;
char map[12][12];
queue <pair<int, int>> qq;
int imap[8] = {-1,-1,0,1,1, 1, 0,-1};
int jmap[8] = { 0, 1,1,1,0,-1,-1,-1};

bool f(int i,int j,int k,int n) {
	if (n == 5) { return true; }
	
	else if (i + imap[k] >= 0 && i + imap[k] < 10 && j + jmap[k] >= 0 && j + jmap[k] < 10 && map[i + imap[k]][j + jmap[k]] == 'X') {
		if (f(i + imap[k], j + jmap[k], k, n + 1) == true) { return true; }
	}
	return false;
}

bool ans() {
	

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j]=='X') {
				for (int k = 0; k < 8; k++) {
					if (i + imap[k]>=0 && i + imap[k]<10 && j + jmap[k]>=0 && j + jmap[k]<10 &&map[i + imap[k]][j + jmap[k]] == 'X') {
						if (f(i + imap[k], j + jmap[k], k, 2) == true) { return true; }
					}
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
		if (ans() == true) { cout << 1; return 0; }
		map[i][j] = '.';
	}

	cout << 0;
	return 0;

}