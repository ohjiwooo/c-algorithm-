#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;

ll dp[1001][1001][2];
int arr[1005];

ll dp_func(int s, int e,int turn) { //시작점, 끝점, 누구의 턴인지 -0:근우

	if (s == e) {
		if (turn == 0)return arr[s]; //근우차례면 해당 카드 선택하므로 return
		else { return 0; }//근우차례가 아니면 선택하지 않으므로 return 0
	}

	ll &answer = dp[s][e][turn];
	if (answer != -1)return answer; //이미구함

	if (turn == 0) { //지금이 근우 차례라면
		answer = max(dp_func(s, e - 1, 1) + arr[e], dp_func(s + 1, e,1) + arr[s]);//1의 턴으로 넘겨주고, 범위를줄임 + 선택한카드
	}
	else {
		answer= min(dp_func(s, e - 1, 0), dp_func(s + 1, e, 0));
	}
	return answer;

}
int main() {

	int t, n;
	cin >> t;

	while (t--) {

		cin >> n;
		
		for (int i = 0; i < n;i++) {
			cin >> arr[i];
		} //입력받기
		memset(dp, -1, sizeof(dp));
		cout<<dp_func(0, n - 1, 0)<<"\n";
	


	}


	return 0;
}