#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {


	ll x, y; //게임횟수, 이긴게임
	cin >> x >> y;

	ll max = 9876543210;
	ll a = y * 100 / x;
	ll s = 0; ll e = x;
	ll answer = max;
	while (s <= e) {

		ll mid = (s + e) / 2;
		ll newy = (y + mid) * 100 / (x + mid);
		if (newy > a) { //변함
			answer = min(answer, mid);
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}

	if (answer == max)answer = -1;
	cout << answer;
	return 0;
}