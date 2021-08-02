#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll arr[100005];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;
	

	for (int i = 0; i < n;i++) {
		cin >> arr[i];
	}

	ll s = 0; ll e = 0; ll answer = 100005;
	ll sum = arr[s];
	while (s < n && e < n) {
	
		if (sum >= m) { //정답임
			answer = min(answer, e-s+1);
			sum -= arr[s++]; //왼쪽포인터 이동
		}
		else {//정답아님
			sum += arr[++e];//오른쪽 포인터 이동
		}
	}
	if (answer == 100005)answer = 0;
	cout << answer;
	return 0;
}