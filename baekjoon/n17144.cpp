#include<iostream>
#include<queue>
using namespace std;

int r;////�ళ��
int c;//������
int t;//��

int room[52][52];
int temp[52][52] = { 0, };

typedef struct s {
	int i;
	int j;
}s;

int main() {
	
	cin >> r >> c >> t;

	queue<s> location;
	s u;
	s d;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> room[i][j];
			if (room[i][j] == -1) { location.push({ i,j }); } //��,�Ʒ� ������ ť����
		}
	} //�Է�

	for (int k = 0; k < t; k++) {
		int n = 0; //Ȯ���� ĭ ��
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (room[i][j] > 0) {//Ȯ���ϴ� ĭ
					if (i != 0 && room[i - 1][j] != -1) { temp[i - 1][j] += (room[i][j] / 5); n++; }//����Ȯ��
					if (i != r - 1 && room[i + 1][j] != -1) { temp[i + 1][j] += (room[i][j] / 5); n++; }//�Ʒ���Ȯ��
					if (j != 0 && room[i][j - 1] != -1) { temp[i][j - 1] += (room[i][j] / 5); n++; }//����Ȯ��
					if (j != c - 1) { temp[i][j + 1] += (room[i][j] / 5); n++; }//����Ȯ��
					temp[i][j] = (temp[i][j] - (room[i][j] / 5)*n);
				}
				n = 0;
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				room[i][j] += temp[i][j]; temp[i][j] = 0;
			}
		}
		///Ȯ��

		u = location.front();
		d = location.back();
		int i = u.i;
		int j = u.j;

		while (i != 0) {
			if (room[i][j] != -1 ) {
				room[i][j] = room[i - 1][j];
			}
			i = i - 1;
		} //���κ� 0��
		while (j != c - 1) {

			room[i][j] = room[i][j + 1];

			j = j + 1;
		} //���κ� 0��
		while (i != u.i) {

			room[i][j] = room[i + 1][j];

			i = i + 1;
		} //���κ� r-1��
		while (j != 0) {
			if (room[i][j - 1] != -1) {
				room[i][j] = room[i][j - 1];
			}
			else { room[i][j] = 0; }
			j = j - 1;
		} //���κ� j��
	//���κг�

		i = d.i;
		j = d.j;
		while (i != r - 1) {
			if (room[i][j] != -1) {
				room[i][j] = room[i + 1][j];
			}
			i = i + 1;
		} //�Ʒ��κ� 0��
		while (j != c- 1) {

			room[i][j] = room[i][j + 1];

			j = j + 1;
		} //�Ʒ��κ� r-1��
		while (i != d.i) {

			room[i][j] = room[i -1][j];

			i = i - 1;
		} //�Ʒ��κ� c-1��

		
		while (j !=0) {
			if (room[i][j - 1] != -1) {
				room[i][j] = room[i][j - 1];
			}
			else { room[i][j] = 0; }
			j = j -1;
		} //�Ʒ��κ� i��

	}

	int sum = 0;
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			sum += room[i][j];
		}
	}
	
	cout << sum+2;

	return 0;
}
