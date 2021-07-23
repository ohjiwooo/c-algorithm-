#include <iostream>
using namespace std;



int main() {
	int n, m;
	cin >> n >> m;

	long long arr[1003][1003];
	
	for (int i = 1; i <= n; i++) {
		arr[i][0] = arr[i][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % 10007;
		}
	}

	cout << arr[n][m] << "\n";

	return 0;
}




