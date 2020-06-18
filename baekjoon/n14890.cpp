#include<iostream>

using namespace std;

int n,l;
int map[105][105];
int flag= 0;
int ans = 0;
bool loc[105][105];

int slope(int i1,int j1,int i2,int j2) { //��� �������� ��ǥ ���� 1 �Ұ��� 0
	int i;
	if (i1 == i2) { //���϶�
		if (map[i1][j1] > map[i2][j2]) { //������ ã��
			for (i = 0; i < l;i++) { //���� ���̺�
				if (j2 + i >= n) { return 0; }
				if (map[i2][j2] != map[i2][j2 + i] ) { return 0; }
				else { loc[i2][j2 + i] = true;}
			}
		}
		else {
			for (i = 0; i < l; i++) { //���� ���̺�
				if (j1 - i < 0 ) { return 0; }
				if (map[i1][j1] != map[i1][j1 - i] || loc[i1][j1-i]==true ) { return 0; }
			}
		}
	}
	else if (j1 == j2) { //���϶�
		if (map[i1][j1] > map[i2][j2]) { //������ ã��
			for (i = 0; i < l; i++) { //���� ���̺�
				if (i2 + i >= n) { return 0; }
				if (map[i2][j2] != map[i2 + i][j2]) { return 0; }
				else { loc[i2+i][j2] = true;}
			}
		}
		else {
			for (i = 0; i < l; i++) { //���� ���̺�
				if (i1 - i < 0) { return 0; }
				if (map[i1][j1] != map[i1-i][j1] || loc[i1-i][j1]==true) { return 0; }
			}
		}
	}
	return 1;

}

int pos(int a) {
	if (a < 0) { return -a; }
	else { return a; }
}

int main() {

	cin >> n >> l;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			cin >> map[i][j];
			loc[i][j] = false;
		}
	}


	for (int i = 0; i < n; i++) { //��
		for (int j = 0; j+1 < n; j++) {
			if (pos(map[i][j] - map[i][j+1]) ==1) { //���̰� ��ĭ
				if (slope(i, j, i, j + 1) == 0) { flag = 1; break; } //���� �Ѽ�����
			}
			else if (pos(map[i][j] - map[i][j + 1]) > 1) { flag = 1; break; } //���̰� ��ĭ�̻�
		}
		if (flag == 0) { ans++; }
		flag = 0;
	}
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			loc[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) { //��
		for (int j = 0; j+1 < n; j++) {
			if (pos(map[j][i] - map[j+1][i]) == 1) { //���̰� ��ĭ
				if (slope(j, i, j+1, i) == 0) { flag = 1; break; } //���� �Ѽ�����
			}
			else if (pos(map[j+1][i] - map[j][i]) > 1) { flag = 1; break; } //���̰� ��ĭ�̻�
		}
		if (flag == 0) { ans++; }
		flag = 0;
	}

	cout << ans;
	return 0;
}