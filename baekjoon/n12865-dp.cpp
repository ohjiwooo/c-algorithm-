#include<iostream>
#include<algorithm>

using namespace std;

int arr[102][2] = { 0, };
int map[102][100002] = { 0, };

int dp(int n,int k,int arr[102][2],int map[102][100002]) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j-arr[i][0] >= 0) {
				map[i][j] = max(map[i - 1][j], map[i - 1][j - arr[i][0]] + arr[i][1]);
			}
			else {
				map[i][j] = map[i - 1][j];
			}
		}
	}

	return map[n][k];

}

int main() {

	int n = 0;
	int k = 0;

	cin >> n >> k;

	
	int a, b;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		arr[i][0] = a;
		arr[i][1] = b;
	}

	cout << dp(n, k, arr, map);


}