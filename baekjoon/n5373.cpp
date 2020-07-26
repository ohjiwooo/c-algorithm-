#include<iostream>
#include<queue>
using namespace std;

typedef struct s {

	char c;
	char d;

}s;

int n;
int m;
queue <s> qq;
char map[12][9];
void turn2(char a, char b);
void init() {

	for (int i = 3; i < 6; i++) {//green
		for (int j = 0; j < 3; j++) {
			map[i][j] = 'g';
		}
	}
	for (int i = 0; i < 3; i++) {//orange
		for (int j = 3; j < 6; j++) {
			map[i][j] = 'o';
		}
	}for (int i = 3; i < 6; i++) {//white
		for (int j = 3; j < 6; j++) {
			map[i][j] = 'w';
		}
	}for (int i = 6; i < 9; i++) {//red
		for (int j = 3; j < 6; j++) {
			map[i][j] = 'r';
		}
	}for (int i = 9; i < 12; i++) {//yellow
		for (int j = 3; j < 6; j++) {
			map[i][j] = 'y';
		}
	}for (int i = 3; i < 6; i++) {//blue
		for (int j = 6; j < 9; j++) {
			map[i][j] = 'b';
		}
	}
}

void turn3(int ni, int nj, int d) {

	if (d == 1) {//시계방향
		int t1 = map[ni][nj];
		int t2 = map[ni][nj + 1];
		int t3 = map[ni][nj + 2];
		int t4 = map[ni + 1][nj];
		int t5 = map[ni + 1][nj + 2];
		int t6 = map[ni + 2][nj];
		int t7 = map[ni + 2][nj + 1];
		int t8 = map[ni + 2][nj + 2];

		map[ni][nj] = t6;
		map[ni][nj + 1] = t4;
		map[ni][nj + 2] = t1;
		map[ni + 1][nj] = t7;
		map[ni + 1][nj + 2] = t2;
		map[ni + 2][nj] = t8;
		map[ni + 2][nj + 1] = t5;
		map[ni + 2][nj + 2] = t3;

	}
	if (d == 2) {

		int t1 = map[ni][nj];
		int t2 = map[ni][nj + 1];
		int t3 = map[ni][nj + 2];
		int t4 = map[ni + 1][nj];
		int t5 = map[ni + 1][nj + 2];
		int t6 = map[ni + 2][nj];
		int t7 = map[ni + 2][nj + 1];
		int t8 = map[ni + 2][nj + 2];

		map[ni][nj] = t3;
		map[ni][nj + 1] = t5;
		map[ni][nj + 2] = t8;
		map[ni + 1][nj] = t2;
		map[ni + 1][nj + 2] = t7;
		map[ni + 2][nj] = t1;
		map[ni + 2][nj + 1] = t4;
		map[ni + 2][nj + 2] = t6;
	}
}

void print() {
	for (int i = 3; i < 6; i++) {//blue
		for (int j = 3; j < 6; j++) {
			cout << map[i][j];
		}cout << "\n";
	}
}

void turn() {


	while (qq.empty() != true) {
		char a = qq.front().c;
		char b = qq.front().d;
		qq.pop();
		turn2(a, b);
	}
}
void turn2(char a, char b) {
	if (a == 'B') {
		if (b == '+') {
			char c1 = map[11][3];
			char c2 = map[11][4];
			char c3 = map[11][5];

			map[11][3] = map[3][2];
			map[11][4] = map[3][1];
			map[11][5] = map[3][0];//d

			map[3][0] = map[3][3];
			map[3][1] = map[3][4];
			map[3][2] = map[3][5];//l

			map[3][3] = map[3][6];
			map[3][4] = map[3][7];
			map[3][5] = map[3][8];//u

			map[3][6] = c3;
			map[3][7] = c2;
			map[3][8] = c1;//r

			turn3(0, 3, 1);


		}
		else {
			char c1 = map[11][3];
			char c2 = map[11][4];
			char c3 = map[11][5];

			map[11][3] = map[3][8];
			map[11][4] = map[3][7];
			map[11][5] = map[3][6];//d

			map[3][6] = map[3][3];
			map[3][7] = map[3][4];
			map[3][8] = map[3][5];//r

			map[3][3] = map[3][0];
			map[3][4] = map[3][1];
			map[3][5] = map[3][2];//u

			map[3][0] = c3;
			map[3][1] = c2;
			map[3][2] = c1;//l

			turn3(0, 3, 2);
		}
	}

	if (a == 'U') {
		if (b == '+') {
			char c1 = map[6][3];
			char c2 = map[6][4];
			char c3 = map[6][5];

			map[6][3] = map[5][6];
			map[6][4] = map[4][6];
			map[6][5] = map[3][6];//f

			map[3][6] = map[2][3];
			map[4][6] = map[2][4];
			map[5][6] = map[2][5];//r

			map[2][3] = map[5][2];
			map[2][4] = map[4][2];
			map[2][5] = map[3][2];//b

			map[3][2] = c1;
			map[4][2] = c2;
			map[5][2] = c3;//l

			turn3(3, 3, 1);

		}
		else {
			char c1 = map[3][2];
			char c2 = map[4][2];
			char c3 = map[5][2];

			map[3][2] = map[2][5];
			map[4][2] = map[2][4];
			map[5][2] = map[2][3];//l

			map[2][3] = map[3][6];
			map[2][4] = map[4][6];
			map[2][5] = map[5][6];//b

			map[3][6] = map[6][5];
			map[4][6] = map[6][4];
			map[5][6] = map[6][3];//r

			map[6][3] = c1;
			map[6][4] = c2;
			map[6][5] = c3;//f

			turn3(3, 3, 2);
		}
	}

	if (a == 'F') {
		if (b == '+') {
			char c1 = map[5][3];
			char c2 = map[5][4];
			char c3 = map[5][5];

			map[5][3] = map[5][0];
			map[5][4] = map[5][1];
			map[5][5] = map[5][2];//u

			map[5][0] = map[9][5];
			map[5][1] = map[9][4];
			map[5][2] = map[9][3];//l

			map[9][5] = map[5][6];
			map[9][4] = map[5][7];
			map[9][3] = map[5][8];//d

			map[5][6] = c1;
			map[5][7] = c2;
			map[5][8] = c3;//r

			turn3(6, 3, 1);
		}
		else {
			char c1 = map[5][0];
			char c2 = map[5][1];
			char c3 = map[5][2];

			map[5][0] = map[5][3];
			map[5][1] = map[5][4];
			map[5][2] = map[5][5];//l

			map[5][3] = map[5][6];
			map[5][4] = map[5][7];
			map[5][5] = map[5][8];//u

			map[5][6] = map[9][5];
			map[5][7] = map[9][4];
			map[5][8] = map[9][3];//r

			map[9][5] = c1;
			map[9][4] = c2;
			map[9][3] = c3;//d

			turn3(6, 3, 2);
		}
	}
	if (a == 'D') {
		if (b == '+') {
			char c1 = map[3][8];
			char c2 = map[4][8];
			char c3 = map[5][8];

			map[3][8] = map[8][5];
			map[4][8] = map[8][4];
			map[5][8] = map[8][3];//r

			map[8][5] = map[5][0];
			map[8][4] = map[4][0];
			map[8][3] = map[3][0];//f

			map[5][0] = map[0][3];
			map[4][0] = map[0][4];
			map[3][0] = map[0][5];//l

			map[0][3] = c1;
			map[0][4] = c2;
			map[0][5] = c3;//b

			turn3(9, 3, 1);
		}
		else {
			char c1 = map[3][0];
			char c2 = map[4][0];
			char c3 = map[5][0];

			map[3][0] = map[8][3];
			map[4][0] = map[8][4];
			map[5][0] = map[8][5];//l

			map[8][3] = map[5][8];
			map[8][4] = map[4][8];
			map[8][5] = map[3][8];//f

			map[5][8] = map[0][5];
			map[4][8] = map[0][4];
			map[3][8] = map[0][3];//r

			map[0][5] = c1;
			map[0][4] = c2;
			map[0][3] = c3;//b

			turn3(9, 3, 2);
		}
	}
	if (a == 'L') {
		if (b == '+') {
			char c1 = map[6][3];
			char c2 = map[7][3];
			char c3 = map[8][3];

			map[6][3] = map[3][3];
			map[7][3] = map[4][3];
			map[8][3] = map[5][3];//f

			map[3][3] = map[0][3];
			map[4][3] = map[1][3];
			map[5][3] = map[2][3];//u

			map[0][3] = map[9][3];
			map[1][3] = map[10][3];
			map[2][3] = map[11][3];//b

			map[9][3] = c1;
			map[10][3] = c2;
			map[11][3] = c3;//l

			turn3(3, 0, 1);
		}
		else {
			char c1 = map[0][3];
			char c2 = map[1][3];
			char c3 = map[2][3];

			map[0][3] = map[3][3];
			map[1][3] = map[4][3];
			map[2][3] = map[5][3];//b

			map[3][3] = map[6][3];
			map[4][3] = map[7][3];
			map[5][3] = map[8][3];//u

			map[6][3] = map[9][3];
			map[7][3] = map[10][3];
			map[8][3] = map[11][3];//r

			map[9][3] = c1;
			map[10][3] = c2;
			map[11][3] = c3;//f

			turn3(3, 0, 2);
		}
	}
	if (a == 'R') {
		if (b == '+') {
			char c1 = map[0][5];
			char c2 = map[1][5];
			char c3 = map[2][5];

			map[0][5] = map[3][5];
			map[1][5] = map[4][5];
			map[2][5] = map[5][5];//b

			map[3][5] = map[6][5];
			map[4][5] = map[7][5];
			map[5][5] = map[8][5];//u

			map[6][5] = map[9][5];
			map[7][5] = map[10][5];
			map[8][5] = map[11][5];//f

			map[9][5] = c1;
			map[10][5] = c2;
			map[11][5] = c3;//d

			turn3(3, 6, 1);

		}
		else {
			char c1 = map[9][5];
			char c2 = map[10][5];
			char c3 = map[11][5];

			map[9][5] = map[6][5];
			map[10][5] = map[7][5];
			map[11][5] = map[8][5];//d

			map[6][5] = map[3][5];
			map[7][5] = map[4][5];
			map[8][5] = map[5][5];//f

			map[3][5] = map[0][5];
			map[4][5] = map[1][5];
			map[5][5] = map[2][5];//u

			map[0][5] = c1;
			map[1][5] = c2;
			map[2][5] = c3;//b

			turn3(3, 6, 2);
		}
	}
}

int main() {

	cin >> n;

	char a, b;
	init();
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> a;
			cin >> b;
			qq.push({ a, b });
		}

		turn();
		print();
		init();

	}

	return 0;
}