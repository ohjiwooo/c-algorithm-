#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;

ll dp[1001][1001][2];
int arr[1005];

ll dp_func(int s, int e,int turn) { //������, ����, ������ ������ -0:�ٿ�

	if (s == e) {
		if (turn == 0)return arr[s]; //�ٿ����ʸ� �ش� ī�� �����ϹǷ� return
		else { return 0; }//�ٿ����ʰ� �ƴϸ� �������� �����Ƿ� return 0
	}

	ll &answer = dp[s][e][turn];
	if (answer != -1)return answer; //�̹̱���

	if (turn == 0) { //������ �ٿ� ���ʶ��
		answer = max(dp_func(s, e - 1, 1) + arr[e], dp_func(s + 1, e,1) + arr[s]);//1�� ������ �Ѱ��ְ�, ���������� + ������ī��
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
		} //�Է¹ޱ�
		memset(dp, -1, sizeof(dp));
		cout<<dp_func(0, n - 1, 0)<<"\n";
	


	}


	return 0;
}