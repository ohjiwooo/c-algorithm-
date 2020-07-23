#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int map[25][25];
int ans = 9877654321;

int m(int a,int b) {

	if (a > b) { return a - b; }
	else { return b - a; }

}


int main() {

	cin >> n;

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	vector <int> v(n);
	vector<int> v2(n + 1);
	vector<int> team1(n);
	vector <int>team2(n);
	int t1 = 0;
	int t2 = 0;
	int team1_sum = 0;
	int team2_sum = 0;

	for (int i = 0; i < n; i++) {
		v[i] = 1;
	}
	for (int i = 0; i < n / 2;i++) {
		v[i] = 0;
	}
	for (int i = 0; i <n; i++) {
		v2[i] = i+1;
	}

	do {
		t1 = 0; t2 = 0; team1_sum = 0; team2_sum = 0;

		for (int i = 0; i < n;i++) {
			if (v[i]==0) {
				team1[t1++] = v2[i];
			}
			else {
				team2[t2++] = v2[i];
			}
		}
		
		for (int i = 0; i < t1 ; i++) {
			for (int j = 0; j < t1 ; j++) {
				team1_sum += map[team1[i]][team1[j]];
			}
		}
		for (int i = 0; i < t2; i++) {
			for (int j = 0; j < t2; j++) {
				team2_sum += map[team2[i]][team2[j]];
			}
		}

		int temp = m(team1_sum, team2_sum);
		if (temp < ans) {
			ans = temp;
		}
	
	} while (next_permutation(v.begin(),v.end()));
	

	cout << ans;
	return 0;
}