#include<iostream>
#include<vector>
using namespace std;


int arr[103];
long long dp[22][103];
int n;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> arr[i];
	}
	dp[arr[0]][0] = 1;
	for (int i = 1; i < n-1;i++) {
		for (int j = 0; j <= 20;j++) {
			int value = j + arr[i];
			if (dp[j][i-1]!=0 && value>=0 && value<=20) {
				dp[value][i] += dp[j][i - 1];
			}
			value = j - arr[i];
			if (dp[j][i-1] != 0 && value >= 0 && value <= 20) {
				dp[value][i]+=dp[j][i-1];
			}
		}
	}
	

	cout << dp[arr[n-1]][n-2];
	return 0;
}