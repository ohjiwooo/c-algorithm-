#include <string>
#include <vector>
#include<iostream>
using namespace std;

bool vis[100][100];
int n, m;
int map1[100][100];
int map2[100][100];


vector<vector<int>> turn(vector<vector<int>> key, int map2[100][100]) {

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			map2[i][j] = 0;
		}
	}

	int k = m - 1;
	int ans[25][25];
	for (int i = 0; i < m; i++) { //turn
		for (int j = 0; j < m; j++) {
			ans[j][k] = key[i][j];
		}
		k--;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			key[i][j] = ans[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			map2[i][j] = key[i][j];
		}
	}
	return key;
}

void init() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			vis[i][j] = false;
		}
	}
}
void init2() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			map2[i][j] = 0;
		}
	}

}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;

	int temp[100][100] = { 0 };
	n = lock.size();
	m = key.size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map1[i + m][j + m] = lock[i][j];
		}
	}//가운데에 자물쇠 복사

	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (lock[i][j] == 0) { num++; }
		}
	}//홈의갯수
	if (num == 0) { return true; }
	int t = 0;
	while (t < 4) {

		key = turn(key, map2);

		int d = m - 1;//현재밑
		int k = 0;//내린칸수

		while (d < m * 2 + n - 2) {
			d++;
			k++;
			init2();

			for (int i = 0; i < m; i++) { //밑으로 내리기
				for (int j = 0; j < m; j++) {
					map2[i + k][j] = key[i][j];
				}
			}

			int l = m - 1;//현재왼쪽세로

			while (l < m * 2 + n - 2) {
				l++;
				init();
				for (int i = d - m + 1; i <= d; i++) { //옆으로 당기기
					for (int j = l; j > l - m; j--) {
						map2[i][j] = map2[i][j - 1];
						vis[i][j] = true;
					}
				}


				int h = num;
				answer = false;
				for (int i = m; i < m + n; i++) {
					for (int j = m; j < n + m; j++) {
						if (vis[i][j] == true) {//여기만 확인
							if (map1[i][j] == 1 && map2[i][j] == 1) {
								answer = false; break;
							}
							else if (map1[i][j] == 0 && map2[i][j] == 1) {
								answer = true; h--;
							}
							else if (map1[i][j] == 1 && map2[i][j] == 0) {
								answer = true;
							}
							else if (map1[i][j] == 0 && map2[i][j] == 0) {
								answer = false; break;
							}
						}
					}
				}
				if (h == 0 && answer == true) { return answer; }

			}
		}
		t++;
	}
	answer = false;
	return answer;
}