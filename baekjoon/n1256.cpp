#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m, k;//n���� a�� m���� z, k��° ���ڿ� 
int dp[202][202];

char answer[2] = { 'a','z' };


int dynamic(int now_n,int now_m) {

	if (now_n == 0 || now_m == 0)dp[now_n][now_m] = 1; return 1;
	if (dp[now_n][now_m] != -1)return dp[now_n][now_m]; //�̹� ����

	int &res = dp[now_n][now_m]; 
	res = dp[now_n - 1][now_m] + dp[now_n][now_m - 1];
	return res;
}

int main() {


	cin >> n >> m >> k;

	memset(dp, -1, sizeof(dp));
	dynamic(n,m);
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (k > dp[i][m]){
			answer = i; break;
		}
	}
	answer -= 1; //�տ��ִ� a�� ����


	return 0;

}