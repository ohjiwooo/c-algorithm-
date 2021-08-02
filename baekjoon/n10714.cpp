#include<iostream>
#include<cstring>
#include<algorithm>

typedef long long ll;
using namespace std;

ll arr[2003];
ll dp[2005][2005];
ll n;

ll move_r(ll a) {

	a = (a + 1) % n;
	return a;
}

ll move_l(ll a) {

	a = (a - 1) % n;
	if (a < 0) a=n-1;
	return a;
}
ll dp_func(ll l, ll r, ll turn) { //0이 주인공

	if (l == r) {
		if (turn == 0)return arr[l];
		else return 0;
	}
	ll &answer = dp[l][r];
	if (answer != -1) return answer; //이미 계산된 dp라면 return 해줌

	if (turn == 0) {
		answer = max(dp_func(l, move_r(r), 1) + arr[r], dp_func(move_l(l), r, 1) + arr[l]);
	}
	else {
		if (arr[r] > arr[l]) answer = dp_func(l, move_r(r), 0);
		else {
			answer = dp_func(move_l(l), r, 0);
		}
	}
	return answer;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (ll i = 0; i < n;i++) {
		cin >> arr[i];
	}


	memset(dp, -1, sizeof(dp));
	ll answer = 0;
	for (ll i = 0; i < n;i++) {
		answer = max(answer, dp_func(i, (i + 1)%n, 0));
	}
	cout << answer;
	return 0;

}



