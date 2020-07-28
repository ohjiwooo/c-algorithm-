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
void s_blue();
void s_green();

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
	}//������ ĭ��ŭ ����
	int k;
	for (int j = 8; j > 3; j--) {//�� ����� �ִ¸�ŭ ����
		for (int i = 0; i < 4; i++) {
			if (map[i][j] !=0 && map[i][j+1]==0) {//���� ����� ���� �������,������map[i][j]
				if (map[i][j-1]==map[i][j]) {//���� ����� ���ʰ� �������� ��Ʈ -2
					k = j;
					while (map[i][k+1] ==0 && k+1<10) {
						map[i][k+1] = map[i][k];
						map[i][k-1] = 0;
						k++;
					}
				}
				else if (i+1<4 && map[i][j]==map[i+1][j] && map[i+1][j+1]==0) {//���� ����� �Ʒ���ϰ� �������� ��Ʈ,�Ʒ������ ���� �������-3
					k = j;
					while (map[i][k+1] == 0 && map[i+1][k+1]==0 &&k+1<10) {
						map[i][k+1] = map[i][k]; map[i + 1][k+1] = map[i][k];
						map[i][k] = 0; map[i + 1][k] = 0;
						k++;
					}
				}
				else if(map[i][j] != map[i+1][j] && ((map[i][j]!= map[i-1][j] && i-1>=0) || i-1<0) ){//���� ����� ���� �������-1
					k = j;
					while (map[i][k + 1] == 0 && k + 1 < 10) {
						map[i][k + 1] = map[i][k];
						map[i][k] = 0;
						k++;
					}
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
	int k = 0;
	for (int i = 8; i > 3; i--) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j] != 0 && map[i+1][j] == 0) {//�������� ���� �������,���� map[i][j]
				if(map[i][j]==map[i][j+1] && map[i+1][j+1] ==0) {//�������� �����ʰ� �������� ��Ʈ, �������� ���� ������� -2
					k = i;
					while (map[k+1][j]==0 && map[k+1][j+1] ==0 && k+1<10) {
						map[k + 1][j] = map[k][j]; map[k + 1][j + 1] = map[k][j];
						map[k][j] = 0; map[k][j + 1] = 0;
						k++;
					}
				}
				else if (map[i][j]==map[i-1][j]) {//�����ϰ� ���Ǻ���� ��Ʈ -3
					k = i;
					while (map[k+1][j]==0 && k+1<10) {
						map[k + 1][j] = map[k][j];
						map[k - 1][j] = 0;
						k++;
					}
				}
				else if(map[i][j] != map[i][j+1] && ((map[i][j]!=map[i][j-1] && j-1>=0)|| j-1<0)){//�������� ���� ������� -1 ����
					k = i;
					while (map[k+1][j]==0 &&k+1<10) {
						map[k + 1][j] = map[k][j];
						map[k][j] = 0;
						k++;
					}
				}
			}
		}
	}
}


bool check() {
	int n = 0;//������ ĭ����
	int score = 0;//ȹ�� ����
	int num = 0;//������ �ٰ���
	int a;//����� ��or �� ��ȣ

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
	if (map[0][5] != 0 || map[1][5] != 0 || map[2][5] != 0 || map[3][5] != 0) { s_blue(); }
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
	if (map[5][0] != 0 || map[5][1] != 0 || map[5][2] != 0 || map[5][3] != 0) { s_green(); }
	if (score > 0) { answer += score; return true; }
	return false;
}

void s_blue() {
	int n = 9;
	for (int j = 4; j < 6; j++) { //blue
		for (int i = 0; i < 4; i++) {
			if (map[i][j] != 0) {
				map[0][n] = 0;
				map[1][n] = 0;
				map[2][n] = 0;
				map[3][n--] = 0; 
				break;
			}
		}
	}
	blue(0,0);
}

void s_green() {
	int n = 9;
	for (int i = 4; i < 6; i++) { 
		for (int j = 0; j < 4; j++) {
			if (map[i][j] != 0) {
				map[n][0] = 0;
				map[n][1] = 0;
				map[n][2] = 0;
				map[n--][3] = 0;
				break;
			}
		}
	}
	green(0, 0);
}
int main() {

	cin >> n;
	for (int i = 0; i < n;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		qq.push({a,b,c});
	}
	bool c;
	while (qq.empty() !=true) {

		int t = qq.front().t;
		int x = qq.front().x;
		int y = qq.front().y;
		qq.pop();
		
		bn++;
		new_block(t,x,y);
		c = check();
		while (c==true) {
			c = check();
		}
	}
		
		int answer2 = 0;
		for (int i = 0; i < 4;i++) {
			for (int j = 4; j < 10;j++) {
				if (map[i][j] != 0) { answer2++; }
			}
		}
		for (int i = 4; i < 10; i++) {
			for (int j = 0; j < 4; j++) {
				if (map[i][j] != 0) { answer2++; }
			}
		}
		cout << answer<<"\n";
		cout << answer2;
	return 0;
}