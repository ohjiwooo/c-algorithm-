#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int gcd(int a, int b) {
	
	if (a==0) {
		return b;
	}
	else if (b==0) {
		return a;
	}
	int answer = a % b;

	if (answer==0) {
		return b;
	}
	else {
		return gcd(b, answer);
	}


}
int com(pair<int,int>a,pair<int,int>b) {
	return a.first > b.first;

}


int v[1000005];
int l[1000005]; //완쪽부터 gcd
int r[1000005]; //오른쪽부터 gcd
int a, b;

int main() {


	int n;
	cin >> n;

	for (int i = 1; i <= n;i++) {
		cin >> v[i];
	}
	l[1] = v[1];
	for (int i = 2; i <= n; i++) {
		if (l[i-1] <= v[i]) {
			a = v[i]; b = l[i-1];
		}
		else {
			b = v[i]; a = l[i-1];
		}
		l[i]=(gcd(a, b));
	}
	r[n] = v[n];
	
	for (int i = n-1; i > 0; i--) {
		if (v[i] <= r[i+1]) {
			a = r[i+1]; b = v[i];
		}
		else {
			b = r[i+1]; a = v[i];
		}
		r[i]=(gcd(a, b));
		
	}
	vector<pair<int, int>>answer;


	for (int i = 1; i <= n; i++) {
		int a = gcd(l[i-1],r[i+1]);
		answer.push_back(make_pair(a, v[i]));//i를 빼면 a
	}
	sort(answer.begin(), answer.end(),com);
	if (answer[0].first==answer[n-1].first) {
		cout << -1;
	}
	else {
		cout << answer[0].first << " " << answer[0].second;
	}

	return 0;
}
