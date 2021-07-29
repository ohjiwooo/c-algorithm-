#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int dp[4004][4004];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	int answer = 0;
	for (int i = 1; i <= s1.size();i++) {
		for (int j = 0; j < s2.size();j++) {
			if (s1[i-1]==s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				answer = max(answer, dp[i][j]);
			}
		}
	
	}
	cout << answer;
}