#include<iostream>

using namespace std;

typedef struct s{
	int s=0; //속력
	int d=0; //방향
	int z=0; //크키
	int c = 0;//이동함
}s;

int r, c,m;
s map[102][102];
int mm[102][102];
int answer = 0;
//방향(1 - 위, 2 - 아래, 3 - 오, 4 - 왼)

void move(int a) {
	for (int i = a; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j].d == 1) { mm[i - 1][j] = map[i][j].z; }
			else if (map[i][j].d == 2) { mm[i + 1][j] = map[i][j].z; }
			else if (map[i][j].d == 3) { mm[i][j+1] = map[i][j].z; }
			else if (map[i][j].d == 4) { mm[i - 1][j] = map[i][j].z; }
		}
	}

}

int main() {

	cin >> r >> c >> m;

	int a, b;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a;
			cin >> b;
			if (i == a && j == b) {
				cin >> map[i][j].d;
				cin >> map[i][j].s;
				cin >> map[i][j].z;
			}
		}
	}//위치(0,1) 속력 방향(1-위,2-아래,3-오,4-왼) 크기

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			if (map[i][j].d != 0) {
				map[i][j].s = 0;
				map[i][j].d = 0;
				map[i][j].z = 0;
				answer++;
				break;
			}
		}
	}


	return 0;
}