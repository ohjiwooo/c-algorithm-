#include<iostream>
#include<queue>
using namespace std;

typedef struct s {

	int time;
	char di;

}s;

int n,k,l;
char map[105][105]; //지도
queue <s>qq; //이동경로
queue <pair<int, int>> b;
int d = 1; //보는방향
int t = 0; //현재걸린시간
int flag = 0; //1이면 겜끝
int imap[4] = { -1,0,1,0 };
int jmap[4] = {0,1,0,-1};


void move() {
	int hi = b.back().first;
	int hj = b.back().second;
	int bi = b.front().first;
	int bj = b.front().second;

	if (hi+imap[d] <1 || hi+imap[d] >n || hj+jmap[d] <1 || hj+jmap[d] >n || map[hi + imap[d]][hj + jmap[d]] == '*') { 
		flag = 1; //이탈하거나 몸에닿아서 겜끝
		return;
	}
	else if (map[hi + imap[d]][hj + jmap[d]]=='a') {//사과만남
		map[hi + imap[d]][hj + jmap[d]] = '*';	
		b.push(make_pair(hi + imap[d], hj + jmap[d]));

	}
	else if (map[hi + imap[d]][hj + jmap[d]] == '-') {//빈칸만남
		map[hi + imap[d]][hj + jmap[d]] = '*';
		b.push(make_pair(hi + imap[d], hj + jmap[d]));//머리추가
		map[bi][bj] = '-';
		b.pop();//꼬리삭제
		

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