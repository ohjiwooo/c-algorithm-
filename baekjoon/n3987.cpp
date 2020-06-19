#include<iostream>

using namespace std;

int n, m;
int map[505][505];
int pr, pc;
int ans = 0;
char answer;

void up(int i2, int j2) {
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			if (map[i2 - 1][j] == '.') {
				ans++;
			}
			else if (map[i2 - 1][j] == 'C') {
				return;
			}
			else if (map[i2 - 1][j] == '/') {
				return;
			}
		}
	}
}

void right(int i2, int j2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

		}
	}
}

void down(int i2, int j2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

		}
	}
}

void left(int i2, int j2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	cin >> pr >> pc;


	return 0;
}