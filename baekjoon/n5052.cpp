#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;



int solve(vector<string> v,int n) {

	sort(v.begin(), v.end());
	for (int i = 0; i < n-1; i++) {
		
		if (v[i+1].substr(0,v[i].length())==v[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {

	int t = 0;
	int n = 0;
	cin >> t;

	while (t--) {
		int a = 0;
		vector<string> v;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a;
			v.push_back(to_string(a));
		}
		if (solve(v, n)==0) {
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}
	}
	return 0;
}