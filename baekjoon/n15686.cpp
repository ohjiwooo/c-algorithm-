#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int map[55][55];
int nn = 0;
int hh = 0;

int d(int i,int j,int i2,int j2) {
	int ans = 0;

	if (i>i2) {
		ans += i - i2;
	}
	else { ans += i2 - i; }

	if (j>j2) {
		ans += j - j2;
	}
	else { ans += j2 - j; }

	return ans;
}

int main() {

	cin >> n >> m;
	vector <pair<int, int>>v(15);
	vector <pair<int, int>>h(120);

	int answer = 0;

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			cin >> map[i][j];
			if (map[i][j]==2) {
				v[nn].first = i;
				v[nn++].second = j;
			}
			else if (map[i][j]==1) {
				h[hh].first = i;
				h[hh++].second = j;
			}
		}
	}
	
	vector <int>v2(nn);
	vector<pair<int, int>> temp(m);

	for (int i = 0; i < nn;i++) {
		v2[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		v2[i] = 0;
	}

	int j;
	int ans = 987654321;
	do {
		j = 0;
		for (int i = 0; i < nn;i++) {
			if (v2[i]==0) {
				temp[j].first = v[i].first;
				temp[j++].second = v[i].second;
			}
		}

		int t;
		int a = 0;
		for (int k = 0; k < hh; k++) {
			t = 987654321;
			for (int k2 = 0; k2 < m; k2++) {
				a = d(h[k].first, h[k].second, temp[k2].first, temp[k2].second);
				if (a < t) {
					t = a;
				}
			}answer += t;
		}
		if (ans > answer) { ans = answer; }
		answer = 0;
	} while (next_permutation(v2.begin(),v2.end()));

	cout << ans;
	return 0;
}