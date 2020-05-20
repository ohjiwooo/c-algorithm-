#include<iostream>

using namespace std;

typedef struct s{
	int s=0; //�ӷ�
	int d=0; //����
	int z=0; //ũŰ
	
}s;

int r, c,m;
s map[102][102];
int answer = 0;
s temp[102][102];




void move() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j].d == 1) {//��
				if (i - map[i][j].s > 0) {//�����ȳ���
					if (temp[i - map[i][j].s][j].z < map[i][j].z) { //�̹��ִ� �ְ� ���ų� �� ����
						temp[i - map[i][j].s][j].s = map[i][j].s;
						temp[i - map[i][j].s][j].d = map[i][j].d;
						temp[i - map[i][j].s][j].z = map[i][j].z;
					}
				}
				else if (i - map[i][j].s == 0) {
					map[i][j].d = 2;
					if (temp[0][j].z < map[i][j].z) { //�̹��ִ� �ְ� ���ų� �� ����
						temp[0][j].s = map[i][j].s;
						temp[0][j].d = map[i][j].d;
						temp[0][j].z = map[i][j].z;
					}
				}
				else {//��������
					map[i][j].d = 2;//����ٲ�
					int n = (i + map[i][j].s) % r+2; //�ε��� ���
					if (temp[n][j].z < map[i][j].z) { //�̹��ִ� �ְ� ���ų� �� ����
						temp[n][j].s = map[i][j].s;
						temp[n][j].d = map[i][j].d;
						temp[n][j].z = map[i][j].z;
					}
				}
			}
			else if (map[i][j].d == 2) {//�Ʒ�
				if (i + map[i][j].s <r-1) {//�����ȳ���
					if (temp[i + map[i][j].s][j].z < map[i][j].z) { //�̹��ִ� �ְ� ���ų� �� ����
						temp[i + map[i][j].s][j].s = map[i][j].s;
						temp[i + map[i][j].s][j].d = map[i][j].d;
						temp[i + map[i][j].s][j].z = map[i][j].z;
					}
				}
				else if (i - map[i][j].s == r-1) { //������������
					map[i][j].d = 1;
					if (temp[r-1][j].z < map[i][j].z) { //�̹��ִ� �ְ� ���ų� �� ����
						temp[r-1][j].s = map[i][j].s;
						temp[r-1][j].d = map[i][j].d;
						temp[r-1][j].z = map[i][j].z;
					}
				}
				else {//��������
					map[i][j].d = 1;//����ٲ�
					int n =r- ((i + map[i][j].s) % r+2); //�ε��� ���
					if (temp[n][j].z < map[i][j].z) { //�̹��ִ� �ְ� ���ų� �� ����
						temp[n][j].s = map[i][j].s;
						temp[n][j].d = map[i][j].d;
						temp[n][j].z = map[i][j].z;
					}
				}
			}
			else if (map[i][j].d == 3) {//������
				if (j + map[i][j].s < c-1) {//�����ȳ���
					if (temp[i][j + map[i][j].s].z < map[i][j].z) { //�̹��ִ� �ְ� ���ų� �� ����
						temp[i][j + map[i][j].s].s = map[i][j].s;
						temp[i][j + map[i][j].s].d = map[i][j].d;
						temp[i][j + map[i][j].s].z = map[i][j].z;
					}
				}
				else if (j + map[i][j].s == c-1) {
					map[i][j].d = 4;
					if (temp[0][c-1].z < map[i][j].z) { //�̹��ִ� �ְ� ���ų� �� ����
						temp[0][c-1].s = map[i][j].s;
						temp[0][c-1].d = map[i][j].d;
						temp[0][c-1].z = map[i][j].z;
					}
				}
				else {//��������
					map[i][j].d = 4;//����ٲ�
					int n = c - ((j + map[i][j].s) % c+2); //�ε��� ���
					if (temp[n][j].z < map[i][j].z) { //�̹��ִ� �ְ� ���ų� �� ����
						temp[n][j].s = map[i][j].s;
						temp[n][j].d = map[i][j].d;
						temp[n][j].z = map[i][j].z;
					}
				}
			}
			else if (map[i][j].d == 4) {//����
				if (j - map[i][j].s > 0) {//�����ȳ���
					if (temp[i][j - map[i][j].s].z < map[i][j].z) { //�̹��ִ� �ְ� ���ų� �� ����
						temp[i][j - map[i][j].s].s = map[i][j].s;
						temp[i][j - map[i][j].s].d = map[i][j].d;
						temp[i][j - map[i][j].s].z = map[i][j].z;
					}
				}
				else if (i - map[i][j].s == 0) {
					map[i][j].d = 3;
					if (temp[i][0].z < map[i][j].z) { //�̹��ִ� �ְ� ���ų� �� ����
						temp[i][0].s = map[i][j].s;
						temp[i][0].d = map[i][j].d;
						temp[i][0].z = map[i][j].z;
					}
				}
				else {//��������
					map[i][j].d = 3;//����ٲ�
					int n = (i + map[i][j].s) % c+2; //�ε��� ���
					if (temp[i][n].z < map[i][j].z) { //�̹��ִ� �ְ� ���ų� �� ����
						temp[i][n].s = map[i][j].s;
						temp[i][n].d = map[i][j].d;
						temp[i][n].z = map[i][j].z;
					}
				}
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

	cin >> r >> c >> m;

	int a, b;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a;
			cin >> b;
			temp[i][j].z = 0;
			if (i == a && j == b) {
				cin >> map[i][j].d;
				cin >> map[i][j].s;
				cin >> map[i][j].z;

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