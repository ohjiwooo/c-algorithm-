#include<iostream>
#include <algorithm> 
using namespace std;

int n, m, k;
int arr[505][505];
int turn[10][3];
int temp[505][505];
int turn2[1000][10];
int a[10];

void t(int a,int b,int c) { 
	int l1 = a - c;
	int l2 = b - c;
	int r1 = a + c;
	int r2 = b + c;

	int i;
	while (l1 != r1) {
		i = 1;
		while (l2 + i <= r2) { //�������̵�
			temp[l1][l2 + i] = arr[l1][l2 + i - 1];
			i++;
		}

		i = 1;
		while (l1 + i <= r1) { //�����ʼ����� �̵�
			temp[l1 + i][r2] = arr[l1 + i - 1][r2];
			i++;
		}

		i = 1;
		while (r2 - i >= l2) { //�Ʒ��� �̵�
			temp[r1][r2 - i] = arr[r1][r2 - i + 1];
			i++;
		}

		i = 1;
		while (r1 - i >= l1) {//���ʼ����� �̵�
			temp[r1 - i][l2] = arr[r1 - i + 1][l2];
			i++;
		}

		l1++;
		l2++;
		r1--;
		r2--;
	}
}

int fac(int a) {
	int ans=1;
	while (a >= 1) {
		ans *= a;
		a--;
	}
	return ans;
}
int answer() {
	int ans = 100000;
	int sum = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m;j++) {
			sum += temp[i][j];
		}
		if (ans > sum) { ans = sum; }
		sum = 0;
	}
	return ans;
}
int main() {

	cin >> n >> m >> k;
	
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= m;j++) {
			cin >> arr[i][j];
			temp[i][j] = arr[i][j];
			
		}
	} //�迭�Է�

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> turn[i][j];
		}
	} //ȸ���Է�

	int ans = 100000;
	int sum;
	
	for (int i = 0; i < k;i++) {
		a[i] = i;
	} //�������ϱ� ���� �迭

	int j = 0;
	do {

		for (int i = 0; i < k; i++) {
			turn2[j][i] = a[i];
		}

		j++;

	} while (next_permutation(a,a+k));



	for (int i = 0; i < fac(k);i++) {
	
		t(turn[i][0], turn[i][1], turn[i][2]);
		sum = answer();
		if (ans>sum) {
			ans = sum;
		}
	
	}
	
	cout << ans;
	return 0;
}