#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


pair<int,int> map[1002][1002];

int main() {

	string s;
	int n, m,a;
	cin >> n >> m;
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		cin >>s;
		for (int j = 0; j < m;j++) {
			a = s[j] - '0';

			if (a == 0) { map[i][j].first = 0; map[i][j].second = 0; }
			else {
				 map[i][j].first = min(map[i - 1][j].first,map[i-1][j-1].first)+1;   //대각선 위 고려 안해서 틀림
				 map[i][j].second = min(map[i][j - 1].second,map[i-1][j-1].second)+1;
			}
			int tmp = min(map[i][j].first, map[i][j].second);
			tmp = (tmp*tmp);
			answer = max(answer, tmp);
		}
	}
	cout << answer;
	return 0;
}