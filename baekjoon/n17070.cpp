#include<iostream>

using namespace std;

int ans = 0;
int n;
int shape = 0; //모양 0은 가로 ,1 은 세로 ,2는 대각선
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

	if (shape == 0) { //가로일때
		move1(i, j);
	}
	else if (shape == 1) {//세로일때
		move2(i, j);
	}
	else{ //대각선일때
		move3(i, j);
	}

}


void move1(int i,int j) {//현재 가로일때 이동, 현재위치(i,j-1 i,j)

	if (room[i][j + 1] == 0) { //옆으로 이동
		shape = 0;
		move(i, j + 1);
	}
	if (room[i][j+1]==0 && room[i+1][j] ==0 && room[i+1][j+1]==0) { //대각선으로 이동
		shape = 2;
		move(i+1,j+1);
	}
}

void move2(int i,int j) { //현재 세로일때 이동, 현재위치 ()
	
	if (room[i+1][j]==0) {//밑으로 이동 세로
		shape = 1;
		move(i+1,j);
	}
	if (room[i+1][j]==0 && room[i][j+1]==0 && room[i+1][j+1]==0) {//대각선 이동
		shape = 2;
		move(i+1,j+1);
	}

}

void move3(int i,int j) { //현재 대각선 일때 이동, 현재위치 ()
	
	if (room[i][j+1]==0) {//오른쪽 직선 이동 가로
		shape = 0;
		move(i,j+1);
	}
	if (room[i+1][j]==0 && room[i][j+1]==0 && room[i+1][j+1]==0) {//대각선 이동
		shape = 2;
		move(i + 1, j + 1);
	}
	if (room[i+1][j]==0) {//밑으로 이동 세로
		shape = 1;
		move(i+1,j);
	}
}



int main() {

	cin >> n;//집크기

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> room[i][j];
		}
	}

	move(1, 2);
	cout << ans;
	return 0;
}