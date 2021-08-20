#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll n;
ll arr[2003];
ll dp[2003][2003];


int go_r(int a) {

	return (a + 1) % n;
}
int go_l(int a) {
	a = (a - 1) % n;
	if (a < 0)return n - 1;
	return a;
}

ll func(int s, int e, int t) { //1이 주인공

	if (s==e) {
		if (t == 1)return arr[s];
		else {
			return 0;
		}
	}
	ll &res = dp[s][e];
	if (dp[s][e] != -1) return res;

	if (t == 0) {
		if (arr[s] > arr[e]) { res=func(go_l(s), e, 1); }
		else {
			res=func(s, go_r(e), 1);
		}
	}
	else {
		res = max(func(go_l(s), e, 0)+arr[s], func(s, go_r(e), 0)+arr[e]);
		
	}
	return res;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> arr[i];
	}
	ll answer = 0;
	
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n;i++) {
		
		answer = max(answer, func(i, (i + 1) % n, 1));
	}

	cout << answer;
	return 0;
}