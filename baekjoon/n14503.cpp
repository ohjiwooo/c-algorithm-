#include<iostream>

using namespace std; 

int n, m;
int r, c, d;
int map[55][55];
bool vis[55][55];
int ans = 0;
int flag = 0;


void left_0() {//d==0
	if (map[r][c-1] == 0 && vis[r][c-1] !=true) { // 청소할 공간있음
		d = 3;
		c -= 1;
		vis[r][c] = true;
		flag = 0;
		ans++;
	}
	else if (map[r][c - 1] == 1 || vis[r][c - 1] == true) { //청소할 공간없음
		d = 3;
		flag++;
	}
}
void left_1() {//d==1
	if (map[r-1][c] == 0 && vis[r-1][c] != true) { // 청소할 공간있음
		d = 0;
		r -= 1;
		vis[r][c] = true;
		flag = 0;
		ans++;
	}
	else if (map[r-1][c] == 1 || vis[r-1][c] == true) { //청소할 공간없음
		d = 0;
		flag++;
	}
}
void left_2() {//d==2
	if (map[r][c+1] == 0 && vis[r][c+1] != true) { // 청소할 공간있음
		d = 1;
		c += 1;
		vis[r][c] = true;
		flag = 0;
		ans++;
	}
	else if (map[r][c+1] == 1 || vis[r][c+1] == true) { //청소할 공간없음
		d = 1;
		flag++;
	}
}
void left_3() {//d==3
	if (map[r +1][c] == 0 && vis[r + 1][c] != true) { // 청소할 공간있음
		d = 2;
		r += 1;
		vis[r][c] = true;
		flag = 0;
		ans++;
	}
	else if (map[r + 1][c] == 1 || vis[r + 1][c] == true) { //청소할 공간없음
		d = 2;
		flag++;
	}
}

int main() {

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			vis[i][j] = false;
		}
	}
	

	vis[r][c] = true; ans++;

	while (1) {
		if (flag == 4) {
			if ((d == 0 && map[r + 1][c] == 1) || (d == 1 && map[r][c - 1] == 1) || (d == 2 && map[r - 1][c] == 1) || (d == 3 && map[r][c + 1] == 1)) {
				break;
			}
			else if (d == 0 && map[r+1][c] ==0) { //북쪽이고 뒤에갈길있음
				r += 1; flag = 0; 
			}
			else if (d==1 && map[r][c-1]==0) {//동쪽이고 있음
				c -= 1; flag = 0; 
			}
			else if (d == 2 && map[r-1][c] == 0) {//남쪽이고 있음
				r -= 1; flag = 0; 
			}
			else if (d == 3 && map[r][c + 1] == 0) {//서쪽이고 있음
				c += 1; flag = 0; 
			}
		}
		else if (d == 0) { left_0(); }
		else if (d == 1) { left_1(); }
		else if (d == 2) { left_2(); }
		else if (d == 3) { left_3(); }
		

	}

	cout << ans;

	return 0;
}