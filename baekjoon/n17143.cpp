#include<iostream>

using namespace std;

typedef struct s{
	int s=0; //�ӷ�
	int d=0; //����
	int z=0; //ũŰ
	int c = 0;//�̵���
}s;

int r, c,m;
s map[102][102];
int mm[102][102];
int answer = 0;
//����(1 - ��, 2 - �Ʒ�, 3 - ��, 4 - ��)

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
	}//��ġ(0,1) �ӷ� ����(1-��,2-�Ʒ�,3-��,4-��) ũ��

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