#include<iostream>

using namespace std;

typedef struct s{
	int s; //속력
	int d; //방향
	int z; //크키
}s;

int r, c, m;
s map[105][105];
int answer = 0;
s temp[105][105];



void del(int i,int j) {
	map[i][j].d = 0;
	map[i][j].s = 0;
	map[i][j].z = 0;
}
void del2(int i, int j) {
	temp[i][j].d = 0;
	temp[i][j].s = 0;
	temp[i][j].z = 0;
}

void move2(int n,int i,int j) {
	int m = 0;
	if (map[i][j].d == 1 || map[i][j].d == 2) { m = i;}
	else { m = j; }
	if (n == 0) {
		if (map[i][j].z > temp[i][j].z) {//방금온애가 더 큼
			temp[i][j] = map[i][j];
			del(i, j);
		}
		else { del(i, j); }
	}
	for (int k = 0; k < n; k++) {
		if ((map[i][j].d == 1 && i!=1)||(map[i][j].d==2 &&i==r )) {
			map[i][j].d = 1;
			m -= 1;
			if (m == 1) { map[i][j].d = 2; }
			if (k == n - 1) {
				if(map[i][j].z>temp[m][j].z) {//방금온애가 더 큼
					temp[m][j] = map[i][j];
					del(i, j);
				}
				else { del(i, j); }
			}
		} //위
		else if ((map[i][j].d == 2 && i!=r)||(map[i][j].d==1 &i==1)) {
			map[i][j].d = 2;
			m += 1;
			if (m == r ) { map[i][j].d = 1; }
			if (k == n - 1) {
				if (map[i][j].z > temp[m][j].z) {//누가있고 방금온애가 더 큼
					temp[m][j] = map[i][j];
					del(i, j);
				}
				else { del(i, j); }
			}
		}//아래
		else if((map[i][j].d == 3 && j!=c)||(map[i][j].d==4&&j==1)) {
			map[i][j].d = 3;
			m += 1;
			if (m == c ) { map[i][j].d = 4; }
			if (k == n - 1) {
				if (map[i][j].z > temp[i][m].z) {//누가있고 방금온애가 더 큼
					temp[i][m] = map[i][j];
					del(i, j);
				}
				else { del(i, j); }
			}
		}//오
		else if ((map[i][j].d==4 && j!=1)||(map[i][j].d==3&&j==c)) {
			map[i][j].d = 4;
			m -= 1;
			if (m == 1) { map[i][j].d = 3; }
			if (k == n - 1) {
				if ( map[i][j].z > temp[i][m].z ) {//누가있고 방금온애가 더 큼
					temp[i][m] = map[i][j];
					del(i, j);
				}
				else { del(i, j); }
			}
		}//왼
	}
}

void move() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j].z != 0) {
				int n = 0;//속력정리
				if (map[i][j].d == 1 || map[i][j].d == 2) {
					n = map[i][j].s % (r*2-2);
				}
				else { n = map[i][j].s % (c*2-2); }
				move2(n, i, j);
			}
		}
	}
}

void update() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (temp[i][j].z != 0) {
				map[i][j] = temp[i][j];
				del2(i, j);
			}
		}
	}
}

void p() {
	cout << "==========\n";
	for (int i=1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout<<map[i][j].z<<" ";
		}
		cout << "\n";
	}
	cout << "===========\n";

}

int main() {
	
	cin >> r >> c >> m;
	int n1,n2,n3,n4,n5;

	

	for (int k = 0; k <m; k++) {
		cin >> n1;
		cin >> n2;
		cin >> n3;
		cin >> n4;
		cin >> n5;
		map[n1][n2].s = n3;
		map[n1][n2].d = n4;
		map[n1][n2].z = n5;	
	}
 // 입력
	
	p();
	for (int j = 1; j <= c; j++) {
		for (int i = 1; i <= r; i++) {
			if (map[i][j].z != 0) {
				answer += map[i][j].z; //찾음 잡음
				map[i][j].s = 0;
				map[i][j].d = 0;
				map[i][j].z = 0;
				break;
			}
		}
		move(); //이동
		update();
		p();
	}
	cout << answer;
	return 0;
}