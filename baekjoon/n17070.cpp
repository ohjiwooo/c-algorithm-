#include<iostream>

using namespace std;

int ans = 0;
int n;
int shape = 0; //��� 0�� ���� ,1 �� ���� ,2�� �밢��
int room[20][20];

void move1(int i, int j);
void move2(int i, int j);
void move3(int i, int j);

void move(int i,int j) {

	if (i == n && j == n) {
		ans++;
		return;
	}
	else if (i > n || j > n) {
		return;
	}

	if (shape == 0) { //�����϶�
		move1(i, j);
	}
	else if (shape == 1) {//�����϶�
		move2(i, j);
	}
	else{ //�밢���϶�
		move3(i, j);
	}

}


void move1(int i,int j) {//���� �����϶� �̵�, ������ġ(i,j-1 i,j)

	if (room[i][j + 1] == 0) { //������ �̵�
		shape = 0;
		move(i, j + 1);
	}
	if (room[i][j+1]==0 && room[i+1][j] ==0 && room[i+1][j+1]==0) { //�밢������ �̵�
		shape = 2;
		move(i+1,j+1);
	}
}

void move2(int i,int j) { //���� �����϶� �̵�, ������ġ ()
	
	if (room[i+1][j]==0) {//������ �̵� ����
		shape = 1;
		move(i+1,j);
	}
	if (room[i+1][j]==0 && room[i][j+1]==0 && room[i+1][j+1]==0) {//�밢�� �̵�
		shape = 2;
		move(i+1,j+1);
	}

}

void move3(int i,int j) { //���� �밢�� �϶� �̵�, ������ġ ()
	
	if (room[i][j+1]==0) {//������ ���� �̵� ����
		shape = 0;
		move(i,j+1);
	}
	if (room[i+1][j]==0 && room[i][j+1]==0 && room[i+1][j+1]==0) {//�밢�� �̵�
		shape = 2;
		move(i + 1, j + 1);
	}
	if (room[i+1][j]==0) {//������ �̵� ����
		shape = 1;
		move(i+1,j);
	}
}



int main() {

	cin >> n;//��ũ��

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> room[i][j];
		}
	}

	move(1, 2);
	cout << ans;
	return 0;
}