#include<iostream>

using namespace std;

typedef struct s{
	int s; //속력
	int d; //방향
	int z; //크키
}s;

int r, c,m;
s map[102][102];
int answer = 0;
s temp[102][102];

void change(int a,int b,int c,int d) {
	if (temp[a][b].z < map[c][d].z) { //이미있는 애가 없거나 더 작음
		temp[a][b].s = map[c][d].s;
		temp[a][b].d = map[c][d].d;
		temp[a][b].z = map[c][d].z;
	}

}


void move() {
	for (int i = 1; i < r; i++) {
		for (int j = 1; j < c; j++) {
			if (map[i][j].d == 1) {//위
				


			}
			else if (map[i][j].d == 2) {//아래
				
			}
			else if (map[i][j].d == 3) {//오른쪽
				
		
			}
			else if (map[i][j].d == 4) {//왼쪽
				
				
			}
		}
	}

}

void update() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j].d = temp[i][j].d;
			map[i][j].s = temp[i][j].s;
			map[i][j].z = temp[i][j].z;
			temp[i][j].d = 0;
			temp[i][j].z = 0;
			temp[i][j].s = 0;
		}
	}

}

int main() {
	int a, b, c, d, e;
	cin >> r >> c >> m;
	
	for (int k = 0; k <r*m; k++) {
		cin >> a;
		cin >> b;
		cin >> c;
		cin >> d;
		cin >> e;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (i == a && j == b) {
					map[i][j].d = c;
					map[i][j].s=d;
					map[i][j].z=e;
				}
				else { temp[i][j].z = 0; }
			}
		}
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			if (map[i][j].d != 0) {
				map[i][j].s = 0;
				map[i][j].d = 0;
				map[i][j].z = 0;
				answer++;
				move();
				update();
				break;
			}
		}
	}
	cout << answer;


	return 0;
}