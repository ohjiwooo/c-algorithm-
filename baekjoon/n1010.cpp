#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll arr[32][32]; //ÆÄ½ºÄ®ÀÇ »ï°¢Çü ±¸Çö
int main() {

	int t, n, m;
	cin >> t;

	while (t--) {
		cin >> n >> m;

	
		for (int i = 0; i < 2;i++) {
			for (int j = 0; j <= i;j++) {
				arr[i][j] = 1;
			}
		}

		for (int i = 2; i <= m;i++) {
			for (int j = 0; j <= n;j++) {	
				if (j == 0)arr[i][j] = 1;
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
		cout << arr[m][n]<<"\n";
	}

	return 0;
}