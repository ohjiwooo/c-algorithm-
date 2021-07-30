#include<iostream>
#include<cstring>
#include<algorithm>

typedef long long ll;
using namespace std;

ll arr[2003];
ll dp[1005][1005][2];
int n;

int move_r(int a) {

	a = (a + 1) % n;
	return a;
}

int move_r(int a) {

	a = (a + 1) % n;
	if (a < 0)a = +n;
	return a;
}
ll dp_func(int l, int r, int turn) { //0이 주인공

	if (l == r) {
		if (turn == 0)return arr[l];
		else return 0;
	}
	ll answer = dp[l][r][turn];
	if (answer != -1) return answer; //이미 계산된 dp라면 return 해줌

	if(turn==0) answer= max(dp_func()))

}
int main() {

	
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> arr[i];
	}


	memset(dp, -1, sizeof(dp));



	return 0;

}



