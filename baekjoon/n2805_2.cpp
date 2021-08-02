#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int tree[1000005];

int main() {


	ios::sync_with_stdio(0);
	cin.tie(0);
	ll maxx = 0;
	ll n, m;//나무 수, 상근이가 원하는 길이
	cin >> n >> m;

	for (int i = 0; i < n;i++) {
		cin >> tree[i];
		if (tree[i] > maxx)maxx = tree[i];
	}

	ll s = 0; ll e = maxx; ll answer=0;

	while (e >= s) {
	
		ll mid = (s + e) / 2;
		if (mid == 0)break;
		ll sum = 0;
		for (int i = 0; i < n;i++) {
			if (tree[i] > mid)sum += (tree[i] - mid);
		}

		if (sum >= m) {
			if(answer<mid)answer = mid;
			s= mid + 1;
		}
		else {
			e = mid - 1;
		}
	
	}
	cout << answer;
	return 0;
}