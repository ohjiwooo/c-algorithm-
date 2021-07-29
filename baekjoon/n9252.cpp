#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int dp[4004][4004];

vector<char>answer;
int main() {

	string s1, s2;

	cin >> s1 >> s2;


	for (int i = 0; i < s1.size();i++) {
	
		for (int j = 0; j < s2.size();j++) {

			if (s1[i] == s2[j]) { //두 문자가 같음
				dp[i + 1][j] = dp[i][j - 1] + 1;
			}
			else {//다름
				dp[i + 1][j] = max(dp[i][j], dp[i][j - 1]);
			}
		}
	}

	int n = s1.size(); int m = s2.size();
	while (n!=0  && m!=0) {

		if (s1[n-1]==s2[m-1]) {
			answer.push_back(s1[n-1]);
			n--; m--;
		}
		else if (dp[n][m]==dp[n-1][m]) {
			n--;
		}
		else if (dp[n][m]==dp[n][m-1]) {
			m--;
		}
	}


	cout << dp[s1.size()][s2.size() - 1]<<"\n";
	for (int i = 0; i < answer.size();i++) {
		cout << answer[i];
	}


}