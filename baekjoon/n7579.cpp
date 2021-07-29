#include<iostream>
#include<algorithm>
using namespace std;

pair<int, int> arr[105]; //사용중 메모리, 재시작 비용
int dp[105][10005]; //cost의 최대가 100*100
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int answer = 0;
	for (int i = 1; i <= n;i++) {
		cin >> arr[i].first;
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].second;
		answer += arr[i].second;
	}
	
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j < answer+1;j++) { // i번째 앱까지 탐색했을때 j비용을 소모하여 얻을수있는 최대 메모리
			if (j - arr[i].second >= 0) {  //끌수있음
				dp[i][j] = max(dp[i - 1][j], arr[i].first + dp[i - 1][j - arr[i].second]);
			}
			else { //끌 수 없음
				dp[i][j] = dp[i - 1][j];
			}
			if (dp[i][j] >= m)answer = min(answer, j);
		}
	}

	cout << answer;
	return 0;
}