#include<iostream>
#include<queue>
using namespace std;


typedef struct s {
	char b;
	int t = 0;
}s;
int r, c, n;
s map[250][250];
int time = 1;
int imap[4] = { -1,0,1,0 };
int jmap[4] = { 0,1,0,-1 };

void f1() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j].b == 'O') {
				map[i][j].t--;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j].b=='.') {
				map[i][j].b = 'O';
				map[i][j].t = 3;
			}
		}
	}
	
}

void f2() {

	queue <pair<int, int>>qq;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j].b == 'O') {
				map[i][j].t--;
				if (map[i][j].t == 0) { qq.push(make_pair(i,j)); }
			}
		}
	}

	while (qq.empty()!=true) {
		int i = qq.front().first;
		int j = qq.front().second;
		qq.pop();
		map[i][j].b = '.';
		map[i][j].t = 0;

		for (int k = 0; k < 4;k++) {
			if (i+imap[k] >=0 && i+imap[k]<r && j+jmap[k] >=0 && j+jmap[k] <c ) {
				map[i + imap[k]][j + jmap[k]].b = '.';
				map[i + imap[k]][j + jmap[k]].t = 0;
			}
		}
	}


}

int main() {

	cin >> r >> c >> n;
	for (int i = 0; i < r;i++) {
		for (int j = 0; j < c;j++) {
			cin >> map[i][j].b;
			if (map[i][j].b == 'O') { map[i][j].t = 2; }
		}
	}

	int f = 1;

	while (time < n) {
		time++;
		if (f>0) { f1(); }
		else {f2();}
		f = -f;
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j].b;
		}cout << "\n";
	}
	return 0;
}