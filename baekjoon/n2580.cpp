#include<iostream>
#include<vector>
using namespace std;

int map[15][15];
int num = 0;
vector <pair<int, int>>v(100);


//��ü 0 ��������

void p() {
	cout << "==============================\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << " ";
		}cout << "\n";
	}
}

void in() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) { v[num].first = i; v[num++].second = j; }
		}
	}
}

bool check(int i, int j) {
	
	bool arr[10] = { false };
	bool ans = true;

	for (int k = 0; k < 9; k++) { //��˻�
		if (map[i][k]!=0) {
			if (arr[map[i][k]] == false) { arr[map[i][k]] = true; }
			else { return false; }
		}
	}

	
	for (int k = 0; k < 10; k++) { //���˻�
		arr[k] = false;
	}
	for (int k = 0; k < 9; k++) { //���˻�
		if (map[k][j]!=0) {
			if (arr[map[k][j]] == false) { arr[map[k][j]] = true; }
			else { return false; }
		}
	}

	for (int k = 0; k < 10; k++) { //���˻�
		arr[k] = false;
	}
	int k, k2;
	if (i < 3) { k = 0; }
	else if (i < 6) { k = 3; }
	else { k = 6; }
	if (j < 3) { k2 = 0; }
	else if (j < 6) { k2 = 3; }
	else { k2 = 6; }
	for (int a = k; a < k + 3;a++) {//�簢�˻�
		for (int b = k2; b < k2 + 3;b++) {
			if (map[a][b]!=0) {
				if (arr[map[a][b]] == false) { arr[map[a][b]] = true; }
				else { return false; }
			}
		}
	}

	return true;
}

bool f(int now) {
	
	if (num == 0) { p(); return true; }
	bool arr[10] = { false };//false�� ���� �Ⱦ� ����
	int ni = v[now].first;
	int nj = v[now].second;

	for (int i = 0; i < 9;i++) {//��
		arr[map[ni][i]] = true;
	}
	for (int i = 0; i < 9; i++) {//��
		arr[map[i][nj]] = true;
	}
	int k, k2;
	if (ni < 3) { k = 0; }
	else if (ni < 6) { k = 3; }
	else { k = 6; }
	if (nj < 3) { k2 = 0; }
	else if (nj < 6) { k2 = 3; }
	else { k2 = 6; }

	for (int a = k; a < k + 3; a++) {//�簢�˻� 
		for (int b = k2; b < k2 + 3; b++) {
			arr[map[a][b]] = true;
		}
	}

	for (int i = 1; i < 10;i++) {
		if (arr[i] != true ) {
			map[ni][nj] = i;
			if (check(ni,nj)==true) {
				num--;
				if (f(now + 1) == true) { return true; };
				num++;
			}
		}
	}
	return false;
}


int main() {
	
	in();
	f(0);
	return 0;
}