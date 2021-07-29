#include<iostream>
#include<algorithm>

using namespace std;

int dp[205][205]; // i~j까지 맞추는데 비용
int arr[205];
int divide(int s,int e) {

	if (s == e)return 0; // 자기자신이면 return 0
	int &n = dp[s][e];
	if (n != -1) { return n; } //이미 dp[s][e]를 알고있음 -> return n

	n = 987654321;//최댓값으로 두고 갱신시작

	int l,r;
	for (int i = s; i < e;i++) {

		l = divide(s,i);
		r = divide(i + 1, e);

		if (arr[s] == arr[i + 1]) {//양쪽 색이 같은경우
			n = min(n, l + r);
		}
		else {
			n = min(n, l + r + 1);
		}
	}
	return n;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i =0; i < n;i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			dp[i][j] = -1;
		}
	}
	
	cout << divide(0, n - 1);

}


