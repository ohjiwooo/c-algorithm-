#include<iostream>

using namespace std;

int n, m;
int map[502][502];
int answer = 0;
int temp = 0;
int max(int a,int b,int c,int d,int e) {
	int ans;
	if (a >= b  ) { ans = a; }
	else { ans = b; }
	if (c > ans) { ans = c; }
	if (d > ans) { ans = d; }
	if (e > ans) { ans = e; }
	return ans;
}

int shape1(int i,int j) {
	int sum = 0;
	int ans = 0;

	if (i + 3 <= n - 1 ) {
		sum = (map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j]);
		ans = sum;
	}//세로
	if (j + 3 <= m - 1) {
		sum = (map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3]);
		if (ans < sum) { ans = sum; }
	}//가로
	return ans;
}//막대모양
int shape2(int i,int j) {
	int ans=0;
	if (i + 1 <= n - 1 && j + 1 <= m - 1){
		ans = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];
	}
	return ans;
}//네모모양

int shape3(int i,int j) {
	int sum = 0;
	int ans = 0;
	
	if (i + 1 <= n - 1 && j + 2 <= m - 1) {
		ans = map[i][j + 2] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
		sum = map[i][j] + map[i + 1][j] + map[i+1][j + 1] + map[i+1][j + 2];
		if (ans < sum) { ans = sum; }
		sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
		if (ans < sum) { ans = sum; }
		sum = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i][j + 2];
		if (ans < sum) { ans = sum; }
	} //가로
	
	if (i+2<=n-1 && j+1<=m-1) {
		sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
		if (ans < sum) { ans = sum; }
		sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1];
		if (ans < sum) { ans = sum; }
		sum = map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1] + map[i + 2][j];
		if (ans < sum) { ans = sum; }
		sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
		if (ans < sum) { ans = sum; }
	}//세로
	return ans;

}//ㄴ모양
int shape4(int i,int j) {
	int sum = 0;
	int ans = 0;

	if (i + 2 <= n - 1 && j + 1 <= m - 1) {
		ans = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
		sum = map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j] + map[i + 2][j];
		if (ans < sum) { ans = sum; }
	}
	if (i + 1 <= n - 1 && j + 2 <= m - 1) {
		sum = map[i][j + 1] + map[i][j + 2] + map[i + 1][j] + map[i + 1][j + 1];
		if (ans < sum) { ans = sum; }
		sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
		if (ans < sum) { ans = sum; }
	}
	return ans;

}//ㄹ모양

int shape5(int i,int j) {
	int sum = 0;
	int ans = 0;
	if (i + 1 <= n - 1 && j+2<=m-1) {
		ans = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
		sum = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
		if (ans < sum) { ans = sum; }
	}
	if (i + 2 <= n - 1 && j + 1<=m-1) {
		sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
		if (ans < sum) { ans = sum; }
		sum = map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
		if (ans < sum) { ans = sum; }
	}
	return ans;
}//ㅗ 모양

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp = max(shape1(i, j), shape2(i, j), shape3(i, j), shape4(i, j), shape5(i, j));
			if (answer < temp) { answer = temp; }
		}
	}
	
	cout << answer;

	return 0;
}

