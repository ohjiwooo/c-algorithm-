#include<iostream>
#include <algorithm> 
using namespace std;

int n, m, k;
int arr[55][55]; //�迭
int turn[10][3]; //������ ��input
int temp[55][55]; //�迭���
int turn2[1000][10]; //�������
int a[10]; //���������
int temp_num;

void t(int a,int b,int c) { 
	int l1 = a - c;
	int l2 = b - c;
	int r1 = a + c;
	int r2 = b + c;

	int i;
	while (l1 != r1) {
		temp_num = temp[l1][l2-+1];
		
		i = 0;
		while (l1 +i < r1) {//���ʼ����� �̵�
			temp[l1+i][l2] = temp[l1+i+1][l2];
			i++;
		}


		i = 0;
		while (l2 + i < r2) { //�Ʒ��� �̵�
			temp[r1][l2 + i] = temp[r1][l1 + i + 1];
			i++;
		}

/*		cout << "===============================\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << temp[i][j] << " ";

			}
			cout << "\n";
		}*/

		i = 0;
		while (r1-i > l1) { //�����ʼ����� �̵�
			temp[r1-i][r2] = temp[r1-i-1][r2];
			i++;
		}

		i = 0;
		while (r2 -i > l1) { //�������̵�
			temp[l1][r2-i] = temp[l1][r2-i-1];
			i++;
		}
	//	temp[l1][l2] = temp_num;

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

	t(turn[0][0],turn[0][1],turn[0][2]);
/*	cout << "===============================\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << temp[i][j] << " ";

		}
		cout << "\n";
	}*/


/*	for (int i = 0; i < fac(k);i++) { //������ fac(k)��
		
		for (int j = 0; j < k;j++) { //��������
			
			int a1 = turn2[i][j];
			t(turn[a1][0], turn[a1][1], turn[a1][2]);
			
			

			sum = answer();
			if (ans > sum) {
				ans = sum;

			}
		}
	}
	
	cout << ans;*/
	return 0;
}