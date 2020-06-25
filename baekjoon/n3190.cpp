#include<iostream>
#include<queue>
using namespace std;

typedef struct s {

	int time;
	char di;

}s;

int n,k,l;
char map[105][105]; //����
queue <s>qq; //�̵����
queue <pair<int, int>> b;
int d = 1; //���¹���
int t = 0; //����ɸ��ð�
int flag = 0; //1�̸� �׳�
int imap[4] = { -1,0,1,0 };
int jmap[4] = {0,1,0,-1};


void move() {
	int hi = b.back().first;
	int hj = b.back().second;
	int bi = b.front().first;
	int bj = b.front().second;

	if (hi+imap[d] <1 || hi+imap[d] >n || hj+jmap[d] <1 || hj+jmap[d] >n || map[hi + imap[d]][hj + jmap[d]] == '*') { 
		flag = 1; //��Ż�ϰų� ������Ƽ� �׳�
		return;
	}
	else if (map[hi + imap[d]][hj + jmap[d]]=='a') {//�������
		map[hi + imap[d]][hj + jmap[d]] = '*';	
		b.push(make_pair(hi + imap[d], hj + jmap[d]));

	}
	else if (map[hi + imap[d]][hj + jmap[d]] == '-') {//��ĭ����
		map[hi + imap[d]][hj + jmap[d]] = '*';
		b.push(make_pair(hi + imap[d], hj + jmap[d]));//�Ӹ��߰�
		map[bi][bj] = '-';
		b.pop();//��������
		

	}
}

void turn(char c) {
	if (c=='L') {
		if (d==0) {
			d = 3;
		}
		else if (d==3) {
			d = 2;
		}
		else if (d==2) {
			d = 1;
		}
		else { d = 0; }
	}
	if (c == 'D') {
		if (d == 0) {
			d = 1;
		}
		else if (d == 3) {
			d = 0;
		}
		else if (d == 2) {
			d = 3;
		}
		else { d = 2; }
	}
}
	
int main() {

	cin >> n >> k ;

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			map[i][j] = '-';
		}
	}
	for (int i = 0; i < k;i++) {
		int a,b;
		cin >> a >> b;
		map[a][b] = 'a';
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int c;
		char d;
		cin >> c >> d;
		qq.push({c,d});
	}
	map[1][1] = '*';
	b.push(make_pair(1, 1));

	while (1) {
		if (qq.empty()!=true) {
			int new_t = qq.front().time;
			char new_d = qq.front().di;
			qq.pop();

			while (t != new_t) {
				move();
				t++;
				if (flag == 1) {
					cout << t;
					return 0;
				}
			}
			turn(new_d);
		}
		else {
			while (1) {
				move();
				t++;
				if (flag == 1) {
					cout << t;
					return 0;
				}
			}
		}
	}



	return 0;
}