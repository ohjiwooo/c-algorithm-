#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n,t;
int arr[1005];
int dp[1005][1005][2];




int f(int s, int e,int t) {

	if (s == e) {
		if (t == 1)return arr[s]; //1이면 근우 턴이므로 점수에 추가
		else return 0;
	}
	int &res = dp[s][e][t];
	if (res != -1)return res;
	if (t == 0) { //근우 차례가 아님
		res= min(f(s + 1, e, 1), f(s, e - 1, 1));
	}
	else {
		res= max(f(s + 1, e, 0) + arr[s], f(s, e - 1, 0) + arr[e]);
	}

	return res;
}

int main() {



	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n;i++) {
			cin >> arr[i];
		}
		memset(dp, -1, sizeof(dp));
		cout<<f(0, n - 1, 1)<<"\n";
		

	}



}