#include<iostream>
#include<algorithm>
using namespace std;

int n, m;//n�� ���� ������ m�ʿ�
int use[105];
int cost[105];
int dp[105][10003];

int main() {

	cin >> n >> m;
	int num = 0;
	for (int i = 1; i <= n;i++) {
		cin >> use[i];
	}
	for (int i = 1; i <= n;i++) {
		cin >> cost[i];
		num += cost[i];
	}

	//m����Ʈ�� Ȯ���ϱ����� ���� cost
	
	for (int i = 1; i <= n;i++) { //i���� Ž�������� cost j �� ����Ͽ� �������ִ� �ִ�޸�
		for (int j = 1; j <= num;j++) {
			if (j-cost[i] >= 0) { //cost�� j���� �����Ƿ� ��������
				dp[i][j] = max(dp[i-1][j - cost[i]] + use[i], dp[i-1][j]);
			}
			else {
				dp[i][j] =dp[i - 1][j];
			}
			if (dp[i][j]>=m) {
				num = min(num, j);
			}
		}
	}
	cout << num;
}