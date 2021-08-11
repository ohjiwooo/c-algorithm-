#include<iostream>

using namespace std;


int h, w, n;
int map[1004][1004];
int dp[1004][1004];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w >> n;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}
	dp[0][0] = n-1;//n번 방문함

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			dp[i + 1][j] += dp[i][j] / 2;
			dp[i][j + 1] += dp[i][j] / 2;

			if (dp[i][j] % 2 != 0) { //홀수
				if (map[i][j] == 1) dp[i][j + 1]++; //오른쪽으로 한번더
				else { dp[i + 1][j]++; } //아래로 한번더
				if (map[i][j] == 1)map[i][j] = 0;
				else { map[i][j] = 1; }
			}
		}
	}
	
	int i = 0; int j = 0;
	while (1) {

		if (i == h || j == w)break;
		if (map[i][j] == 1)j++;
		else { i++; }
	}
	cout << i + 1 << " " << j + 1;
}