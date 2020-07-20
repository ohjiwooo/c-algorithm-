#include<iostream>
#include<queue>
using namespace std;

typedef struct s {

	int t;
	int x;
	int y;

}s;

int map[15][15] = {0,};
int n;
int bn = 0;
queue <s> qq;
int answer = 0;

//t = 1: 크기가 1×1인 블록을(x, y)에 놓은 경우
//t = 2 : 크기가 1×2인 블록을(x, y), (x, y + 1)에 놓은 경우
//t = 3 : 크기가 2×1인 블록을(x, y), (x + 1, y)에 놓은 경우

void new_block(int t,int x,int y) {

	int bx1, by1, bx2, by2;

	if (t==1||t==2) { 
		if (t == 1) { bx1 = x; by1 = y; }
		else { bx1 = x; by1 = y + 1; }

		while (map[bx1][by1+1] == 0&& by1+1<10) {
			map[bx1][by1++] = 0;
			map[bx1][by1] = bn;
		}

		if (t == 2) { map[bx1][by1 - 1] = bn; }

	}//t1,t2 blue
	else {
		bx1 = x; by1 = y; bx2 = x + 1; by2 = y;
		
		while (map[bx1][by1 + 1] ==0 && by1 + 1 < 10 && map[bx2][by2 + 1] ==0 && by2 + 1 < 10) {
			map[bx1][by1++] = 0;
			map[bx2][by2++] = 0;
			map[bx1][by1] = bn;
			map[bx2][by2] = bn;
		}
	
	}//t3 blue

	if (t == 1 || t == 3) {
		if (t == 1) { bx1 = x; by1 = y; }
		else { bx1 = x+1; by1 = y; }

		while (map[bx1+1][by1] ==0 && bx1 + 1 < 10) {
			map[bx1++][by1] = 0;
			map[bx1][by1] = bn;
		}

		if (t == 3) { map[bx1-1][by1] = bn; }

	}//t1,t3 green
	else {
		bx1 = x; by1 = y; bx2 = x; by2 = y+1;

		while (map[bx1+1][by1] ==0 && bx1 + 1 < 10 && map[bx2+1][by2] ==0 && bx2 + 1 < 10) {
			map[bx1++][by1] = 0;
			map[bx2++][by2] = 0;
			map[bx1][by1] = bn;
			map[bx2][by2] = bn;
		}

	}//t2 green

	
}

void blue(int num,int a) {

	for (int j =a; j-num > 3;j--) {
		for (int i = 0; i < 4;i++) {
			map[i][j] = map[i][j - num];
		}
	}
	
	for (int j = 8; j > 3; j--) {
		for (int i = 0; i < 4; i++) {
			if (map[i][j] !=0 && map[i][j-1]==0) {
				if (i-1>3 && map[i-1][j]==map[i][j]) {//위
					while (map[i+1][j] !=0 && i+1<10) {
						map[i + 1][j] = map[i][j];
						map[i - 1][j] = 0;
					}
				}
				else if (j+1<4 && map[i][j]==map[i][j+1]) {//오
					
				}
				else if (j-1>=0 && map[i][j-1]== map[i][j]) {//왼
				
				}
			}
		}
	}

}

void green(int num,int a) {

	for (int i = a; i - num > 3; i--) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = map[i-num][j];
		}
	}

	for (int i = 8; i > 3; i--) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j] != 0 && map[i-1][j] == 0) {
				
			}
		}
	}

}


bool check() {
	int n = 0;//없어진 칸갯수
	int score = 0;//획득 점수
	int num = 0;//없어진 줄갯수
	int a;//사라진 행or 열 번호

	num = 0;
	for (int j = 4; j < 10;j++) {//blue
		n = 0;
		for (int i = 0; i < 4;i++) {
			if (map[i][j]!=0) {
				n++;
			}
		}
		if (n==4) {
			a = j;
			num++;
			score++;
		}
	}
	if (num>0) { blue(num, a); }

	num = 0;
	for (int i = 4; i < 10; i++) {//green
		n = 0;
		for (int j = 0; j < 4; j++) {
			if (map[i][j] !=0 ) {
				n++;
			}
		}
		if (n == 4) {
			a = i;
			score++;
			num++;
		}
	}

	if (num>0) { green(num, a); }

	if (score > 0) { answer += score; return true; }
	return false;
}




int main() {

	cin >> n;
	for (int i = 0; i < n;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		qq.push({a,b,c});
	}

	while (qq.empty() !=true) {

		int t = qq.front().t;
		int x = qq.front().x;
		int y = qq.front().y;
		qq.pop();
		
		bn++;
		new_block(t,x,y);
		check();
		cout << "================================\n";
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << map[i][j] << " ";
			}cout << "\n";
		}
	}

	return 0;
}