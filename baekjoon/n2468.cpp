#include<iostream>

using namespace std;

int n;
int map[102][102];
int m = 0;
int ans = 0;
int v[102][102] = { 0,};
int answer = 0;

void search(int i,int j,int h) {
	v[i][j] = 1;
	if (i != 0 && map[i - 1][j] > h&&v[i-1][j]!=1) { search(i -1, j, h); }//À§
	if (i != n-1 && map[i + 1][j] > h&&v[i+1][j]!=1) { search(i + 1, j, h); }//¾Æ·¡
	if (j != 0 && map[i][j-1] > h&&v[i][j-1]!=1) { search(i , j-1, h); }//¿Þ
	if (j != n-1 && map[i][j+1] > h&&v[i][j+1]!=1) { search(i, j+1, h); }//¿À
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] > m) { m = map[i][j]; }
		}
	}



	for (int h = 0; h < m; h++) {
		ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > h && v[i][j] == 0) { search(i, j, h); ans++; }
			}
		}
		if (ans > answer) { answer = ans;}
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				v[a][b] = 0;
			}
		}
	}

	cout << answer;



	return 0;
}