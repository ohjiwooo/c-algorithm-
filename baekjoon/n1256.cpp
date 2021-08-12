#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;

typedef long long ll;
int n, m;//n개의 a와 m개의 z, k번째 문자열 
ll k;
ll dp[102][102];
bool poss = true;
ll a = 1000000001;
string answer = "";
ll dynamic(int now_n,int now_m) { //a가 n개 z가  m개일때 조합의수

	if (now_m == 0|| now_n == 0) { //하나일땐 1
		dp[now_n][now_m] = 1; return 1;
	}
	if (dp[now_n][now_m] != -1) return dp[now_n][now_m];
	ll &res = dp[now_n][now_m];
	
	res = min((dynamic(now_n - 1,now_m) + dynamic(now_n,now_m - 1)), a);

	return res;

}

void get_char(int a, int z, int x) {

	

	if (a == 0) {
		for (int i = 0; i < z;i++) {
			answer += 'z';
		}
		return;
	}
	else if (z==0) {
		for (int i = 0; i < a; i++) {
			answer += 'a';
		}
		return;
	}
	int now = dp[a - 1][z];
	if ( x <= now) {
		answer += 'a';
		get_char(a - 1, z, x);
	}
	else{
		answer += 'z';
		get_char(a , z-1, x-now);
	}

}
int main() {


	cin >> n >> m >> k;

	memset(dp, -1, sizeof(dp));
	dynamic(n,m);

	if (k > dp[n][m] || k > 1000000000)cout << -1;
	else {
		get_char(n, m, k);
		cout << answer;
	}
	return 0;

}