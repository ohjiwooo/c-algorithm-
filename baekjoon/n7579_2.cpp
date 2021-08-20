#include<iostream>
#include<algorithm>
using namespace std;

int n, m;//n개 어플 앞으로 m필요
int use[105];
int cost[105];
int dp[105][10003];

int main() {

	cin >> n >> m;
	int num = 0;
	for (int i = 1; i <= n;i++) {
		cin >> use[i];
	}
	for (int i = 1; i <= n;i++) {
		cin >> cost[i];
		num += cost[i];
	}

	//m바이트를 확보하기위한 최저 cost
	
	for (int i = 1; i <= n;i++) { //i까지 탐색했을때 cost j 를 사용하여 얻을수있는 최대메모리
		for (int j = 1; j <= num;j++) {
			if (j-cost[i] >= 0) { //cost가 j보다 작으므로 끌수있음
				dp[i][j] = max(dp[i-1][j - cost[i]] + use[i], dp[i-1][j]);
			}
			else {
				dp[i][j] =dp[i - 1][j];
			}
			if (dp[i][j]>=m) {
				num = min(num, j);
			}
		}
	}
	cout << num;
}