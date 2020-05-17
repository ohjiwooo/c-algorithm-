#include<iostream>
#include<queue>
using namespace std;

int r;////행개수
int c;//열개수
int t;//초

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
			if (room[i][j] == -1) { location.push({ i,j }); } //위,아래 순서로 큐에들어감
		}
	} //입력

	for (int k = 0; k < t; k++) {
		int n = 0; //확산한 칸 수
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (room[i][j] > 0) {//확산하는 칸
					if (i != 0 && room[i - 1][j] != -1) { temp[i - 1][j] += (room[i][j] / 5); n++; }//위로확산
					if (i != r - 1 && room[i + 1][j] != -1) { temp[i + 1][j] += (room[i][j] / 5); n++; }//아래로확산
					if (j != 0 && room[i][j - 1] != -1) { temp[i][j - 1] += (room[i][j] / 5); n++; }//왼쪽확산
					if (j != c - 1) { temp[i][j + 1] += (room[i][j] / 5); n++; }//오른확산
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
		///확산

		u = location.front();
		d = location.back();
		int i = u.i;
		int j = u.j;

		while (i != 0) {
			if (room[i][j] != -1 ) {
				room[i][j] = room[i - 1][j];
			}
			i = i - 1;
		} //윗부분 0열
		while (j != c - 1) {

			room[i][j] = room[i][j + 1];

			j = j + 1;
		} //윗부분 0행
		while (i != u.i) {

			room[i][j] = room[i + 1][j];

			i = i + 1;
		} //윗부분 r-1열
		while (j != 0) {
			if (room[i][j - 1] != -1) {
				room[i][j] = room[i][j - 1];
			}
			else { room[i][j] = 0; }
			j = j - 1;
		} //윗부분 j행
	//윗부분끝

		i = d.i;
		j = d.j;
		while (i != r - 1) {
			if (room[i][j] != -1) {
				room[i][j] = room[i + 1][j];
			}
			i = i + 1;
		} //아래부분 0열
		while (j != c- 1) {

			room[i][j] = room[i][j + 1];

			j = j + 1;
		} //아래부분 r-1행
		while (i != d.i) {

			room[i][j] = room[i -1][j];

			i = i - 1;
		} //아래부분 c-1열

		
		while (j !=0) {
			if (room[i][j - 1] != -1) {
				room[i][j] = room[i][j - 1];
			}
			else { room[i][j] = 0; }
			j = j -1;
		} //아래부분 i행

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
