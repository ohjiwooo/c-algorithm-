#include<iostream>
#include<algorithm>

using namespace std;

int dp[205][205]; // i~j���� ���ߴµ� ���
int arr[205];
int divide(int s,int e) {

	if (s == e)return 0; // �ڱ��ڽ��̸� return 0
	int &n = dp[s][e];
	if (n != -1) { return n; } //�̹� dp[s][e]�� �˰����� -> return n

	n = 987654321;//�ִ����� �ΰ� ���Ž���

	int l,r;
	for (int i = s; i < e;i++) {

		l = divide(s,i);
		r = divide(i + 1, e);

		if (arr[s] == arr[i + 1]) {//���� ���� �������
			n = min(n, l + r);
		}
		else {
			n = min(n, l + r + 1);
		}
	}
	return n;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i =0; i < n;i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			dp[i][j] = -1;
		}
	}
	
	cout << divide(0, n - 1);

}


