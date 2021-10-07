#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

ll n, m;
ll arr[100005];
int inf = 987654321;
int main() {

	cin >> n >> m;
	ll a;
	for (int i = 0; i < n;i++) {
		cin >> arr[i];
	}

	int left = 0; int right = 0; ll sum = arr[0]; int answer = inf;

	while (left < n && right< n) {
	
		
		if (sum >= m) {
			answer = min(answer, right - left + 1);
			sum -= arr[left++];
		}
		else {
			sum += arr[++right];
		}
	
	}
	if (answer == inf)cout << 0;
	else {
		cout << answer;
	}
}
