#include<iostream>
#include<queue>

using namespace std;

typedef struct s {

	int i;
	int j;
	int d; // 0-up 1-right 2-down 3-left
	int c = 0;
}s;
int n, m; //√÷¥Î10
char map[15][15];
int ri, rj;
int bi, bj;
int hi, hj;
queue <s>qq;

bool up(char c) {

	if (c=='r') {
		while (ri>0) {
			ri--;
			if (map[ri][rj] == 'O') {
				return true;
			}
			else if (map[ri][ri]=='#') {
				return false;
			}
		}
	}
	else {
		while (bi > 0) {
			bi--;
			if (map[bi][bj] == 'O') {
				return true;
			}
			else if (map[bi][bi] == '#') {
				return false;
			}
		}
	}

}

bool right(char c) {

	if (c == 'r') {
		while (rj < m) {
			rj--;
			if (map[ri][rj] == 'O') {
				return true;
			}
			else if (map[ri][ri] == '#') {
				return false;
			}
		}
	}
	else {
		while (bj <m) {
			bj--;
			if (map[bi][bj] == 'O') {
				return true;
			}
			else if (map[bi][bi] == '#') {
				return false;
			}
		}
	}

}

bool down(char c) {

	if (c == 'r') {
		while (ri < n) {
			ri++;
			if (map[ri][rj] == 'O') {
				return true;
			}
			else if (map[ri][ri] == '#') {
				return false;
			}
		}
	}
	else {
		while (bi < n) {
			bi++;
			if (map[bi][bj] == 'O') {
				return true;
			}
			else if (map[bi][bi] == '#') {
				return false;
			}
		}
	}

}

bool left(char c) {

	if (c == 'r') {
		while (rj > 0) {
			rj--;
			if (map[ri][rj] == 'O') {
				return true;
			}
			else if (map[ri][ri] == '#') {
				return false;
			}
		}
	}
	else {
		while (bj > 0) {
			bj--;
			if (map[bi][bj] == 'O') {
				return true;
			}
			else if (map[bi][bi] == '#') {
				return false;
			}
		}
	}

}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cin >> map[i][j];
			if (map[i][j] == 'O') {
				hi = i; hj = j;
			}
			else if (map[i][j]=='R') {
				ri = i; rj = j;
			}
			else if (map[i][j]=='B') {
				bi = i; bj = j;
			}
		}
	}

	do {
		if (up('b') != true) {
			qq.push({})
		}
	
	
	} while (qq.empty() != true);
	
	

	return 0;
}