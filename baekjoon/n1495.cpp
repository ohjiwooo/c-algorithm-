#include<iostream>
#include<algorithm>
using namespace std;


int dp(int n,int s,int m, int arr[102],int map[102][1005],bool vis[102][1005]) {

	for (int i = 0; i <= m;i++) {
		map[n][i] = i;
		vis[n][i] = true;
	}

	for (int i = n; i > 0;i--) {
		for (int j = 0; j <= m;j++) {
			if (j-arr[i] >= 0 && vis[i][j]!=false) {
				map[i - 1][j - arr[i]] = max(map[i - 1][j - arr[i]], map[i][j]);
				vis[i - 1][j - arr[i]] = true;
			}
			if (j + arr[i] <= m && vis[i][j]!=false) {
				map[i - 1][j + arr[i]]= max(map[i - 1][j + arr[i]],map[i][j]);
				vis[i - 1][j + arr[i]] = true;
			}
		}
	}
	if (vis[0][s]==false) {
		return -1;
	}
	else {
		return map[0][s];
	}
}

int main() {

	int n = 0;
	int s = 0;
	int m = 0;
	cin >> n >> s >> m;//°îÀÇ°³¼ö, ½ÃÀÛº¼·ı, ÃÖ´ëº¼·ı
	int map[102][1005] = { 0, };
	int arr[102] = { 0, };
	bool vis[102][1005] = { false, };

	for (int i = 1; i <= n;i++) {
		cin >> arr[i];
	}
	cout<<dp(n, s, m, arr,map,vis);
	
	return 0;
}