#include<iostream>

using namespace std;

long long arr[100004];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m,a,b;
	cin >> n >> m;

	for (int i = 1; i <= n;i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];

	}

	while (m--) {
		
		cin >> a >> b;
		cout << arr[b] - arr[a-1] << "\n";

	}



	return 0;
}